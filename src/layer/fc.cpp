#include "../../include/layer/fc.hpp"

void Layer::Fullyconnected(
    FeatureMap::FeatureMap& output,
    const FeatureMap::FeatureMap& input,
    const FeatureMap::Kernel& kernel
){

    uint i, j, k;

    for(i = 0; i < kernel.num; ++i){
        float sum = 0.0;
        for(j = 0; j < kernel.col; ++j){
            sum += *(input.data + j) * *(kernel.weights + j);
        }
        *(output.data + i) = sum + *(kernel.bias + i);
    }
    
}