#include "../../include/datahandler/datahandler.h"

void import_tensor_float(char* path, struct Tensor* t)
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

struct Tensor* image_from_bin(char* path, int row, int col, int channel)
{
    FILE* fp;
    fp = fopen(path, "rb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist\n");
        return;
    }

    uint8_t* buf = (uint8_t*)malloc(sizeof(uint8_t) * row * col * channel);
    struct Tensor* t = (struct Tensor*)malloc(sizeof(struct Tensor));

    t -> row        = row;
    t -> col        = col;
    t -> channel    = channel;
    t -> data       = (float*)malloc(sizeof(float) * row * col * channel);

    fread(buf, sizeof(uint8_t), row * col * channel, fp);
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            for(int k = 0; k < channel; ++k){
                (t -> data)[i * col * channel + j * channel + k] = 
                    (float)buf[i * col * channel + j * channel + k];
            }
        }
    }
    fclose(fp);
    free(buf);
    return t;
}

struct Tensor* tensor_from_bin(char* path, int row, int col, int channel)
{
    FILE* fp;
    fp = fopen(path, "rb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist\n");
        return;
    }
    
    struct Tensor* t = (struct Tensor*)malloc(sizeof(struct Tensor));
    t -> row        = row;
    t -> col        = col;
    t -> channel    = channel;
    t -> data       = (float*)malloc(sizeof(float) * row * col * channel);
    fread(t -> data, sizeof(float), row * col * channel, fp);
    return t;
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


void import_conv_weight(
    char* path,
    struct Tensor* t,
    int kernel_row,
    int kernel_col,
    int kernel_channel,
    int kernel_num
){
    assert(t -> row == kernel_row && t -> col == kernel_col && t -> channel == kernel_channel);
    FILE* fp;
    fp = fopen(path, "rb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist\n");
        return;
    }
    
    float* buf = (float*)malloc(sizeof(float) * kernel_row * kernel_col * kernel_channel);
    float* current_buf;
    struct Tensor* current_tensor;

    for(int i = 0; i < kernel_num; ++i){
        fread(buf, sizeof(float), kernel_row * kernel_col * kernel_channel, fp);
        current_buf = buf;
        current_tensor = t + i;                                             // struct Tensor conv_weight[128]

        for(int j = 0; j < kernel_channel; ++j){
            for(int k = 0; k < kernel_row; ++k){
                for(int l = 0; l < kernel_col; ++l){
                    (current_tensor -> data)[k * kernel_col * kernel_channel + l * kernel_channel + j] =
                        (float)current_buf[j * kernel_row * kernel_col + k * kernel_col + l];
                }
            }
        }
    }
    fclose(fp);
    free(buf);
}

void import_conv_bias(
    char* path,
    struct Tensor* t,
    int kernel_row,
    int kernel_col,
    int kernel_channel,
    int kernel_num
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


    for(int i = 0; i < kernel_num; ++i){
        current_buf = buf + i * kernel_row * kernel_col * kernel_channel;
        current_tensor = t + i;
        // memcpy(current_tensor -> data, current_buf, sizeof(float) * kernel_row * kernel_col * kernel_channel);
        for(int j = 0; j < kernel_row; ++j){
            for(int k = 0; k < kernel_col; ++k){
                for(int l = 0; l < kernel_channel; ++l){
                    (current_tensor -> data)[k * kernel_col * kernel_channel + l * kernel_channel + j] =
                        (float)current_buf[j * kernel_row * kernel_col + k * kernel_col + l];
                }
            }
        }
    }
    fclose(fp);
    free(buf);
}

void normalize_img(float* input, int row, int col)
{
    float mean[3]   = {0.485, 0.456, 0.406};
    float std[3]    = {0.229, 0.224, 0.225};

    float temp = 0.0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            for(int k = 0; k < 3; ++k){
                temp = *(input + i * col * 3 + j * 3 + k);
                temp /= 255.0;
                temp = (temp - mean[k]) / std[k];
                *(input + i * col * 3 + j * 3 + k) = temp;
            }
        }
    }
}
