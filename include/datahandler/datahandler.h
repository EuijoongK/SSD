#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "../tensor/tensor.h"

#define DATA_ORDER_BCHW     0
#define DATA_ORDER_BHWC     1 - DATA_ORDER_BCHW

void import_tensor(char* path, struct Tensor* t);
void export_tensor(char* path, struct Tensor* t);

void import_conv_param(
    char* path,
    struct Tensor* t,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t kernel_channel,
    uint32_t kernel_num
);

#endif