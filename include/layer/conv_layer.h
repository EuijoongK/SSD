#ifndef CONV_LAYER_H
#define CONV_LAYER_H

#include "../tensor/tensor.h"
#include "zeropadd_layer.h"

struct Tensor* dilation_weight(
    struct Tensor* weight,
    int num_weight,
    int dilation
);

struct Tensor* convolution(
    struct Tensor* input,
    struct Tensor* weight,
    struct Tensor* bias,
    int output_channel,
    int stride_row,
    int stride_col,
    int padding_num,
    int dilation,
    int relu_opt
);

#endif