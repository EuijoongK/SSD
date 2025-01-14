#include "../../include/layer/conv_layer.h"

void calculate_conv_sz(
    const int input_row,
    const int input_col,
    const int kernel_row,
    const int kernel_col,
    const int stride_row,
    const int stride_col,
    const int padding_num,
    const int dilation,
    int* output_row,
    int* output_col
){  
    *output_row = (int)((input_row + 2 * padding_num - dilation * (kernel_row - 1) - 1) / stride_row) + 1;
    *output_col = (int)((input_col + 2 * padding_num - dilation * (kernel_col - 1) - 1) / stride_col) + 1;
    return;
}

// For Data order BHWC
float unit_conv(
    float* input_data,
    float* kernel_data,
    float bias,
    int input_row,
    int input_col,
    int input_channel,
    int kernel_row,
    int kernel_col,
    int dilation,
    int debug
){
    float* input_ptr;
    float* kernel_ptr;
    
    float sum = 0.0;
    float c = 0.0;
    float y = 0.0;
    float t = 0.0;
    float temp = 0.0;

    for(int i = 0; i < kernel_row; ++i){
        for(int j = 0; j < kernel_col; ++j){
            for(int k = 0; k < input_channel; ++k){
                input_ptr = input_data + i * input_col * input_channel * dilation + j * input_channel * dilation + k;
                kernel_ptr = kernel_data + i * kernel_col * input_channel + j * input_channel + k;

                temp = (*input_ptr) * (*kernel_ptr);
                sum += temp;
            }
        }
    }

    return sum + bias;
}

// For Data order BHWC
void conv_builtin(
    struct Tensor* output,              // struct Tensor* output
    struct Tensor* input,               // struct Tensor* input
    struct Tensor* weight,              // struct Tensor conv1_1_weight[64];
    struct Tensor* bias,                // struct Tensor conv1_1_bias[64];
    int stride_row,
    int stride_col,
    int dilation,
    int relu_opt
){
    int in_row              = input -> row;
    int in_col              = input -> col;
    int in_channel          = input -> channel;
    int out_row             = output -> row;
    int out_col             = output -> col;
    int out_channel         = output -> channel;
    int kernel_row          = weight -> row;
    int kernel_col          = weight -> col;
    int kernel_channel      = weight -> channel;

    float* in_data          = input -> data;
    float* out_data         = output -> data;

    float* current_input;
    float* current_output;
    float* current_weight;
    float* current_bias;
    float temp;



    for(int i = 0; i < out_row; ++i){
        for(int j = 0; j < out_col; ++j){
            current_input = in_data + (i * stride_row * in_col + j * stride_col) * in_channel;          // verified 241129 - pointer of input's first channel, start element for convolution

            for(int k = 0; k < out_channel; ++k){
                current_weight = (weight + k) -> data;                                                  // verified 241129 - for all k, fwrite conv1_1_weight.bin and compared with python version
                current_bias = (bias + k) -> data;                                                      // verified 241129 - ""
                current_output = out_data + i * out_col * out_channel + j * out_channel + k;

                int debug = 0;
                temp = unit_conv(current_input, current_weight, *current_bias, in_row, in_col, in_channel, 
                                            kernel_row, kernel_col, dilation, debug);
                if(relu_opt){
                    temp = (temp > 0) ? temp : 0;
                }
                *current_output = temp;
            }
        }
    }
}


struct Tensor* dilation_weight(
    struct Tensor* weight,
    int num_weight,
    int dilation
){
    int row = weight -> row;
    int col = weight -> col;
    int channel = weight -> channel;

    int out_row = dilation * (row - 1) + 1;
    int out_col = dilation * (col - 1) + 1;
    int out_channel = channel;

    struct Tensor* out_weight = (struct Tensor*)malloc(sizeof(struct Tensor) * num_weight);
    // struct Tensor out_weight[1024];
    struct Tensor* current_out;
    struct Tensor* current_in;
    float* src;
    float* dst;

    for(int i = 0; i < num_weight; ++i){
        current_in = weight + i;                    // weight[i]
        current_out = out_weight + i;               // out_weight[i]

        current_out -> row = out_row;
        current_out -> col = out_col;
        current_out -> channel = out_channel;
        current_out -> data = (float*)malloc(sizeof(float) * out_row * out_col * out_channel);
        memset(current_out -> data, 0, sizeof(float) * out_row * out_col * out_channel);
        src = current_in -> data;
        dst = current_out -> data;

        for(int j = 0; j < row; ++j){
            for(int k = 0; k < col; ++k){
                for(int l = 0; l < channel; ++l){
                    *(dst + j * dilation * col * channel + k * dilation * channel + l) = *(src + j * col * channel + k * channel + l);
                }
            }
        }
    }
    return out_weight;
}

struct Tensor* convolution(
    struct Tensor* input,                   // struct Tensor* input
    struct Tensor* weight,                  // struct Tensor conv1_1_weight[64];
    struct Tensor* bias,                    // struct Tensor conv1_1_bias[64];
    int output_channel,
    int stride_row,
    int stride_col,
    int padding_num,
    int dilation,
    int relu_opt
){
    assert(input -> channel == weight -> channel);
    int output_row, output_col;
    calculate_conv_sz(input -> row, input -> col, weight -> row, weight -> col,
                    stride_row, stride_col, padding_num, dilation, &output_row, &output_col);
    
    float* output_data = (float*)malloc(sizeof(float) * output_row * output_col * output_channel);

    struct Tensor* output = (struct Tensor*)malloc(sizeof(struct Tensor));
    output -> row       = output_row;
    output -> col       = output_col;
    output -> channel   = output_channel;
    output -> data      = output_data;

    struct Tensor* buf;
    if(padding_num){
        buf = zeropadd(input, padding_num);
    }else{
        buf = input;
    }
    conv_builtin(output, buf, weight, bias, stride_row, stride_col, dilation, relu_opt);

    if(padding_num){
        destroy_tensor(buf);
    }
    return output;
}
