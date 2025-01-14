#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char* file_path = "./data/2007_000480.bin";
    int width = 500;
    int height = 375;
    int channel = 3;

    int sz = width * height * channel;
    unsigned char* buf = (unsigned char*)malloc(sizeof(unsigned char) * sz);

    FILE* fp = fopen(file_path, "rb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist!\n");
        return 0;
    }
    fread(buf, sizeof(unsigned char), sz, fp);
    fclose(fp);

    unsigned char* output = (unsigned char*)malloc(sizeof(unsigned char) * sz / channel);


// Data Order : BHWC
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            for(int k = 0; k < channel; ++k){
                if(k == 0){
                    *(output + i * width + j) = *(buf + i * width * channel + j * channel + k);
                }
            }
        }
    }

    fp = fopen("./data/gray_img.bin", "wb");
    if(fp == NULL){
        fprintf(stderr, "The path does not exist!\n");
        return 0;
    }
    fwrite(output, sizeof(unsigned char), sz / channel, fp);
    fclose(fp);

    free(output);
    free(buf);
}