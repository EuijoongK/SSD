#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "../core/core.hpp"

namespace Layer {
	void calculate_conv_sz(const FeatureMap::FeatureMap& input, const FeatureMap::Kernel& kernel, const uint stride_row, const uint stride_col, uint& output_row, uint& output_col);
	float patch_conv(float* input_address, float* kernel_address, const size_t input_row, const size_t input_col, const size_t kernel_row, const size_t kernel_col);
	void Conv(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input, const FeatureMap::Kernel& kernel, const uint stride_row, const uint stride_col);
	void Conv_ReLU(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input, const FeatureMap::Kernel& kernel, const uint stride_row, const uint stride_col);
}

#endif