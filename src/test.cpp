#include "network/model.hpp"
#include "datahandler/datahandler.hpp"
#include <iostream>

int main() {
    std::string file_directory = "./Keras/";
    std::string file_name = "layer_info.txt";

    Network::Network model;
    Datahandler::import_model(file_directory + file_name, &model);

    int index = 0;
    auto layer_list = model.layer_list;
    FeatureMap::Kernel* kernel_ptr = model.kernel_arr;

    for(; index < model.layer_num; ++index){
        auto layer_type = layer_list[index];
        if(layer_type == CONV){
            std::cout << "conv2d" << std::endl;
            std::cout << (kernel_ptr + index) -> row << " ";
            std::cout << (kernel_ptr + index) -> col << " ";
            std::cout << (kernel_ptr + index) -> channel << " ";
            std::cout << (kernel_ptr + index) -> num << " ";
            std::cout << std::endl;
        }
        else if(layer_type == FC){
            std::cout << "dense" << std::endl;
            std::cout << (kernel_ptr + index) -> row << " ";
            std::cout << (kernel_ptr + index) -> col << " ";
            std::cout << (kernel_ptr + index) -> channel << " ";
            std::cout << (kernel_ptr + index) -> num << " ";
            std::cout << std::endl;
        }
        else if(layer_type == MAXPOOLING){
            std::cout << "maxpooling2d" << std::endl;
            std::cout << (kernel_ptr + index) -> row << " ";
            std::cout << (kernel_ptr + index) -> col << " ";
            std::cout << (kernel_ptr + index) -> channel << " ";
            std::cout << (kernel_ptr + index) -> num << " ";
            std::cout << std::endl;
        }
        else if(layer_type == ZEROPADDING){
            std::cout << "zeropadding" << std::endl;
            std::cout << (kernel_ptr + index) -> row << " ";
            std::cout << (kernel_ptr + index) -> col << " ";
            std::cout << (kernel_ptr + index) -> channel << " ";
            std::cout << (kernel_ptr + index) -> num << " ";
            std::cout << std::endl;
        }
        else if(layer_type == FLATTEN){
            std::cout << "flatten" << std::endl;
            std::cout << (kernel_ptr + index) -> row << " ";
            std::cout << (kernel_ptr + index) -> col << " ";
            std::cout << (kernel_ptr + index) -> channel << " ";
            std::cout << (kernel_ptr + index) -> num << " ";
            std::cout << std::endl;
        }
        else if(layer_type == DROPOUT){
            std::cout << "dropout" << std::endl;
        }
    }
}