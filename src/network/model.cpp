#include "../../include/network/model.hpp"

Network::Network::Network(){
    layer_num = 0;
}

Network::Network::Network(const Network& ref){
    layer_num = ref.layer_num;
    layer_list = ref.layer_list;
    input = ref.input;

    memcpy(kernel_arr, ref.kernel_arr, sizeof(FeatureMap::Kernel) * MAX_LAYER_NUM);
    memcpy(map_arr, ref.map_arr, sizeof(FeatureMap::FeatureMap) * MAX_LAYER_NUM);
}

void Network::Network::add_layer(uint layer_type, const FeatureMap::Kernel& kernel){
    layer_list.push_back(layer_type);
    kernel_arr[++layer_num] = kernel;
}

void Network::Network::run_model_step(){

    FeatureMap::FeatureMap* currnet_featuremap = input;
    FeatureMap::Kernel* current_kernel = kernel_arr;
    FeatureMap::FeatureMap* output = map_arr;

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

Network::Network::~Network(){

}