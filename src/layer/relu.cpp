#include "../../include/layer/relu.hpp"

namespace Layer{
    void Relu(FeatureMap::FeatureMap& input){
        uint input_sz = input.row * input.col;
        for(uint i = 0; i < input.channel; ++i){
            
            float* input_ptr = input.data + i * input_sz;

            for(uint j = 0; j < input.row; ++j){
                for(uint k = 0; k < input.col; ++k){
                    if(*(input_ptr + j * input.col + k) < 0){
                        *(input_ptr + j * input.col + k) = 0;
                    }
                }
            }
        }
    }
}