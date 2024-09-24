#ifndef ZEROPADD_LAYER_H
#define ZEROPADD_LAYER_H

#include "../tensor/tensor.h"

struct Tensor* ZeroPadd(
    struct Tensor* input,
    uint32_t padding_num
);

struct Tensor* zeropadd(
    struct Tensor* input,
    uint32_t padding_num
);

#endif