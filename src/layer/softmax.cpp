#include "../../include/layer/softmax.hpp"

void Layer::Softmax(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input){
    float max_value = *std::max_element(input.data, input.data + input.row);

    float* output_data = (float*)malloc(sizeof(float) * input.row);
    float sum = 0.0, current = 0.0;

    uint i;
    for(i = 0; i < input.row; ++i){
        current = static_cast<float>(exp(*(input.data + i)));
        sum += current;
        *(output_data + i) = current;
    }
    for(i = 0; i < input.row; ++i){
        *(output_data + i) /= sum;
    }

    output.row = input.row;
    output.col = input.col;
    output.channel = input.channel;
    output.data = output_data;
}