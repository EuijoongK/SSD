#include "../../include/layer/fc.hpp"

void Layer::Fullyconnected(
    FeatureMap::FeatureMap& output,
    const FeatureMap::FeatureMap& input,
    const FeatureMap::Kernel& kernel
){

    uint i, j;

    for(i = 0; i < kernel.row; ++i){
        float sum = 0.0;
        for(j =0; j < kernel.col - 1; ++j){
            sum += ((*(input.data + i)) * (*(kernel.data + i * kernel.col + j)));
        }
    }
    for(i = 0; i < kernel.row; ++i){
        *(output.data + i) += *(kernel.data + kernel.col * i + kernel.col - 1);
    }
}