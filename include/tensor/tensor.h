#ifndef TENSOR_H
#define TENSOR_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

struct Tensor{
    int row;
    int col;
    int channel;
    float* data;
};

struct Tensor* create_tensor(float* data, int batch, int channel, int row, int col);
// void import_tensor(char* path, struct Tensor* t);
// void export_tensor(char* path, struct Tensor* t);
void destroy_tensor(struct Tensor* t);

#endif