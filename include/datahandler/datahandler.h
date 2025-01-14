#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "../tensor/tensor.h"


void import_tensor_float(char* path, struct Tensor* t);
struct Tensor* image_from_bin(char* path, int row, int col, int channel);
struct Tensor* tensor_from_bin(char* path, int row, int col, int channel);
void export_tensor(char* path, struct Tensor* t);

void import_conv_weight(
    char* path,
    struct Tensor* t,
    int kernel_row,
    int kernel_col,
    int kernel_channel,
    int kernel_num
);

void import_conv_bias(
    char* path,
    struct Tensor* t,
    int kernel_row,
    int kernel_col,
    int kernel_channel,
    int kernel_num
);

void normalize_img(float* input, int row, int col);

#endif