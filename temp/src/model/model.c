#include "../../include/model/model.h"

void init(struct Model* model){
    model -> num_layer = 0;
    model -> num_featuremap = 0;
    model -> num_arr1d = 0;
    model -> num_conv_layer = 0;
    model -> num_fc_layer = 0;
    model -> num_maxpool_layer = 0;
    return;
}

void add_input(
    struct Model* model,
    struct FeatureMap* input
){
    model -> featuremap_list[0] = input;
    ++(model -> num_featuremap);
    return;
}

void add_conv_layer(
    struct Model* model,
    struct Kernel* kernel,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint32_t relu_opt
){  
    uint32_t model_index = model -> num_layer;
    uint32_t conv_index = model -> num_conv_layer;

    *((model -> layer) + model_index) = CONV;
    *((model -> conv_kernel_list) + conv_index) = kernel;

    struct ConvParam conv_param;
    conv_param.stride_row = stride_row;
    conv_param.stride_col = stride_col;
    conv_param.padding_num = padding_num;
    conv_param.relu_opt = relu_opt;

    *((model -> conv_param) + conv_index) = conv_param;

    ++(model -> num_layer);
    ++(model -> num_conv_layer);
    return;
}

void add_fc_layer(
    struct Model* model,
    struct kernel1D* kernel
){
   uint32_t model_index = model -> num_layer;
   uint32_t fc_index = model -> num_fc_layer;

   *((model -> layer) + model_index) = FC;
   *((model -> fc_kernel_list) + fc_index) = kernel;

   ++(model -> num_layer);
   ++(model -> num_fc_layer);
   return;
}

void add_maxpool_layer(
    struct Model* model,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t stride_row,
    uint32_t stride_col
){
    uint32_t model_index = model -> num_layer;
    
    struct MaxpoolParam maxpool_param;
    maxpool_param.kernel_row = kernel_row;
    maxpool_param.kernel_col = kernel_col;
    maxpool_param.stride_row = stride_row;
    maxpool_param.stride_col = stride_col;

    *((model -> layer) + model_index) = MAXPOOL;
    ++(model -> num_layer);
}

void run_conv_layer(
    struct Model* model,
    const uint32_t featuremap_index,
    const uint32_t conv_index
){
    struct FeatureMap* input = model -> featuremap_list[featuremap_index];
    struct Kernel* kernel = model -> conv_kernel_list[conv_index];
    struct ConvParam conv_param = model -> conv_param[conv_index];

    uint32_t stride_row = conv_param.stride_row;
    uint32_t stride_col = conv_param.stride_col;
    uint32_t padding_num = conv_param.padding_num;
    uint32_t relu_opt = conv_param.relu_opt;

    struct FeatureMap* output = Conv3D(input, kernel, stride_row, stride_col, padding_num, relu_opt);
    model -> featuremap_list[featuremap_index + 1] = output;
    ++(model -> num_featuremap);

    return;
}

void run_fc_layer(
    struct Model* model,
    const uint32_t arr1d_index,
    const uint32_t fc_index
){
    struct arr1D* input = model -> arr1D_list[arr1d_index];
    struct kernel1D* kernel = model -> fc_kernel_list[fc_index];

    struct arr1D* output = Fullyconnect(input, kernel);
    model -> arr1D_list[arr1d_index + 1] = output;
    ++(model -> num_arr1d);

    return;
}

void run_maxpool_layer(
    struct Model* model,
    const uint32_t maxpool_index
){
    
}

void run_model(struct Model* model){
    uint32_t num_layer = model -> num_layer;
    uint32_t num_featuremap = model -> num_featuremap;
    uint32_t num_arr1d = model -> num_arr1d;

    uint32_t index = 0;
    uint32_t featuremap_index = 0;
    uint32_t arr1d_index = 0;
    uint32_t conv_index = 0;
    uint32_t fc_index = 0;

    for(; index < num_layer; ++index){
        if(*(model -> layer + index) == CONV){
            run_conv_layer(model, featuremap_index, conv_index);
            ++featuremap_index;
            ++conv_index;

            if(featuremap_index == model -> num_featuremap){

            }
        }else if(*(model -> layer + index) == MAXPOOL){

        }else if(*(model -> layer + index) == FC){

        }
    }
}

struct arr1D* get_model_output(struct Model* model){
    
}

void freeModel(struct Model* model){
    /*
    for(uint32_t i = 0; i < model -> num_conv_layer; ++i){
        free(model -> conv_layer_list[i]);
        free(model -> conv_kernel_list[i]);
    }
    for(uint32_t i = 0; i < model -> num_fc_layer; ++i){
        free(model -> fc_layer_list[i]);
        free(model -> fc_kernel_list[i]);
    }
    */
    free(model);
    return;
}