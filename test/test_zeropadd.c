#include "../include/layer/zeropadd_layer.h"

int main(){
    float data[] = {1, 5, 2, 6, 3, 7, 4, 8};
    struct Tensor t;
    t.row = 2;
    t.col = 2;
    t.channel = 2;
    t.data = data;

    struct Tensor* output = zeropadd(&t, 2);

    int row = output -> row;
    int col = output -> col;
    int channel = output -> channel;

    printf("New row : %d\n", row);
    printf("New col : %d\n", col);

    printf("Zeropadding...\n");
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            for(int k = 0; k < channel; ++k){
                printf("%f\t", output -> data[i * col * channel + j * channel + k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    destroy_tensor(output);

    printf("sizeof int : %d\n", sizeof(int));
    printf("%ld\n", sizeof(float) * (1 << 31));
}