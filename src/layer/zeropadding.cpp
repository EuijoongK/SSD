#include "../../include/layer/zeropadding.hpp"

namespace Layer {

	void calculate_zeropadding_sz(const FeatureMap::FeatureMap& input, const uint padding_layer, uint& output_row, uint& output_col) {
		output_row = input.row + 2 * padding_layer;
		output_col = input.col + 2 * padding_layer;
		return;
	}

	void Zeropadding(FeatureMap::FeatureMap& output, const FeatureMap::FeatureMap& input, const uint padding_layer){
		uint output_row = 0;
		uint output_col = 0;
		calculate_zeropadding_sz(input, padding_layer, output_row, output_col);
		float* output_data = (float*)malloc(sizeof(float) * output_row * output_col * input.channel);
		
		uint input_sz = input.row * input.col;
		uint output_sz = output_row * output_col;
		
		uint i, j;

		for (i = 0; i < input.channel; ++i) {
			float* input_ptr = input.data + i * input_sz;
			float* output_ptr = output_data + i * output_sz;

			for (j = 0; j < input.row; ++j) {
				memcpy(output_ptr + (j + padding_layer) * output_col + padding_layer, input_ptr + j * input.col, sizeof(float) * input.col);
			}
		}

		output.row = output_row;
		output.col = output_col;
		output.channel = input.channel;
		output.data = output_data;

		return;
	}
}