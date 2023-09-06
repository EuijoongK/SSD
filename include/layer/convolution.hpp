#ifndef CONVOLUTION_H
#define CONVOLUTION_H
#include "../featuremap/featuremap.hpp"

namespace Layer {
	void calculate_conv_sz(
		const FeatureMap::FeatureMap& input, 
		const FeatureMap::Kernel& kernel, 
		const uint stride_row, 
		const uint stride_col, 
		uint& output_row, 
		uint& output_col
	);

	float patch_conv(
		float* input_address, 
		float* kernel_address, 
		const uint input_row, 
		const uint input_col, 
		const uint kernel_row, 
		const uint kernel_col
	);

	void Conv(
		FeatureMap::FeatureMap& output, 
		const FeatureMap::FeatureMap& input, 
		const FeatureMap::Kernel& kernel, 
		const uint stride_row, 
		const uint stride_col
	);
	
	void Conv_ReLU(
		FeatureMap::FeatureMap& output, 
		const FeatureMap::FeatureMap& input, 
		const FeatureMap::Kernel& kernel, 
		const uint stride_row, 
		const uint stride_col
	);
}

#endif