#ifndef FC_H
#define FC

#include "../core/core.hpp"

namespace Layer{
    void Fullyconnected(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input, const FeatureMap::Kernel& kernel);
}

#endif