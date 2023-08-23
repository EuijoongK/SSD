#ifndef MAXPOOLING_H
#define MAXPOOLING_H

#include "../core/core.hpp"

namespace Layer {
    void calculate_maxpooling_sz(const FeatureMap::FeatureMap& input, const uint kernel_row, const uint kernel_col, const uint stride_row, const uint stride_col, uint& output_row, uint& output_col);
    void Maxpooling(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input, const uint kernel_row, const uint kernel_col, const uint stride_row, const uint stride_col);
}

#endif