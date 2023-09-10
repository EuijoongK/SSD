#ifndef FC_H
#define FC_H

#include "../featuremap/featuremap.hpp"

namespace Layer{
    void Fullyconnected(
        FeatureMap::FeatureMap& output, 
        const FeatureMap::FeatureMap& input, 
        const FeatureMap::Kernel& kernel
    );
}

#endif