#include "../../include/layer/flatten.hpp"

void Layer::Flatten(
    FeatureMap::FeatureMap& input
){
    input.flatten();
    return;
}