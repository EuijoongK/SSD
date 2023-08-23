#include "../../include/layer/fc.hpp"

void Layer::Fullyconnected(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input, const FeatureMap::Kernel& kernel){
    for(uint i = 0; i < kernel.row; ++i){
        float sum = 0;
        for(uint j =0; j < kernel.col - 1; ++j){
            sum += ((*(input.data + i)) * (*(kernel.data + i * kernel.col + j)));
        }
        *(output.data + i) = sum;
    }
    for(uint i = 0; i < kernel.row; ++i){
        *(output.data + i) += *(kernel.data + kernel.col * i + kernel.col - 1);
    }
}