#include "../../include/model/model.hpp"

Model::Model::Model(){
    layer_num = 0;
    layer_list.clear();
}

Model::Model::Model(const Model& ref){
    layer_num = ref.layer_num;
    layer_list = ref.layer_list;
    input = ref.input;

    memcpy(kernel_arr, ref.kernel_arr, sizeof(FeatureMap::Kernel) * MAX_KERNEL_NUM);
    memcpy(featuremap_arr, ref.featuremap_arr, sizeof(FeatureMap::FeatureMap) * MAX_LAYER_NUM);
}

void Model::Model::add_layer(uint layer_type, const FeatureMap::Kernel& kernel){
    layer_list.push_back(layer_type);
    *(kernel_arr + layer_num) = kernel;
    ++layer_num;
}

void Model::Model::run_model(){
    
    FeatureMap::FeatureMap* currnet_featuremap = input;
    FeatureMap::Kernel* current_kernel = kernel_arr;
    FeatureMap::FeatureMap* output = featuremap_arr;

    for(auto layer_type : layer_list){
        if(layer_type == CONV){
            
        }
        else if(layer_type == FC){

        }
        else if(layer_type == MAXPOOLING){

        }
        else if(layer_type == RELU){

        }
        else if(layer_type == SOFTMAX){

        }
        else if(layer_type == ZEROPADDING){

        }
    }
}

void Model::Model::summary(){
    uint index = 0;
    FeatureMap::Kernel* kernel_ptr = kernel_arr;

    std::cout << "Model" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Layer(type)          Kernel shape           Param #" << std::endl;
    std::cout << "===================================================" << std::endl;
    for(; index < layer_num; ++index){

        auto layer_type = layer_list[index];
        if(layer_type == CONV){
            std::cout << "conv                 ";
        }
        else if(layer_type == FC){
            std::cout << "dense                ";
        }
        else if(layer_type == MAXPOOLING){
            std::cout << "maxpooling" << std::endl;
        }
        else if(layer_type == ZEROPADDING){
            std::cout << "zeropadding" << std::endl;
        }
        else if(layer_type == FLATTEN){
            std::cout << "flatten" << std::endl;
        }
        else if(layer_type == DROPOUT){
            std::cout << "dropout" << std::endl;
        }
        if(layer_type == CONV || layer_type == FC){
            std::cout << "(";
            std::cout << (kernel_ptr + index) -> row << ", ";
            std::cout << (kernel_ptr + index) -> col << ", ";
            std::cout << (kernel_ptr + index) -> channel << ", ";
            std::cout << (kernel_ptr + index) -> num << ")";
            std::cout << std::endl;
        }
    }
}

Model::Model::~Model(){

}