#include "../../include/layer/maxpooling.hpp"

namespace Layer {

	void calculate_maxpooling_sz(
		const FeatureMap::FeatureMap& input, 
		const uint kernel_row, 
		const uint kernel_col, 
		const uint stride_row, 
		const uint stride_col, 
		uint& output_row, uint& output_col
	) {
		output_row = static_cast<uint>((input.row - kernel_row) / stride_row) + 1;
		output_col = static_cast<uint>((input.col - kernel_col) / stride_col) + 1;
		return;
	}
	
	void Maxpooling(
		FeatureMap::FeatureMap& output, 
		const FeatureMap::FeatureMap& input, 
		const uint kernel_row, 
		const uint kernel_col, 
		const uint stride_row, 
		const uint stride_col
	){
		uint output_row = 0;
		uint output_col = 0;
		calculate_maxpooling_sz(input, kernel_row, kernel_col, stride_row, stride_col, output_row, output_col);
		float* output_data = (float*)malloc(sizeof(float) * output_row * output_col * input.channel);
		float* value_arr = (float*)malloc(sizeof(float) * kernel_row * kernel_col);

		uint input_sz = input.row * input.col;
		uint output_sz = output_row * output_col;

		for (uint i = 0; i < input.channel; ++i) {
			float* input_ptr = input.data + i * input_sz;
			float* output_ptr = output_data + i * output_sz;

			for (uint j = 0; j < output_row; ++j) {
				for (uint k = 0; k < output_col; ++k) {
					for (uint l = 0; l < kernel_row; ++l) {
						memcpy(value_arr + l * kernel_col, input_ptr + (j * stride_row + l) * input.col + k * stride_col, sizeof(float) * kernel_col);
					}
					*(output_ptr + j * output_col + k) = *std::max_element(value_arr, value_arr + kernel_row * kernel_col);
				}
			}
		}
		free(value_arr);

		output.row = output_row;
		output.col = output_col;
		output.channel = input.channel;
		output.data = output_data;

		return;
	}
}