#ifndef TENSOR_H
#define TENSOR_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <assert.h>

struct Tensor{
    uint32_t row;
    uint32_t col;
    uint32_t channel;
    float* data;
};

struct Tensor* create_tensor(float* data, uint32_t batch, uint32_t channel, uint32_t row, uint32_t col);
void import_tensor(char* path, struct Tensor* t);
void export_tensor(char* path, struct Tensor* t);
void destroy_tensor(struct Tensor* t);

#endif