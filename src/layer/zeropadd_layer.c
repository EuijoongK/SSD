#include "../../include/layer/zeropadd_layer.h"

struct Tensor* zeropadd_builtin(
    struct Tensor* input,
    int padding_num
){
    int input_row      = input -> row;
    int input_col      = input -> col;
    int input_channel  = input -> channel;
    float* input_data       = input -> data;

    int output_row     = input_row + 2 * padding_num;
    int output_col     = input_col + 2 * padding_num;
    int output_channel = input_channel;
    float* output_data      = (float*)malloc(sizeof(float) * output_row * output_col * output_channel);
    memset(output_data, 0, sizeof(float) * output_row * output_col * output_channel);

    float* input_ptr;
    float* output_ptr;

    for(int i = 0; i < input_row; ++i){
        for(int j = 0; j < input_col; ++j){
            input_ptr   = input_data + i * input_col * input_channel + j * input_channel;
            output_ptr  = output_data + (i + padding_num) * output_col * output_channel
                            + (j + padding_num) * output_channel;
            memcpy(output_ptr, input_ptr, sizeof(float) * input_channel);
        }
    }

    struct Tensor* output = (struct Tensor*)malloc(sizeof(struct Tensor));
    output -> row       = output_row;
    output -> col       = output_col;
    output -> channel   = output_channel;
    output -> data      = output_data;
    return output;
}

struct Tensor* zeropadd(
    struct Tensor* input,
    int padding_num
){
    struct Tensor* output = zeropadd_builtin(input, padding_num);
    // destroy_tensor(input);                                       // destroyed at convolution layer
    return output;
}