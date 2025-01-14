#include "../include/model/ssd.h"
// #include <opencv4/opencv2/core/core_c.h>

void save_file(FILE* fp, char* path, float* data, int size)
{
    fp = fopen(path, "wb");
    fwrite(data, sizeof(float), size, fp);
    fclose(fp);
}

int main(){
    FILE* fp;
    // load input image and normalize image
    printf("Load input data...\n");
    char* input_path = "./data/2007_000480.bin";
    int in_row = 300;
    int in_col = 300;
    int in_channel = 3;
    struct Tensor* input = image_from_bin(input_path, in_row, in_col, in_channel);               // verified 250112
    normalize_img(input -> data, input -> row, input -> col);                                    // verified 250112

    // model run
    struct SSD ssd;
    SSD_init(&ssd);
    SSD_load_param(&ssd);
    printf("Run SSD...\n");
    struct Tensor** output = SSD_run(&ssd, input);
    struct Tensor* locs = output[0];
    struct Tensor* class_score = output[1];
    float* locs_data = locs -> data;
    float* score_data = class_score -> data;

    int num_class = 21;
    int num_prior = 8732;

    // softmax scores
    for(int i = 0; i < num_prior; ++i){
        float* current_prior = score_data + i * num_class;
        float sum = 0.0;
        float temp = 0.0;
        for(int j = 0; j < num_class; ++j){
            temp = *(current_prior + j);
            sum += expf(temp);
        }
        for(int j = 0; j < num_class; ++j){
            temp = *(current_prior + j);
            *(current_prior + j) = expf(temp) / sum;
        }
    }                                                                                           // verified 250113

    // decode object coordinates from locs
    float prior[num_prior][4];
    float cxcy[num_prior][4];
    float xy[num_prior][4];
    create_prior_box(prior);                                                                    // verified 250113
    gcxgcy_to_cxcy(locs_data, prior, cxcy, num_prior);                                          // verified 250113
    cxcy_to_xy(cxcy, xy, num_prior);                                                            // verified 250113

    float min_score = 0.2;
    int top_k = 3;

    int suppress[num_prior][num_class];
    nms(score_data, suppress, num_prior, num_class, min_score, top_k);

    destroy_tensor(output[0]);
    destroy_tensor(output[1]);
    free(output);
    SSD_destroy(&ssd);
}