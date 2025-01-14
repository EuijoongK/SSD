#include "../../include/model/predict.h"

void pred_init(struct Predict* pred)
{
    for(int i = 0; i < N_BOX_CONV4_3 * 4; ++i){
        (pred -> loc_conv4_3_weight)[i].row = 3;
        (pred -> loc_conv4_3_weight)[i].col = 3;
        (pred -> loc_conv4_3_weight)[i].channel = 512;
        (pred -> loc_conv4_3_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (pred -> loc_conv4_3_bias)[i].row = 1;
        (pred -> loc_conv4_3_bias)[i].col = 1;
        (pred -> loc_conv4_3_bias)[i].channel = 1;
        (pred -> loc_conv4_3_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV7 * 4; ++i){
        (pred -> loc_conv7_weight)[i].row = 3;
        (pred -> loc_conv7_weight)[i].col = 3;
        (pred -> loc_conv7_weight)[i].channel = 1024;
        (pred -> loc_conv7_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 1024);

        (pred -> loc_conv7_bias)[i].row = 1;
        (pred -> loc_conv7_bias)[i].col = 1;
        (pred -> loc_conv7_bias)[i].channel = 1;
        (pred -> loc_conv7_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV8_2 * 4; ++i){
        (pred -> loc_conv8_2_weight)[i].row = 3;
        (pred -> loc_conv8_2_weight)[i].col = 3;
        (pred -> loc_conv8_2_weight)[i].channel = 512;
        (pred -> loc_conv8_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (pred -> loc_conv8_2_bias)[i].row = 1;
        (pred -> loc_conv8_2_bias)[i].col = 1;
        (pred -> loc_conv8_2_bias)[i].channel = 1;
        (pred -> loc_conv8_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV9_2 * 4; ++i){
        (pred -> loc_conv9_2_weight)[i].row = 3;
        (pred -> loc_conv9_2_weight)[i].col = 3;
        (pred -> loc_conv9_2_weight)[i].channel = 256;
        (pred -> loc_conv9_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (pred -> loc_conv9_2_bias)[i].row = 1;
        (pred -> loc_conv9_2_bias)[i].col = 1;
        (pred -> loc_conv9_2_bias)[i].channel = 1;
        (pred -> loc_conv9_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV10_2 * 4; ++i){
        (pred -> loc_conv10_2_weight)[i].row = 3;
        (pred -> loc_conv10_2_weight)[i].col = 3;
        (pred -> loc_conv10_2_weight)[i].channel = 256;
        (pred -> loc_conv10_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (pred -> loc_conv10_2_bias)[i].row = 1;
        (pred -> loc_conv10_2_bias)[i].col = 1;
        (pred -> loc_conv10_2_bias)[i].channel = 1;
        (pred -> loc_conv10_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV11_2 * 4; ++i){
        (pred -> loc_conv11_2_weight)[i].row = 3;
        (pred -> loc_conv11_2_weight)[i].col = 3;
        (pred -> loc_conv11_2_weight)[i].channel = 256;
        (pred -> loc_conv11_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (pred -> loc_conv11_2_bias)[i].row = 1;
        (pred -> loc_conv11_2_bias)[i].col = 1;
        (pred -> loc_conv11_2_bias)[i].channel = 1;
        (pred -> loc_conv11_2_bias)[i].data = (float*)malloc(sizeof(float));
    }



    for(int i = 0; i < N_BOX_CONV4_3 * N_CLASS; ++i){
        (pred -> cl_conv4_3_weight)[i].row = 3;
        (pred -> cl_conv4_3_weight)[i].col = 3;
        (pred -> cl_conv4_3_weight)[i].channel = 512;
        (pred -> cl_conv4_3_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (pred -> cl_conv4_3_bias)[i].row = 1;
        (pred -> cl_conv4_3_bias)[i].col = 1;
        (pred -> cl_conv4_3_bias)[i].channel = 1;
        (pred -> cl_conv4_3_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV7 * N_CLASS; ++i){
        (pred -> cl_conv7_weight)[i].row = 3;
        (pred -> cl_conv7_weight)[i].col = 3;
        (pred -> cl_conv7_weight)[i].channel = 1024;
        (pred -> cl_conv7_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 1024);

        (pred -> cl_conv7_bias)[i].row = 1;
        (pred -> cl_conv7_bias)[i].col = 1;
        (pred -> cl_conv7_bias)[i].channel = 1;
        (pred -> cl_conv7_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV8_2 * N_CLASS; ++i){
        (pred -> cl_conv8_2_weight)[i].row = 3;
        (pred -> cl_conv8_2_weight)[i].col = 3;
        (pred -> cl_conv8_2_weight)[i].channel = 512;
        (pred -> cl_conv8_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (pred -> cl_conv8_2_bias)[i].row = 1;
        (pred -> cl_conv8_2_bias)[i].col = 1;
        (pred -> cl_conv8_2_bias)[i].channel = 1;
        (pred -> cl_conv8_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV9_2 * N_CLASS; ++i){
        (pred -> cl_conv9_2_weight)[i].row = 3;
        (pred -> cl_conv9_2_weight)[i].col = 3;
        (pred -> cl_conv9_2_weight)[i].channel = 256;
        (pred -> cl_conv9_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (pred -> cl_conv9_2_bias)[i].row = 1;
        (pred -> cl_conv9_2_bias)[i].col = 1;
        (pred -> cl_conv9_2_bias)[i].channel = 1;
        (pred -> cl_conv9_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV10_2 * N_CLASS; ++i){
        (pred -> cl_conv10_2_weight)[i].row = 3;
        (pred -> cl_conv10_2_weight)[i].col = 3;
        (pred -> cl_conv10_2_weight)[i].channel = 256;
        (pred -> cl_conv10_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (pred -> cl_conv10_2_bias)[i].row = 1;
        (pred -> cl_conv10_2_bias)[i].col = 1;
        (pred -> cl_conv10_2_bias)[i].channel = 1;
        (pred -> cl_conv10_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < N_BOX_CONV11_2 * N_CLASS; ++i){
        (pred -> cl_conv11_2_weight)[i].row = 3;
        (pred -> cl_conv11_2_weight)[i].col = 3;
        (pred -> cl_conv11_2_weight)[i].channel = 256;
        (pred -> cl_conv11_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (pred -> cl_conv11_2_bias)[i].row = 1;
        (pred -> cl_conv11_2_bias)[i].col = 1;
        (pred -> cl_conv11_2_bias)[i].channel = 1;
        (pred -> cl_conv11_2_bias)[i].data = (float*)malloc(sizeof(float));
    }
}

void pred_load_param(struct Predict* pred)
{
    char* loc_conv4_3_weight_path = "./param/pred_convs_loc_conv4_3_weight.bin";
    char* loc_conv4_3_bias_path = "./param/pred_convs_loc_conv4_3_bias.bin";
    char* loc_conv7_weight_path = "./param/pred_convs_loc_conv7_weight.bin";
    char* loc_conv7_bias_path = "./param/pred_convs_loc_conv7_bias.bin";
    char* loc_conv8_2_weight_path = "./param/pred_convs_loc_conv8_2_weight.bin";
    char* loc_conv8_2_bias_path = "./param/pred_convs_loc_conv8_2_bias.bin";
    char* loc_conv9_2_weight_path = "./param/pred_convs_loc_conv9_2_weight.bin";
    char* loc_conv9_2_bias_path = "./param/pred_convs_loc_conv9_2_bias.bin";
    char* loc_conv10_2_weight_path = "./param/pred_convs_loc_conv10_2_weight.bin";
    char* loc_conv10_2_bias_path = "./param/pred_convs_loc_conv10_2_bias.bin";
    char* loc_conv11_2_weight_path = "./param/pred_convs_loc_conv11_2_weight.bin";
    char* loc_conv11_2_bias_path = "./param/pred_convs_loc_conv11_2_bias.bin";

    char* cl_conv4_3_weight_path = "./param/pred_convs_cl_conv4_3_weight.bin";
    char* cl_conv4_3_bias_path = "./param/pred_convs_cl_conv4_3_bias.bin";
    char* cl_conv7_weight_path = "./param/pred_convs_cl_conv7_weight.bin";
    char* cl_conv7_bias_path = "./param/pred_convs_cl_conv7_bias.bin";
    char* cl_conv8_2_weight_path = "./param/pred_convs_cl_conv8_2_weight.bin";
    char* cl_conv8_2_bias_path = "./param/pred_convs_cl_conv8_2_bias.bin";
    char* cl_conv9_2_weight_path = "./param/pred_convs_cl_conv9_2_weight.bin";
    char* cl_conv9_2_bias_path = "./param/pred_convs_cl_conv9_2_bias.bin";
    char* cl_conv10_2_weight_path = "./param/pred_convs_cl_conv10_2_weight.bin";
    char* cl_conv10_2_bias_path = "./param/pred_convs_cl_conv10_2_bias.bin";
    char* cl_conv11_2_weight_path = "./param/pred_convs_cl_conv11_2_weight.bin";
    char* cl_conv11_2_bias_path = "./param/pred_convs_cl_conv11_2_bias.bin";


    import_conv_weight(loc_conv4_3_weight_path, pred -> loc_conv4_3_weight, 3, 3, 512, N_BOX_CONV4_3 * 4);
    import_conv_bias(loc_conv4_3_bias_path, pred -> loc_conv4_3_bias, 1, 1, 1, N_BOX_CONV4_3 * 4);

    import_conv_weight(loc_conv7_weight_path, pred -> loc_conv7_weight, 3, 3, 1024, N_BOX_CONV7 * 4);
    import_conv_bias(loc_conv7_bias_path, pred -> loc_conv7_bias, 1, 1, 1, N_BOX_CONV7 * 4);

    import_conv_weight(loc_conv8_2_weight_path, pred -> loc_conv8_2_weight, 3, 3, 512, N_BOX_CONV8_2 * 4);
    import_conv_bias(loc_conv8_2_bias_path, pred -> loc_conv8_2_bias, 1, 1, 1, N_BOX_CONV8_2 * 4);

    import_conv_weight(loc_conv9_2_weight_path, pred -> loc_conv9_2_weight, 3, 3, 256, N_BOX_CONV9_2 * 4);
    import_conv_bias(loc_conv9_2_bias_path, pred -> loc_conv9_2_bias, 1, 1, 1, N_BOX_CONV9_2 * 4);

    import_conv_weight(loc_conv10_2_weight_path, pred -> loc_conv10_2_weight, 3, 3, 256, N_BOX_CONV10_2 * 4);
    import_conv_bias(loc_conv10_2_bias_path, pred -> loc_conv10_2_bias, 1, 1, 1, N_BOX_CONV10_2 * 4);

    import_conv_weight(loc_conv11_2_weight_path, pred -> loc_conv11_2_weight, 3, 3, 256, N_BOX_CONV11_2 * 4);
    import_conv_bias(loc_conv11_2_bias_path, pred -> loc_conv11_2_bias, 1, 1, 1, N_BOX_CONV11_2 * 4);


    import_conv_weight(cl_conv4_3_weight_path, pred -> cl_conv4_3_weight, 3, 3, 512, N_BOX_CONV4_3 * N_CLASS);
    import_conv_bias(cl_conv4_3_bias_path, pred -> cl_conv4_3_bias, 1, 1, 1, N_BOX_CONV4_3 * N_CLASS);

    import_conv_weight(cl_conv7_weight_path, pred -> cl_conv7_weight, 3, 3, 1024, N_BOX_CONV7 * N_CLASS);
    import_conv_bias(cl_conv7_bias_path, pred -> cl_conv7_bias, 1, 1, 1, N_BOX_CONV7 * N_CLASS);

    import_conv_weight(cl_conv8_2_weight_path, pred -> cl_conv8_2_weight, 3, 3, 512, N_BOX_CONV8_2 * N_CLASS);
    import_conv_bias(cl_conv8_2_bias_path, pred -> cl_conv8_2_bias, 1, 1, 1, N_BOX_CONV8_2 * N_CLASS);

    import_conv_weight(cl_conv9_2_weight_path, pred -> cl_conv9_2_weight, 3, 3, 256, N_BOX_CONV9_2 * N_CLASS);
    import_conv_bias(cl_conv9_2_bias_path, pred -> cl_conv9_2_bias, 1, 1, 1, N_BOX_CONV9_2 * N_CLASS);

    import_conv_weight(cl_conv10_2_weight_path, pred -> cl_conv10_2_weight, 3, 3, 256, N_BOX_CONV10_2 * N_CLASS);
    import_conv_bias(cl_conv10_2_bias_path, pred -> cl_conv10_2_bias, 1, 1, 1, N_BOX_CONV10_2 * N_CLASS);

    import_conv_weight(cl_conv11_2_weight_path, pred -> cl_conv11_2_weight, 3, 3, 256, N_BOX_CONV11_2 * N_CLASS);
    import_conv_bias(cl_conv11_2_bias_path, pred -> cl_conv11_2_bias, 1, 1, 1, N_BOX_CONV11_2 * N_CLASS);
}

void pred_destroy(struct Predict* pred)
{
    for(int i = 0; i < N_BOX_CONV4_3 * 4; ++i){
        free(pred -> loc_conv4_3_weight[i].data);
        free(pred -> loc_conv4_3_bias[i].data);
        pred -> loc_conv4_3_weight[i].data = NULL;
        pred -> loc_conv4_3_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV7 * 4; ++i){
        free(pred -> loc_conv7_weight[i].data);
        free(pred -> loc_conv7_bias[i].data);
        pred -> loc_conv7_weight[i].data = NULL;
        pred -> loc_conv7_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV8_2 * 4; ++i){
        free(pred -> loc_conv8_2_weight[i].data);
        free(pred -> loc_conv8_2_bias[i].data);
        pred -> loc_conv8_2_weight[i].data = NULL;
        pred -> loc_conv8_2_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV9_2 * 4; ++i){
        free(pred -> loc_conv9_2_weight[i].data);
        free(pred -> loc_conv9_2_bias[i].data);
        pred -> loc_conv9_2_weight[i].data = NULL;
        pred -> loc_conv9_2_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV10_2 * 4; ++i){
        free(pred -> loc_conv10_2_weight[i].data);
        free(pred -> loc_conv10_2_bias[i].data);
        pred -> loc_conv10_2_weight[i].data = NULL;
        pred -> loc_conv10_2_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV11_2 * 4; ++i){
        free(pred -> loc_conv11_2_weight[i].data);
        free(pred -> loc_conv11_2_bias[i].data);
        pred -> loc_conv11_2_weight[i].data = NULL;
        pred -> loc_conv11_2_bias[i].data = NULL;
    }


    for(int i = 0; i < N_BOX_CONV4_3 * N_CLASS; ++i){
        free(pred -> cl_conv4_3_weight[i].data);
        free(pred -> cl_conv4_3_bias[i].data);
        pred -> cl_conv4_3_weight[i].data = NULL;
        pred -> cl_conv4_3_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV7 * N_CLASS; ++i){
        free(pred -> cl_conv7_weight[i].data);
        free(pred -> cl_conv7_bias[i].data);
        pred -> cl_conv7_weight[i].data = NULL;
        pred -> cl_conv7_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV8_2 * N_CLASS; ++i){
        free(pred -> cl_conv8_2_weight[i].data);
        free(pred -> cl_conv8_2_bias[i].data);
        pred -> cl_conv8_2_weight[i].data = NULL;
        pred -> cl_conv8_2_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV9_2 * N_CLASS; ++i){
        free(pred -> cl_conv9_2_weight[i].data);
        free(pred -> cl_conv9_2_bias[i].data);
        pred -> cl_conv9_2_weight[i].data = NULL;
        pred -> cl_conv9_2_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV10_2 * N_CLASS; ++i){
        free(pred -> cl_conv10_2_weight[i].data);
        free(pred -> cl_conv10_2_bias[i].data);
        pred -> cl_conv10_2_weight[i].data = NULL;
        pred -> cl_conv10_2_bias[i].data = NULL;
    }

    for(int i = 0; i < N_BOX_CONV11_2 * N_CLASS; ++i){
        free(pred -> cl_conv11_2_weight[i].data);
        free(pred -> cl_conv11_2_bias[i].data);
        pred -> cl_conv11_2_weight[i].data = NULL;
        pred -> cl_conv11_2_bias[i].data = NULL;
    }
}

struct Tensor** predict_run(struct Predict* predict, struct Tensor** input)
{
    struct Tensor* conv4_3      = input[0];
    struct Tensor* conv7        = input[1];
    struct Tensor* conv8_2      = input[2];
    struct Tensor* conv9_2      = input[3];
    struct Tensor* conv10_2     = input[4];
    struct Tensor* conv11_2     = input[5];

    struct Tensor* l_conv4_3    = convolution(conv4_3, predict -> loc_conv4_3_weight, predict -> loc_conv4_3_bias, N_BOX_CONV4_3 * 4, 1, 1, 1, 1, 0);
    struct Tensor* l_conv7      = convolution(conv7, predict -> loc_conv7_weight, predict -> loc_conv7_bias, N_BOX_CONV7 * 4, 1, 1, 1, 1, 0);
    struct Tensor* l_conv8_2    = convolution(conv8_2, predict -> loc_conv8_2_weight, predict -> loc_conv8_2_bias, N_BOX_CONV8_2 * 4, 1, 1, 1, 1, 0);
    struct Tensor* l_conv9_2    = convolution(conv9_2, predict -> loc_conv9_2_weight, predict -> loc_conv9_2_bias, N_BOX_CONV9_2 * 4, 1, 1, 1, 1, 0);
    struct Tensor* l_conv10_2   = convolution(conv10_2, predict -> loc_conv10_2_weight, predict -> loc_conv10_2_bias, N_BOX_CONV10_2 * 4, 1, 1, 1, 1, 0);
    struct Tensor* l_conv11_2   = convolution(conv11_2, predict -> loc_conv11_2_weight, predict -> loc_conv11_2_bias, N_BOX_CONV11_2 * 4, 1, 1, 1, 1, 0);

    struct Tensor* c_conv4_3    = convolution(conv4_3, predict -> cl_conv4_3_weight, predict -> cl_conv4_3_bias, N_BOX_CONV4_3 * N_CLASS, 1, 1, 1, 1, 0);
    struct Tensor* c_conv7      = convolution(conv7, predict -> cl_conv7_weight, predict -> cl_conv7_bias, N_BOX_CONV7 * N_CLASS, 1, 1, 1, 1, 0);
    struct Tensor* c_conv8_2    = convolution(conv8_2, predict -> cl_conv8_2_weight, predict -> cl_conv8_2_bias, N_BOX_CONV8_2 * N_CLASS, 1, 1, 1, 1, 0);
    struct Tensor* c_conv9_2    = convolution(conv9_2, predict -> cl_conv9_2_weight, predict -> cl_conv9_2_bias, N_BOX_CONV9_2 * N_CLASS, 1, 1, 1, 1, 0);
    struct Tensor* c_conv10_2   = convolution(conv10_2, predict -> cl_conv10_2_weight, predict -> cl_conv10_2_bias, N_BOX_CONV10_2 * N_CLASS, 1, 1, 1, 1, 0);
    struct Tensor* c_conv11_2   = convolution(conv11_2, predict -> cl_conv11_2_weight, predict -> cl_conv11_2_bias, N_BOX_CONV11_2 * N_CLASS, 1, 1, 1, 1, 0);

    // destroy_tensor(conv4_3);
    // destroy_tensor(conv7);
    // destroy_tensor(conv8_2);
    // destroy_tensor(conv9_2);
    // destroy_tensor(conv10_2);
    // destroy_tensor(conv11_2);

    l_conv4_3 -> row = 1;
    l_conv4_3 -> col = 5776;
    l_conv4_3 -> channel = 4;

    l_conv7 -> row = 1;
    l_conv7 -> col = 2166;
    l_conv7 -> channel = 4;

    l_conv8_2 -> row = 1;
    l_conv8_2 -> col = 600;
    l_conv8_2 -> channel = 4;

    l_conv9_2 -> row = 1;
    l_conv9_2 -> col = 150;
    l_conv9_2 -> channel = 4;

    l_conv10_2 -> row = 1;
    l_conv10_2 -> col = 36;
    l_conv10_2 -> channel = 4;

    l_conv11_2 -> row = 1;
    l_conv11_2 -> col = 4;
    l_conv11_2 -> channel = 4;

    c_conv4_3 -> row = 1;
    c_conv4_3 -> col = 5776;
    c_conv4_3 -> channel = N_CLASS;

    c_conv7 -> row = 1;
    c_conv7 -> col = 2166;
    c_conv7 -> channel = N_CLASS;

    c_conv8_2 -> row = 1;
    c_conv8_2 -> col = 600;
    c_conv8_2 -> channel = N_CLASS;

    c_conv9_2 -> row = 1;
    c_conv9_2 -> col = 150;
    c_conv9_2 -> channel = N_CLASS;

    c_conv10_2 -> row = 1;
    c_conv10_2 -> col = 36;
    c_conv10_2 -> channel = N_CLASS;

    c_conv11_2 -> row = 1;
    c_conv11_2 -> col = 4;
    c_conv11_2 -> channel = N_CLASS;

    struct Tensor** output = (struct Tensor**)malloc(sizeof(struct Tensor*) * 2);
    struct Tensor* locs             = (struct Tensor*)malloc(sizeof(struct Tensor));
    struct Tensor* classes_score    = (struct Tensor*)malloc(sizeof(struct Tensor));

    locs -> row = 1;
    locs -> col = 8732;
    locs -> channel = 4;
    locs -> data = (float*)malloc(sizeof(float) * locs -> row * locs -> col * locs -> channel);
    classes_score -> row = 1;
    classes_score -> col = 8732;
    classes_score -> channel = N_CLASS;
    classes_score -> data = (float*)malloc(sizeof(float) * classes_score -> row * classes_score -> col * classes_score -> channel);

    //memcpy from feature to output
    int offset = 0;
    int data_num = 0;

    data_num = l_conv4_3 -> row * l_conv4_3 -> col * l_conv4_3 -> channel;
    memcpy(locs -> data + offset, l_conv4_3 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = l_conv7 -> row * l_conv7 -> col * l_conv7 -> channel;
    memcpy(locs -> data + offset, l_conv7 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = l_conv8_2 -> row * l_conv8_2 -> col * l_conv8_2 -> channel;
    memcpy(locs -> data + offset, l_conv8_2 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = l_conv9_2 -> row * l_conv9_2 -> col * l_conv9_2 -> channel;
    memcpy(locs -> data + offset, l_conv9_2 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = l_conv10_2 -> row * l_conv10_2 -> col * l_conv10_2 -> channel;
    memcpy(locs -> data + offset, l_conv10_2 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = l_conv11_2 -> row * l_conv11_2 -> col * l_conv11_2 -> channel;
    memcpy(locs -> data + offset, l_conv11_2 -> data, sizeof(float) * data_num);
    offset += data_num;

    offset = 0;
    
    data_num = c_conv4_3 -> row * c_conv4_3 -> col * c_conv4_3 -> channel;
    memcpy(classes_score -> data + offset, c_conv4_3 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = c_conv7 -> row * c_conv7 -> col * c_conv7 -> channel;
    memcpy(classes_score -> data + offset, c_conv7 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = c_conv8_2 -> row * c_conv8_2 -> col * c_conv8_2 -> channel;
    memcpy(classes_score -> data + offset, c_conv8_2 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = c_conv9_2 -> row * c_conv9_2 -> col * c_conv9_2 -> channel;
    memcpy(classes_score -> data + offset, c_conv9_2 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = c_conv10_2 -> row * c_conv10_2 -> col * c_conv10_2 -> channel;
    memcpy(classes_score -> data + offset, c_conv10_2 -> data, sizeof(float) * data_num);
    offset += data_num;
    data_num = c_conv11_2 -> row * c_conv11_2 -> col * c_conv11_2 -> channel;
    memcpy(classes_score -> data + offset, c_conv11_2 -> data, sizeof(float) * data_num);
    offset += data_num;

    output[0] = locs;
    output[1] = classes_score;

    destroy_tensor(l_conv4_3);
    destroy_tensor(l_conv7);
    destroy_tensor(l_conv8_2);
    destroy_tensor(l_conv9_2);
    destroy_tensor(l_conv10_2);
    destroy_tensor(l_conv11_2);

    destroy_tensor(c_conv4_3);
    destroy_tensor(c_conv7);
    destroy_tensor(c_conv8_2);
    destroy_tensor(c_conv9_2);
    destroy_tensor(c_conv10_2);
    destroy_tensor(c_conv11_2);

    return output;
}