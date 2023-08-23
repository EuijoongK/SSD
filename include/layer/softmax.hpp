#ifndef SOFTMAX_H
#define SOFTMAX_H

#include "../core/core.hpp"

namespace Layer{
    void Softmax(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input);
}

#endif