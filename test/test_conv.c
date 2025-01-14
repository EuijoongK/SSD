#include "../include/model/vgg.h"

int main(){

    printf("Load input data...\n");
    char* input_path = "./data/2007_000480.bin";
    uint32_t in_row = 375;
    uint32_t in_col = 500;
    uint32_t in_channel = 3;
    struct Tensor* input = image_from_bin(input_path, in_row, in_col, in_channel);

    // FILE* fp = fopen("./output/input_first_channel.bin", "rb");
    // float* buf = (float*)malloc(sizeof(float) * 373 * 498);
    // fread(buf, sizeof(float), in_row * in_col, fp);

    // int flag = 1;
    // float error = 1e-7;

    // float* in_data = input -> data;
    // for(int i = 0; i < 373; ++i){
    //     for(int j = 0; j < 498; ++j){
    //         float* current_in = in_data + (i * in_col * in_channel) + j * in_channel;
    //         if(abs((*current_in) - (*(buf + i * 498 + j))) > error){
    //             flag = 0;
    //             break;
    //         }
    //     }
    // }

    FILE* fp = fopen("./output/input_first_conv.bin", "rb");
    float* buf = (float*)malloc(sizeof(float) * 3 * 3 * 3 * 64);
    fread(buf, sizeof(float), 3 * 3 * 3 * 64, fp);

    int flag = 1;
    float error = 1e-7;

    float* in_data = input -> data;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                float temp = *(in_data + i * 9 + j * 3 + k);
                float temp2 = *(buf + i * 9 + j * 3 + k);

                if(abs(temp - temp2) > error){
                    flag = 0;
                    break;
                }
            }
        }
    }

    if(flag){
        printf("Successfully loaded\n");
    }else{
        printf("Failure\n");
    }

    fclose(fp);

    destroy_tensor(input);
}