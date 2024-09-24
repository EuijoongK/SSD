#include "../../include/layer/conv_layer.h"


void calculate_conv_sz(
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    uint32_t* output_row,
    uint32_t* output_col
){
    *output_row = (uint32_t)((input_row - kernel_row + 2 * padding_num) / stride_row) + 1;
    *output_col = (uint32_t)((input_col - kernel_col + 2 * padding_num) / stride_col) + 1;
    return;
}


float conv_unit(
    float* input_data,
    float* kernel_data,
    uint32_t input_row,
    uint32_t input_col,
    uint32_t input_channel,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t bias
){
    float sum = bias;
    float* input_ptr;
    float* kernel_ptr;

    for(int i = 0; i < kernel_row; ++i){
        for(int j = 0; j < kernel_col; ++j){
            for(int k = 0; k < input_channel; ++k){
                input_ptr = input_data + i * input_col * input_channel + j * input_channel + k;
                kernel_ptr = kernel_data + i * kernel_col * input_channel + j * input_channel + k;
                sum += ((*input_ptr) * (*kernel_ptr));
            }
        }
    }
    return sum;
}


void conv_builtin(
    struct Tensor* output,
    struct Tensor* input,
    struct Tensor* weight,
    struct Tensor* bias,
    uint32_t stride_row,
    uint32_t stride_col,
    uint32_t padding_num
){
    uint32_t in_row         = input -> row;
    uint32_t in_col         = input -> col;
    uint32_t in_channel     = input -> channel;
    uint32_t out_row        = output -> row;
    uint32_t out_col        = output -> col;
    uint32_t out_channel    = output -> channel;
    uint32_t kernel_row     = weight -> row;
    uint32_t kernel_col     = weight -> col;
    uint32_t kernel_channel = weight -> channel;
    
    float* in_data          = input -> data;
    float* out_data         = output -> data;
    float* weight_data      = weight -> data;

    for(int i = 0; i < out_row; ++i){
        for(int j = 0; j < out_col; ++j){
            for(int k = 0; k < out_channel; ++k){

            }
        }
    }
}

struct Tensor* convolution(
    struct Tensor* input,
    struct Tensor* weight,
    struct Tensor* bias,
    uint32_t output_channel,
    uint32_t stride_row,
    uint32_t stride_col,
    uint32_t padding_num
){
    assert(input -> channel == weight -> channel);
    uint32_t output_row, output_col;
    calculate_conv_sz(input -> row, input -> col, weight -> row, weight -> col,
                    stride_row, stride_col, padding_num, &output_row, &output_col);

    float* output_data = (float*)malloc(sizeof(float) * output_row * output_col * output_channel);

    struct Tensor* output = (struct Tensor*)malloc(sizeof(struct Tensor));
    output -> row       = output_row;
    output -> col       = output_col;
    output -> channel   = output_channel;
    output -> data      = output_data;

    // Convolution layer
    for(int i = 0; i < output_channel; ++i){

    }


    return output;
}