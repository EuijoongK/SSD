#include "../../include/model/auxiliary.h"

void auxiliary_init(struct Auxiliary* aux)
{
    // Initialize conv8
    for(int i = 0; i < 256; ++i){
        (aux -> conv8_1_weight)[i].row = 1;
        (aux -> conv8_1_weight)[i].col = 1;
        (aux -> conv8_1_weight)[i].channel = 1024;
        (aux -> conv8_1_weight)[i].data = (float*)malloc(sizeof(float) * 1 * 1 * 1024);
        
        (aux -> conv8_1_bias)[i].row = 1;
        (aux -> conv8_1_bias)[i].col = 1;
        (aux -> conv8_1_bias)[i].channel = 1;
        (aux -> conv8_1_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < 512; ++i){
        (aux -> conv8_2_weight)[i].row = 3;
        (aux -> conv8_2_weight)[i].col = 3;
        (aux -> conv8_2_weight)[i].channel = 256;
        (aux -> conv8_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 256);
        
        (aux -> conv8_2_bias)[i].row = 1;
        (aux -> conv8_2_bias)[i].col = 1;
        (aux -> conv8_2_bias)[i].channel = 1;
        (aux -> conv8_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    // Initialize conv9
    for(int i = 0; i < 128; ++i){
        (aux -> conv9_1_weight)[i].row = 1;
        (aux -> conv9_1_weight)[i].col = 1;
        (aux -> conv9_1_weight)[i].channel = 512;
        (aux -> conv9_1_weight)[i].data = (float*)malloc(sizeof(float) * 1 * 1 * 512);
        
        (aux -> conv9_1_bias)[i].row = 1;
        (aux -> conv9_1_bias)[i].col = 1;
        (aux -> conv9_1_bias)[i].channel = 1;
        (aux -> conv9_1_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < 256; ++i){
        (aux -> conv9_2_weight)[i].row = 3;
        (aux -> conv9_2_weight)[i].col = 3;
        (aux -> conv9_2_weight)[i].channel = 128;
        (aux -> conv9_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 128);
        
        (aux -> conv9_2_bias)[i].row = 1;
        (aux -> conv9_2_bias)[i].col = 1;
        (aux -> conv9_2_bias)[i].channel = 1;
        (aux -> conv9_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    // Initialize conv10
    for(int i = 0; i < 128; ++i){
        (aux -> conv10_1_weight)[i].row = 1;
        (aux -> conv10_1_weight)[i].col = 1;
        (aux -> conv10_1_weight)[i].channel = 256;
        (aux -> conv10_1_weight)[i].data = (float*)malloc(sizeof(float) * 1 * 1 * 256);
        
        (aux -> conv10_1_bias)[i].row = 1;
        (aux -> conv10_1_bias)[i].col = 1;
        (aux -> conv10_1_bias)[i].channel = 1;
        (aux -> conv10_1_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < 256; ++i){
        (aux -> conv10_2_weight)[i].row = 3;
        (aux -> conv10_2_weight)[i].col = 3;
        (aux -> conv10_2_weight)[i].channel = 128;
        (aux -> conv10_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 128);
        
        (aux -> conv10_2_bias)[i].row = 1;
        (aux -> conv10_2_bias)[i].col = 1;
        (aux -> conv10_2_bias)[i].channel = 1;
        (aux -> conv10_2_bias)[i].data = (float*)malloc(sizeof(float));
    }

    // Initialize conv11
    for(int i = 0; i < 128; ++i){
        (aux -> conv11_1_weight)[i].row = 1;
        (aux -> conv11_1_weight)[i].col = 1;
        (aux -> conv11_1_weight)[i].channel = 256;
        (aux -> conv11_1_weight)[i].data = (float*)malloc(sizeof(float) * 1 * 1 * 256);
        
        (aux -> conv11_1_bias)[i].row = 1;
        (aux -> conv11_1_bias)[i].col = 1;
        (aux -> conv11_1_bias)[i].channel = 1;
        (aux -> conv11_1_bias)[i].data = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < 256; ++i){
        (aux -> conv11_2_weight)[i].row = 3;
        (aux -> conv11_2_weight)[i].col = 3;
        (aux -> conv11_2_weight)[i].channel = 128;
        (aux -> conv11_2_weight)[i].data = (float*)malloc(sizeof(float) * 3 * 3 * 128);
        
        (aux -> conv11_2_bias)[i].row = 1;
        (aux -> conv11_2_bias)[i].col = 1;
        (aux -> conv11_2_bias)[i].channel = 1;
        (aux -> conv11_2_bias)[i].data = (float*)malloc(sizeof(float));
    }
}

void auxiliary_load_param(struct Auxiliary* aux)
{
    char* conv8_1_weight_path   = "./param/aux_convs_conv8_1_weight.bin";
    char* conv8_1_bias_path     = "./param/aux_convs_conv8_1_bias.bin";
    char* conv8_2_weight_path   = "./param/aux_convs_conv8_2_weight.bin";
    char* conv8_2_bias_path     = "./param/aux_convs_conv8_2_bias.bin";

    char* conv9_1_weight_path   = "./param/aux_convs_conv9_1_weight.bin";
    char* conv9_1_bias_path     = "./param/aux_convs_conv9_1_bias.bin";
    char* conv9_2_weight_path   = "./param/aux_convs_conv9_2_weight.bin";
    char* conv9_2_bias_path     = "./param/aux_convs_conv9_2_bias.bin";

    char* conv10_1_weight_path   = "./param/aux_convs_conv10_1_weight.bin";
    char* conv10_1_bias_path     = "./param/aux_convs_conv10_1_bias.bin";
    char* conv10_2_weight_path   = "./param/aux_convs_conv10_2_weight.bin";
    char* conv10_2_bias_path     = "./param/aux_convs_conv10_2_bias.bin";

    char* conv11_1_weight_path   = "./param/aux_convs_conv11_1_weight.bin";
    char* conv11_1_bias_path     = "./param/aux_convs_conv11_1_bias.bin";
    char* conv11_2_weight_path   = "./param/aux_convs_conv11_2_weight.bin";
    char* conv11_2_bias_path     = "./param/aux_convs_conv11_2_bias.bin";

    import_conv_weight(conv8_1_weight_path, aux -> conv8_1_weight, 1, 1, 1024, 256);
    import_conv_bias(conv8_1_bias_path, aux -> conv8_1_bias, 1, 1, 1, 256);
    import_conv_weight(conv8_2_weight_path, aux -> conv8_2_weight, 3, 3, 256, 512);
    import_conv_bias(conv8_2_bias_path, aux -> conv8_2_bias, 1, 1, 1, 512);

    import_conv_weight(conv9_1_weight_path, aux -> conv9_1_weight, 1, 1, 512, 128);
    import_conv_bias(conv9_1_bias_path, aux -> conv9_1_bias, 1, 1, 1, 128);
    import_conv_weight(conv9_2_weight_path, aux -> conv9_2_weight, 3, 3, 128, 256);
    import_conv_bias(conv9_2_bias_path, aux -> conv9_2_bias, 1, 1, 1, 256);

    import_conv_weight(conv10_1_weight_path, aux -> conv10_1_weight, 1, 1, 256, 128);
    import_conv_bias(conv10_1_bias_path, aux -> conv10_1_bias, 1, 1, 1, 128);
    import_conv_weight(conv10_2_weight_path, aux -> conv10_2_weight, 3, 3, 128, 256);
    import_conv_bias(conv10_2_bias_path, aux -> conv10_2_bias, 1, 1, 1, 256);

    import_conv_weight(conv11_1_weight_path, aux -> conv11_1_weight, 1, 1, 256, 128);
    import_conv_bias(conv11_1_bias_path, aux -> conv11_1_bias, 1, 1, 1, 128);
    import_conv_weight(conv11_2_weight_path, aux -> conv11_2_weight, 3, 3, 128, 256);
    import_conv_bias(conv11_2_bias_path, aux -> conv11_2_bias, 1, 1, 1, 256);
}

void auxiliary_destroy(struct Auxiliary* aux)
{
    for(int i = 0; i < 256; ++i){
        free(aux -> conv8_1_weight[i].data);
        free(aux -> conv8_1_bias[i].data);
        aux -> conv8_1_weight[i].data = NULL;
        aux -> conv8_1_bias[i].data = NULL;
    }

    for(int i = 0; i < 512; ++i){
        free(aux -> conv8_2_weight[i].data);
        free(aux -> conv8_2_bias[i].data);
        aux -> conv8_2_weight[i].data = NULL;
        aux -> conv8_2_bias[i].data = NULL;
    }
    
    for(int i = 0; i < 128; ++i){
        free(aux -> conv9_1_weight[i].data);
        free(aux -> conv9_1_bias[i].data);
        aux -> conv9_1_weight[i].data = NULL;
        aux -> conv9_1_bias[i].data = NULL;
    }

    for(int i = 0; i < 256; ++i){
        free(aux -> conv9_2_weight[i].data);
        free(aux -> conv9_2_bias[i].data);
        aux -> conv9_2_weight[i].data = NULL;
        aux -> conv9_2_bias[i].data = NULL;
    }

    for(int i = 0; i < 128; ++i){
        free(aux -> conv10_1_weight[i].data);
        free(aux -> conv10_1_bias[i].data);
        aux -> conv10_1_weight[i].data = NULL;
        aux -> conv10_1_bias[i].data = NULL;
    }

    for(int i = 0; i < 256; ++i){
        free(aux -> conv10_2_weight[i].data);
        free(aux -> conv10_2_bias[i].data);
        aux -> conv10_2_weight[i].data = NULL;
        aux -> conv10_2_bias[i].data = NULL;
    }

    for(int i = 0; i < 128; ++i){
        free(aux -> conv11_1_weight[i].data);
        free(aux -> conv11_1_bias[i].data);
        aux -> conv11_1_weight[i].data = NULL;
        aux -> conv11_1_bias[i].data = NULL;
    }

    for(int i = 0; i < 256; ++i){
        free(aux -> conv11_2_weight[i].data);
        free(aux -> conv11_2_bias[i].data);
        aux -> conv11_2_weight[i].data = NULL;
        aux -> conv11_2_bias[i].data = NULL;
    }
}

struct Tensor** auxilairy_run(struct Auxiliary* aux, struct Tensor* input)
{
    struct Tensor** output = (struct Tensor**)malloc(sizeof(struct Tensor*) * 4);
    // printf("Conv8_1\n");
    struct Tensor* out_conv8_1 = convolution(input, aux -> conv8_1_weight, aux -> conv8_1_bias, 256, 1, 1, 0, 1, 1);
    // destroy_tensor(input);
    // need input for prediction

    // printf("Conv8_2\n");
    struct Tensor* out_conv8_2 = convolution(out_conv8_1, aux -> conv8_2_weight, aux -> conv8_2_bias, 512, 2, 2, 1, 1, 1);
    destroy_tensor(out_conv8_1);
    output[0] = out_conv8_2;

    // printf("Conv9_1\n");
    struct Tensor* out_conv9_1 = convolution(out_conv8_2, aux -> conv9_1_weight, aux -> conv9_1_bias, 128, 1, 1, 0, 1, 1);
    // destroy_tensor(out_conv8_2);
    // need input for prediction

    // printf("Conv9_2\n");
    struct Tensor* out_conv9_2 = convolution(out_conv9_1, aux -> conv9_2_weight, aux -> conv9_2_bias, 256, 2, 2, 1, 1, 1);
    destroy_tensor(out_conv9_1);
    output[1] = out_conv9_2;

    // printf("Conv10_1\n");
    struct Tensor* out_conv10_1 = convolution(out_conv9_2, aux -> conv10_1_weight, aux -> conv10_1_bias, 128, 1, 1, 0, 1, 1);
    // destroy_tensor(out_conv9_2);
    // need input for prediction

    // printf("Conv10_2\n");
    struct Tensor* out_conv10_2 = convolution(out_conv10_1, aux -> conv10_2_weight, aux -> conv10_2_bias, 256, 1, 1, 0, 1, 1);
    destroy_tensor(out_conv10_1);
    output[2] = out_conv10_2;

    // printf("Conv11_1\n");
    struct Tensor* out_conv11_1 = convolution(out_conv10_2, aux -> conv11_1_weight, aux -> conv11_1_bias, 128, 1, 1, 0, 1, 1);
    // destroy_tensor(out_conv10_2);
    // need input for prediction

    // printf("Conv11_2\n");
    struct Tensor* out_conv11_2 = convolution(out_conv11_1, aux -> conv11_2_weight, aux -> conv11_2_bias, 256, 1, 1, 0, 1, 1);
    destroy_tensor(out_conv11_1);
    output[3] = out_conv11_2;
    
    return output;
}