#include "../../include/layer/convolution.hpp"

namespace Layer {

	void calculate_conv_sz(const FeatureMap::FeatureMap& input, const FeatureMap::Kernel& kernel, const uint stride_row, const uint stride_col, uint& output_row, uint& output_col){
		output_row = static_cast<uint>(input.row - kernel.row) / stride_row + 1;
		output_col = static_cast<uint>(input.col - kernel.col) / stride_col + 1;
		return;
	}

	float patch_conv(float* input_address, float* kernel_address, const size_t input_row, const size_t input_col, const size_t kernel_row, const size_t kernel_col) {
		float sum = 0;
		for (unsigned i = 0; i < kernel_row; ++i) {
			float* input_row = input_address + i * input_col;
			float* kernel_row = kernel_address + i * kernel_col;
			for (unsigned j = 0; j < kernel_col; ++j) {
				sum += (*(input_row + j)) * (*(kernel_row + j));
			}
		}
		return sum;
	}

	void Conv(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input, const FeatureMap::Kernel& kernel, const uint stride_row, const uint stride_col){
		uint output_row = 0;
		uint output_col = 0;
		calculate_conv_sz(input, kernel, stride_row, stride_col, output_row, output_col);
		float* output_data = (float*)malloc(sizeof(float) * output_row * output_col * kernel.num);

		uint output_sz = output_row * output_col;
		uint input_sz = input.row * input.col;
		uint kernel_sz = kernel.row * kernel.col;

		for(uint k = 0; k < kernel.num; ++k){
			float* output_ptr = output_data + k * output_sz;
			float* kernel_ptr = kernel.data + k * kernel_sz;
			for(uint r = 0; r < output_row; ++r){
				for(uint c = 0; c < output_col; ++c){
					*(output_ptr + r * output_col + c) = patch_conv(input.data + (r * stride_row) * input.col + stride_col * c,
					kernel_ptr, input.row, input.col, kernel.row, kernel.col);
				}
			}
		}

		output.row = output_row;
		output.col = output_col;
		output.channel = kernel.num;
		output.data = output_data;

		return;
	}

	void Conv_ReLU(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input, const FeatureMap::Kernel& kernel, const uint stride_row, const uint stride_col){
		uint output_row = 0;
		uint output_col = 0;
		calculate_conv_sz(input, kernel, stride_row, stride_col, output_row, output_col);
		float* output_data = (float*)malloc(sizeof(float) * output_row * output_col * kernel.num);

		uint output_sz = output_row * output_col;
		uint input_sz = input.row * input.col;
		uint kernel_sz = kernel.row * kernel.col;

		for(uint k = 0; k < kernel.num; ++k){
			float* output_ptr = output_data + k * output_sz;
			float* kernel_ptr = kernel.data + k * kernel_sz;
			for(uint r = 0; r < output_row; ++r){
				for(uint c = 0; c < output_col; ++c){
					float result = patch_conv(input.data + (r * stride_row) * input.col + stride_col * c, kernel_ptr, input.row, input.col, kernel.row, kernel.col);
					if(result < 0){
						*(output_ptr + r * output_col + c) = 0;
					}else{
						*(output_ptr + r * output_col + c) = result;
					}
				}
			}
		}

		output.row = output_row;
		output.col = output_col;
		output.channel = kernel.num;
		output.data = output_data;

		return;
	}
}