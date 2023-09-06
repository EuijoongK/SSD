#ifndef ZEROPADDING_H
#define ZEROPADDING_H

#include "../featuremap/featuremap.hpp"

namespace Layer {
    void calculate_zeropadding_sz(
        const FeatureMap::FeatureMap& input, 
        const uint padding_layer, 
        uint& output_row, 
        uint& output_col
    );

    void Zeropadding(
        FeatureMap::FeatureMap& output, 
        const FeatureMap::FeatureMap& input, 
        const uint padding_layer
    );
}

#endif