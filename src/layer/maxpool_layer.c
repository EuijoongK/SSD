#include "../../include/layer/maxpool_layer.h"

void calculate_maxpool_sz(
    const int input_row,
    const int input_col,
    const int kernel_row,
    const int kernel_col,
    const int stride_row,
    const int stride_col,
    int* output_row,
    int* output_col,
    int ceil_mode
){
    if(ceil_mode){
        *output_row = (int)((input_row - kernel_row) / stride_row) + 2;
        *output_col = (int)((input_col - kernel_col) / stride_col) + 2;
    }else{
        *output_row = (int)((input_row - kernel_row) / stride_row) + 1;
        *output_col = (int)((input_col - kernel_col) / stride_col) + 1;
    }
    return;
}


float get_max_value(
    const float* ptr,
    int row,
    int col,
    int channel,
    int kernel_row,
    int kernel_col
){
    float ans = *ptr;
    float buf;

    int i, j;
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
    int kernel_row,
    int kernel_col,
    int stride_row,
    int stride_col,
    int ceil_mode
){
    int input_row      = input -> row;
    int input_col      = input -> col;
    int input_channel  = input -> channel;
    float* input_data       = input -> data;

    int output_row, output_col;
    int output_channel = input_channel;
    calculate_maxpool_sz(input_row, input_col, kernel_row, kernel_col,
                        stride_row, stride_col, &output_row, &output_col, ceil_mode);

    float* temp;
    if(ceil_mode){
        temp = (float*)malloc(sizeof(float) * (input_row + 1) * (input_col + 1) * input_channel);
        memset(temp, 0, sizeof(float) * (input_row + 1) * (input_col + 1) * input_channel);
        // memcpy from input_data to temp
        ///////////////////////////////////////////////////////////////////////////////////

        for(int i = 0; i < input_row; ++i){
            for(int j = 0; j < input_col; ++j){
                float* src_ptr = input_data + i * input_col * input_channel+ j * input_channel;
                float* dst_ptr = temp + i * (input_col + 1) * input_channel + j * input_channel;
                memcpy(dst_ptr, src_ptr, sizeof(float) * input_channel);
            }
        }

        input_row += 1;
        input_col += 1;

    }else{
        temp = input_data;
    }

    float* output_data = (float*)malloc(sizeof(float) * output_row * output_col * output_channel);
    float* input_ptr;
    float* output_ptr;

    for(int i = 0; i < output_row; ++i){
        for(int j = 0; j < output_col; ++j){
            for(int k = 0; k < output_channel; ++k){
                input_ptr = temp + i * stride_row * input_col * input_channel
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
    
    if(ceil_mode){
        free(temp);
    }
    return output;
}