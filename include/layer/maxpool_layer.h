#ifndef MAXPOOL_LAYER_H
#define MAXPOOL_LAYER_H

#include "../tensor/tensor.h"

struct Tensor* maxpool(
    struct Tensor* input,
    int kernel_row,
    int kernel_col,
    int stride_row,
    int stride_col,
    int ceil_mode
);

#endif