#include "../../include/network/model.hpp"

Network::Network::Network(){
    layer_num = 0;
    layer_index = 0;
    kernel_index = 0;
    current = &map_arr[layer_index];
}

Network::Network::Network(const Network& ref){
    //working process
}


void Network::Network::run_model_step(){
    if(layer_index == layer_num){
        return;
    }
    
}

Network::Network::~Network(){

}