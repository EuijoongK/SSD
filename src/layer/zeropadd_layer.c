#include "../../include/layer/zeropadd_layer.h"


struct Tensor* ZeroPadd(
    struct Tensor* input,
    uint32_t padding_num
){
    struct Tensor* output = zeropadd(input, padding_num);
    if(input != NULL){
        if(input -> data != NULL){
            free(input -> data);
            input -> data = NULL;
        }
        free(input);
        input = NULL;
    }
    return output;
}

struct Tensor* zeropadd(
    struct Tensor* input,
    uint32_t padding_num
){
    uint32_t input_row      = input -> row;
    uint32_t input_col      = input -> col;
    uint32_t input_channel  = input -> channel;
    float* input_data       = input -> data;

    uint32_t output_row     = input_row + 2 * padding_num;
    uint32_t output_col     = input_col + 2 * padding_num;
    uint32_t output_channel = input_channel;
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