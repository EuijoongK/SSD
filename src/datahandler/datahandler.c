#include "../../include/datahandler/datahandler.h"


void import_tensor(char* path, struct Tensor* t)
{
    FILE* fp;
    fp = fopen(path, "rb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist\n");
        return;
    }
    fread(t -> data, sizeof(float), t -> row * t -> col * t -> channel, fp);
    return;
}


void export_tensor(char* path, struct Tensor* t)
{
    FILE* fp;
    fp = fopen(path, "wb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist\n");
        return;
    }
    fwrite(t -> data, sizeof(float), t -> row * t -> col * t -> channel, fp);
    return;
}


void import_conv_param(
    char* path,
    struct Tensor* t,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t kernel_channel,
    uint32_t kernel_num
){
    assert(t -> row == kernel_row && t -> col == kernel_col && t -> channel == kernel_channel);
    FILE* fp;
    fp = fopen(path, "rb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist\n");
        return;
    }
    
    float* buf = (float*)malloc(sizeof(float) * kernel_row * kernel_col * kernel_channel * kernel_num);
    fread(buf, sizeof(float), kernel_row * kernel_col * kernel_channel * kernel_num, fp);

    float* current_buf;
    struct Tensor* current_tensor;

#if DATA_ORDER_BCHW
    for(int i = 0; i < kernel_num; ++i){
        current_buf = buf + i * kernel_row * kernel_col * kernel_channel;
        current_tensor = t + i;
        memcpy(current_tensor -> data, current_buf, sizeof(float) * kernel_row * kernel_col * kernel_channel);
    }
#elif DATA_ORDER_BHWC
    for(int i = 0; i < kernel_num; ++i){
        current_buf = buf + i * kernel_row * kernel_col * kernel_channel;
        current_tensor = t + i;
        for(int j = 0; j < kernel_channel; ++j){
            for(int k = 0; k < kernel_row; ++k){
                for(int l = 0; l < kernel_col; ++l){
                    current_tensor -> data[k * kernel_col * kernel_channel + l * kernel_channel + j] = 
                        current_buf[j * kernel_row * kernel_col + k * kernel_col + l];
                }
            }
        }
    }
#endif

    free(buf);
}