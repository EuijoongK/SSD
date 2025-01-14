#include "../../include/model/ssd.h"

float* label[] = {
    "BACKGROUND",           // 0
    "AEROPLANE",            // 1
    "BICYCLE",              // 2
    "BIRD",                 // 3
    "BOAT",                 // 4
    "BOTTLE",               // 5
    "BUS",                  // 6
    "CAR",                  // 7
    "CAT",                  // 8
    "CHAIR",                // 9
    "COW",                  // 10
    "DININGTABLE",          // 11
    "DOG",                  // 12
    "HORSE",                // 13
    "MOTORBIKE",            // 14
    "PERSON",               // 15
    "POTTEDPLANT",          // 16
    "SHEEP",                // 17
    "SOFA",                 // 18
    "TRAIN",                // 19
    "TVMONITOR"             // 20
};

void rescale_tensor(struct Tensor* input, struct Tensor* scale_factor)
{
    // input : 38 x 38 x 512
    // scale :  1 x  1 x 512
    int row = input -> row;
    int col = input -> col;
    int channel = input -> channel;

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            float temp = 0.0;
            float sum = 0.0;
            float norm = 0.0;

            for(int k = 0; k < channel; ++k){
                temp = *(input -> data + i * col * channel + j * channel + k);
                sum += (temp * temp);
            }
            norm = sqrt(sum);
            for(int k = 0; k < channel; ++k){
                temp = *(input -> data + i * col * channel + j * channel + k);
                *(input -> data + i * col * channel + j * channel + k) = *(scale_factor -> data + k) * temp / norm;
            }
        }
    }
}

void create_prior_box(float prior[][4])
{
    int fmap_dims[NUM_FMAPS] = {38, 19, 10, 5, 3, 1};
    float obj_scales[NUM_FMAPS] = {0.1, 0.2, 0.375, 0.55, 0.725, 0.9};
    int num_ratio[] = {3, 5, 5, 5, 3, 3};

    float aspect_ratios[NUM_FMAPS][5] = {
            {1.0, 2.0, 0.5},                 // conv4_3
            {1.0, 2.0, 3.0, 0.5, 0.333},     // conv7
            {1.0, 2.0, 3.0, 0.5, 0.333},     // conv8_2
            {1.0, 2.0, 3.0, 0.5, 0.333},     // conv9_2
            {1.0, 2.0, 0.5},                 // conv10_2
            {1.0, 2.0, 0.5}                  // conv11_2
    };
    
    int count = 0;
    for(int i = 0; i < NUM_FMAPS; ++i){
        int dim = fmap_dims[i];
        float scale = obj_scales[i];
        for(int j = 0; j < dim; ++j){
            for(int k = 0; k < dim; ++k){
                float cx = (k + 0.5) / dim;
                float cy = (j + 0.5) / dim;

                for(int r = 0; r < num_ratio[i]; ++r){
                    float ratio = aspect_ratios[i][r];
                    float w = scale * sqrtf(ratio);
                    float h = scale / sqrtf(ratio);

                    prior[count][0] = cx;
                    prior[count][1] = cy;
                    prior[count][2] = w;
                    prior[count][3] = h;
                    count++;

                    if(ratio == 1.0){
                        float additional_scale;
                        if(i < NUM_FMAPS - 1){
                            additional_scale = sqrtf(scale * obj_scales[i + 1]);
                        }else{
                            additional_scale = 1.0;
                        }
                        // prior[count++] = (struct PriorBox){cx, cy, additional_scale, additional_scale};
                        prior[count][0] = cx;
                        prior[count][1] = cy;
                        prior[count][2] = additional_scale;
                        prior[count][3] = additional_scale;
                        count++;
                    }
                }
            }
        }
    }
}

void SSD_init(struct SSD* ssd)
{   
    ssd -> vgg = (struct VGGBase*)malloc(sizeof(struct VGGBase));
    ssd -> aux = (struct Auxiliary*)malloc(sizeof(struct Auxiliary));
    ssd -> pred = (struct Predict*)malloc(sizeof(struct Predict));
    ssd -> rescale_factor = (struct Tensor*)malloc(sizeof(struct Tensor));

    vgg_init(ssd -> vgg);
    auxiliary_init(ssd -> aux);
    pred_init(ssd -> pred);

    // Rescale factor
    (ssd -> rescale_factor) -> row = 1;
    (ssd -> rescale_factor) -> col = 1;
    (ssd -> rescale_factor) -> channel = 512;
    (ssd -> rescale_factor) -> data = (float*)malloc(sizeof(float) * 1 * 1 * 512);
    import_tensor_float("./param/rescale_factors.bin", ssd -> rescale_factor);
}

void SSD_load_param(struct SSD* ssd)
{
    vgg_load_param(ssd -> vgg);
    auxiliary_load_param(ssd -> aux);
    pred_load_param(ssd -> pred);
}

void SSD_destroy(struct SSD* ssd)
{
    vgg_destroy(ssd -> vgg);
    auxiliary_destroy(ssd -> aux);
    pred_destroy(ssd -> pred);
    destroy_tensor(ssd -> rescale_factor);

    free(ssd -> vgg);
    free(ssd -> aux);
    free(ssd -> pred);
}

struct Tensor** SSD_run(struct SSD* ssd, struct Tensor* input)
{
    struct Tensor** output_vgg = vgg_run(ssd -> vgg, input);
    struct Tensor* conv4_3  = output_vgg[0];

    // need L2 norm
    rescale_tensor(conv4_3, ssd -> rescale_factor);

    struct Tensor* conv7    = output_vgg[1];

    struct Tensor** output_aux = auxilairy_run(ssd -> aux, conv7);
    struct Tensor* conv8_2 = output_aux[0];
    struct Tensor* conv9_2 = output_aux[1];
    struct Tensor* conv10_2 = output_aux[2];
    struct Tensor* conv11_2 = output_aux[3];

    struct Tensor* pred_input[6];
    pred_input[0] = conv4_3;
    pred_input[1] = conv7;
    pred_input[2] = conv8_2;
    pred_input[3] = conv9_2;
    pred_input[4] = conv10_2;
    pred_input[5] = conv11_2;

    struct Tensor** output_pred = predict_run(ssd -> pred, pred_input);

    destroy_tensor(output_vgg[0]);                      // free conv4_3
    destroy_tensor(output_vgg[1]);                      // free conv7
    free(output_vgg);

    destroy_tensor(output_aux[0]);                      // free conv8_2
    destroy_tensor(output_aux[1]);                      // free conv9_2
    destroy_tensor(output_aux[2]);                      // free conv10_2
    destroy_tensor(output_aux[3]);                      // free conv11_2
    free(output_aux);

    return output_pred;
}

void gcxgcy_to_cxcy(float* gcxgcy, float priors_cxcy[][4], float output[][4], int n_priors)
{
    for (int i = 0; i < n_priors; i++) {
        output[i][0] = *(gcxgcy + 4 * i) * (priors_cxcy[i][2] / 10.0) + priors_cxcy[i][0];
        output[i][1] = *(gcxgcy + 4 * i + 1) * (priors_cxcy[i][3] / 10.0) + priors_cxcy[i][1];

        output[i][2] = exp(*(gcxgcy + 4 * i + 2) / 5.0) * priors_cxcy[i][2];
        output[i][3] = exp(*(gcxgcy + 4 * i + 3) / 5.0) * priors_cxcy[i][3];
    }
}

void cxcy_to_xy(float cxcy[][4], float output[][4], int n_boxes)
{
    for (int i = 0; i < n_boxes; i++) {
        output[i][0] = cxcy[i][0] - (cxcy[i][2] / 2.0);  // x_min = c_x - w / 2
        output[i][1] = cxcy[i][1] - (cxcy[i][3] / 2.0);  // y_min = c_y - h / 2
        output[i][2] = cxcy[i][0] + (cxcy[i][2] / 2.0);  // x_max = c_x + w / 2
        output[i][3] = cxcy[i][1] + (cxcy[i][3] / 2.0);  // y_max = c_y + h / 2
    }
}

int compare(const float* value_array, const void* a, const void* b)
{
    int index1 = *(int*)a;
    int index2 = *(int*)b;

    if(value_array[index1] < value_array[index2]){
        return -1;
    }else if(value_array[index1] > value_array[index2]){
        return 1;
    }else{
        return 0;
    }
}

void nms(float* score, int* suppress, int num_prior, int num_class, float min_score, int top_k)
{
    int* index = (int*)malloc(sizeof(int) * num_prior);
    for(int i = 0; i < num_prior; ++i){
        *(index + i) = i;
    }
    for(int i = 0; i < num_class; ++i){
        int num_above_min = 0;
        for(int j = 0; j < num_prior; ++j){
            if(*(score + j * num_class + i) > min_score){
                num_above_min++;
            }
        }
        if(num_above_min == 0){
            continue;
        }
        
    }
    free(index);
}