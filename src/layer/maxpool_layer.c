#include "../../include/layer/maxpool_layer.h"

void calculate_maxpool_sz(
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t stride_row,
    const uint32_t stride_col,
    uint32_t* output_row,
    uint32_t* output_col
){
    *output_row = (uint32_t)((input_row - kernel_row) / stride_row) + 1;
    *output_col = (uint32_t)((input_col - kernel_col) / stride_col) + 1;
    return;
}


float get_max_value(
    const float* ptr,
    uint32_t row,
    uint32_t col,
    uint32_t channel,
    uint32_t kernel_row,
    uint32_t kernel_col
){
    float ans = *ptr;
    float buf;

    uint32_t i, j;
    for(i = 0; i < kernel_row; ++i){
        for(j = 0; j < kernel_col; ++j){
            buf = *(ptr + i * col * channel + j * channel);
            if(buf > ans){
                ans = buf;
            }
        }
    }
    return ans;
}

struct Tensor* maxpool(
    struct Tensor* input,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t stride_row,
    uint32_t stride_col
){
    uint32_t input_row      = input -> row;
    uint32_t input_col      = input -> col;
    uint32_t input_channel  = input -> channel;
    float* input_data       = input -> data;

    uint32_t output_row, output_col;
    uint32_t output_channel = input_channel;
    calculate_maxpool_sz(input_row, input_col, kernel_row, kernel_col,
                        stride_row, stride_col, &output_row, &output_col);

    float* output_data = (float*)malloc(sizeof(float) * output_row * output_col * output_channel);

    float* input_ptr;
    float* output_ptr;

    for(int i = 0; i < output_row; ++i){
        for(int j = 0; j < output_col; ++j){
            for(int k = 0; k < output_channel; ++k){
                input_ptr = input_data + i * stride_row * input_col * input_channel
                            + j * stride_col * input_channel + k;
                output_ptr = output_data + i * output_col * output_channel + j * output_channel + k;
                *output_ptr = get_max_value(input_ptr, input_row, input_col, input_channel, 
                                            kernel_row, kernel_col);
            }
        }
    }

    struct Tensor* output = (struct Tensor*)malloc(sizeof(struct Tensor));
    output -> row       = output_row;
    output -> col       = output_col;
    output -> channel   = output_channel;
    output -> data      = output_data;
    return output;
}