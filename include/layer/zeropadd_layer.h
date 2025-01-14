#ifndef ZEROPADD_LAYER_H
#define ZEROPADD_LAYER_H

#include "../tensor/tensor.h"

struct Tensor* zeropadd(
    struct Tensor* input,
    int padding_num
);

#endif