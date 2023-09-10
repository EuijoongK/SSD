#include "model/model.hpp"
#include "datahandler/datahandler.hpp"
#include <iostream>

int main() {
    std::string file_directory = "./Keras/";
    std::string file_name = "layer_info.txt";

    Model::Model model;
    Datahandler::import_model_info(file_directory + file_name, &model);
    model.summary();

    Datahandler::import_kernel("./Keras/layer1.txt", "./Keras/layer1_bias.txt", model.kernel_arr);

    FeatureMap::Kernel* kernel = model.kernel_arr;
    uint i, j, k, l;
    uint sz1 = kernel -> channel * kernel -> row * kernel -> col;
    uint sz2 = kernel -> row * kernel -> col;
    for(i = 0; i < kernel -> num; ++i){
        for(j = 0; j < kernel -> channel; ++j){
            for(k = 0; k < kernel -> row; ++k){
                for(l = 0; l < kernel -> col; ++l){
                    std::cout << *(kernel -> weights + i * sz1 + j * sz2 + k * kernel -> col + l) << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}