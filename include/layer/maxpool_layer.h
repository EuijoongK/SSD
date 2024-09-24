#ifndef MAXPOOL_LAYER_H
#define MAXPOOL_LAYER_H

#include "../tensor/tensor.h"


struct Tensor* maxpool(
    struct Tensor* input,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t stride_row,
    uint32_t stride_col
);

#endif