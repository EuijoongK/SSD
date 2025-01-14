#include "../include/model/vgg.h"

int main(){
    struct VGGBase vgg;
    vgg_init(&vgg);
    vgg_load_param(&vgg);

    FILE* fp;
    fp = fopen("./output/conv2_1_weight.bin", "wb");

    for(int i = 0; i < 128; ++i){
        fwrite(vgg.conv2_1_weight[i].data, sizeof(float), 3 * 3 * 64, fp);
    }
    fclose(fp);

    fp = fopen("./output/conv2_1_bias.bin", "wb");
    for(int i = 0; i < 128; ++i){
        fwrite(vgg.conv2_1_bias[i].data, sizeof(float), 1, fp);
    }
    fclose(fp);

    vgg_destroy(&vgg);


    struct Tensor t;
    t.row = 3;
    t.col = 3;
    t.channel = 1;
    t.data = (float*)malloc(sizeof(float) * t.row * t.col * t.channel);

    for(int i = 0; i < t.row; ++i){
        for(int j = 0; j < t.col; ++j){
            for(int k = 0; k < t.channel; ++k){
                *(t.data + i * t.col * t.channel + j * t.channel + k) = i * t.col * t.channel + j * t.channel + k;
            }
        }
    }

    struct Tensor* output = dilation_weight(&t, 1, 2);
    int row = output -> row;
    int col = output -> col;
    int channel = output -> channel;

    printf("Row     : %d\n", row);
    printf("Col     : %d\n", col);
    printf("Channel : %d\n", channel);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            for(int k = 0; k < channel; ++k){
                printf("%f\t", *(output -> data + i * col * channel + j * channel + k));
            }
            printf("\n");
        }
    }

    free(output -> data);
    free(output);
    free(t.data);
}