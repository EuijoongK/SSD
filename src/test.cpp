#include "network/model.hpp"
#include "datahandler/datahandler.hpp"
#include <iostream>

int main() {
    uint row = 5;
    uint col = 5;
    uint channel = 2;
    float* mat = (float*)malloc(sizeof(float) * row * col * channel);

    for (unsigned i = 0; i < row; ++i) {
        for (unsigned j = 0; j < col; ++j) {
            *(mat + i * col + j) = 10 * i + j;
            *(mat + row * col + i * col + j) = 20 * i + j;
        }
    }
    
    FeatureMap::FeatureMap input(mat, row, col, channel);

    uint kernel_row = 2;
    uint kernel_col = 2;
    uint kernel_channel = 2;
    uint kernel_num = 1;
    float* kernel_data = (float*)malloc(sizeof(float) * kernel_row * kernel_col * kernel_channel * kernel_num);
    memset(kernel_data, 0, sizeof(float) * kernel_row * kernel_col * kernel_channel * kernel_num);

    float* kernel_bias = (float*)malloc(sizeof(float) * kernel_num);
    memset(kernel_bias, 0, sizeof(kernel_bias));
    
    *kernel_data = 1;
    *(kernel_data + 3) = 1;
    *(kernel_data + 4) = 1;
    *(kernel_data + 7) = 1;

    FeatureMap::Kernel kernel(kernel_data, kernel_bias, kernel_row, kernel_col, kernel_channel, kernel_num, 0);

    FeatureMap::FeatureMap output(NULL, 0, 0, 0);
    Layer::Conv(output, input, kernel, 1, 1);

    for(uint i = 0; i < output.row; ++i){
        for(uint j = 0; j < output.col; ++j){
            std::cout << *(output.data + i * output.col + j) << " ";
        }
        std::cout << std::endl;
    }
    
    std::string file_directory = "./Keras/";
    std::string file_name = "layer1_bias.txt";
}