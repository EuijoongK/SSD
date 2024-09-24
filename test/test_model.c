#include "../include/model/vgg.h"

#define BUF_MAX_SIZE    10000000

int main(){
    char* input_path = "./data/2007_000480.bin";
    uint32_t in_row = 375;
    uint32_t in_col = 500;
    uint32_t in_channel = 3;
    uint8_t buf[BUF_MAX_SIZE];
    FILE* fp;
    fp = fopen(input_path, "rb");
    fread(buf, sizeof(uint8_t), in_row * in_col * in_channel, fp);
    fclose(fp);

    struct Tensor* input;
    input -> data = (float*)malloc(sizeof(float) * in_row * in_col * in_channel);

    for(int i = 0; i < in_row; ++i){
        for(int j = 0; j < in_col; ++j){
            for(int k = 0; k < in_channel; ++k){
                input -> data[i * in_col * in_channel + j * in_channel + k] = 
                    (float)buf[i * in_col * in_channel + j * in_channel + k];
            }
        }
    }

    struct VGGBase model;
    vgg_init(&model);
    vgg_load_param(&model);

    float* data         = model.conv1_1_weight[0].data;
    uint32_t row        = model.conv1_1_weight[0].row;
    uint32_t col        = model.conv1_1_weight[0].col;
    uint32_t channel    = model.conv1_1_weight[0].channel;

    uint32_t num = 0;
    float* current_data = data + num;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            for(int k = 0; k < channel; ++k){
                printf("%f\t", current_data[i * col * channel + j * channel + k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    vgg_destroy(&model);
    free(input -> data);
}