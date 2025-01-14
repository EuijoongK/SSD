// #include "../include/layer/zeropadd_layer.h"
#include "../include/model/vgg.h"

int main(){
        printf("Load input data...\n");
    char* input_path = "./data/2007_000480.bin";
    int in_row = 300;
    int in_col = 300;
    int in_channel = 3;
    struct Tensor* input = image_from_bin(input_path, in_row, in_col, in_channel);

    printf("Zeropadding...\n");
    struct Tensor* output = zeropadd(input, 5);

    printf("Saving output...\n");
    char* output_file = "./output/zeropadd_test.bin";
    FILE* fp = fopen(output_file, "wb");
    fwrite(output -> data, sizeof(float), (output -> row) * (output -> col) * (output -> channel), fp);
    fclose(fp);

    printf("Destroying tensor...\n");
    destroy_tensor(output);
}                                           // verified 241225