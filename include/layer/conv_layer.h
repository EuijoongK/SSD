#ifndef CONV_LAYER_H
#define CONV_LAYER_H

#include "../tensor/tensor.h"

struct Tensor* convolution(
    struct Tensor* input,
    struct Tensor* weight,
    struct Tensor* bias,
    uint32_t output_channel,
    uint32_t stride_row,
    uint32_t stride_col,
    uint32_t padding_num
);

#endif