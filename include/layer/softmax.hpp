#ifndef SOFTMAX_H
#define SOFTMAX_H

#include "../featuremap/featuremap.hpp"

namespace Layer{
    void Softmax(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input);
}

#endif