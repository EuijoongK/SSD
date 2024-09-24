#include "../include/layer/maxpool_layer.h"

int main(){
    float data[27];
    struct Tensor t;
    t.row = 3;
    t.col = 3;
    t.channel = 3;
    
    for(int i = 0; i < t.row; ++i){
        for(int j = 0; j < t.col; ++j){
            for(int k = 0; k < t.channel; ++k){
                data[i * t.col * t.channel + j * t.channel + k] = 3 * i + j + k * 9;
                printf("%f\t", data[i * t.col * t.channel + j * t.channel + k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    t.data = data;

    printf("=============================\n");
    printf("Maxpool Result\n");
    struct Tensor* output = maxpool(&t, 2, 2, 1, 1);
    for(int i = 0; i < output -> row; ++i){
        for(int j = 0; j < output -> col; ++j){
            for(int k = 0; k < output -> channel; ++k){
                printf("%f\t", output -> data[i * output -> col * output -> channel + j * output -> channel + k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    destroy_tensor(output);
}