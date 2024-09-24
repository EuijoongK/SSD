#include "../../include/tensor/tensor.h"

struct Tensor* create_tensor(float* data, uint32_t batch, uint32_t channel, uint32_t row, uint32_t col)
{
    struct Tensor* t = (struct Tensor*)malloc(sizeof(struct Tensor));
    t -> data      = data;
    // t -> batch     = batch;
    t -> channel   = channel;
    t -> row       = row;
    t -> col       = col;
    return t;
}

void import_tensor(char* path, struct Tensor* t)
{
    FILE* fp = NULL;
    fp = fopen(path, "rb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist\n");
    }
    uint32_t size = t -> row * t -> col * t -> channel; // * t -> batch;
    fread(t -> data, sizeof(float), size, fp);

    fclose(fp);
}

void export_tensor(char* path, struct Tensor* t)
{
    FILE* fp = NULL;
    fp = fopen(path, "wb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist\n");
    }
    uint32_t size = t -> row * t -> col * t -> channel; // * t -> batch;
    fwrite(t -> data, sizeof(float), size, fp);

    fclose(fp);
}

void destroy_tensor(struct Tensor* t)
{   
    if(t != NULL){
        if(t -> data != NULL){
            free(t -> data);
            t -> data = NULL;
        }
        free(t);
        t = NULL;
    }
    return;
}