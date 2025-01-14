// #include "../include/layer/maxpool_layer.h"                      // compile error, not debugged yet
#include "../include/model/vgg.h"

int main(){
    printf("Load input data...\n");
    char* input_path = "./data/2007_000480.bin";
    int in_row = 300;
    int in_col = 300;
    int in_channel = 3;
    struct Tensor* input = image_from_bin(input_path, in_row, in_col, in_channel);

    printf("Maxpooling...\n");
    struct Tensor* output = maxpool(input, 3, 3, 2, 2, 0);

    printf("Saving output...\n");
    char* output_file = "./output/maxpool_test.bin";
    FILE* fp = fopen(output_file, "wb");
    fwrite(output -> data, sizeof(float), (output -> row) * (output -> col) * (output -> channel), fp);
    fclose(fp);

    printf("Row     : %d\n", output -> row);
    printf("Col     : %d\n", output -> col);
    printf("Channel : %d\n", output -> channel);
    
    printf("Destroying tensor...\n");
    destroy_tensor(output);
}

// verified 241225, compared maxpool result of C and python, np.allclose successful