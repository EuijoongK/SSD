#include "../../include/datahandler/datahandler.hpp"

namespace Datahandler{

    void import_model(
        const std::string& file_name,
        Network::Network* model_ptr
    ){
        std::ifstream fin;
        fin.open(file_name);

        if(!fin){
            std::cerr << "Error : Unable to open " << file_name << std::endl;
            return;
        }

        uint nlayer;
        uint param_num;
        uint kernel_row;
        uint kernel_col;
        uint kernel_channel;
        uint kernel_num;
        uint type;
        uint index = 1;
        FeatureMap::Kernel* kernel_ptr = model_ptr -> kernel_arr;

        std::string str_token;
        
        fin >> nlayer;
        model_ptr -> layer_num = nlayer;

        while(index <= nlayer){
            fin >> str_token;
            if(str_token.substr(0, 5) == "dense"){
                model_ptr -> layer_list.push_back(FC);
                fin >> param_num;
                fin >> kernel_row;
                fin >> type;
                if(type == 2){
                    kernel_col = static_cast<uint>(param_num / kernel_row) - 1;
                }
                else{
                    kernel_col =  static_cast<uint>(param_num / kernel_row);
                }
                kernel_num = 1;
                kernel_channel = 1;
            }
            else if(str_token.substr(0, 6) == "conv2d"){
                model_ptr -> layer_list.push_back(CONV);
                fin >> param_num;
                fin >> kernel_row;
                fin >> kernel_col;
                fin >> kernel_channel;
                fin >> kernel_num;
                fin >> type;
            }
            else if(str_token.substr(0, 7) == "flatten"){
                model_ptr -> layer_list.push_back(FLATTEN);
                fin >> param_num;
                fin >> kernel_col;
                fin >> kernel_row;
                fin >> type;
            }
            else if(str_token.substr(0, 7) == "dropout"){
                model_ptr -> layer_list.push_back(DROPOUT);
                fin >> param_num;
                fin >> kernel_col; 
                fin >> kernel_row;
                fin >> type;
            }
            else if(str_token.substr(0, 13) == "max_pooling2d"){
                model_ptr -> layer_list.push_back(MAXPOOLING);
                fin >> param_num;
                fin >> kernel_num;
                fin >> type;
            }

            if(!type){
                ++kernel_ptr;
                ++index;
                continue;
            }

            kernel_ptr -> row = kernel_row;
            kernel_ptr -> col = kernel_col;
            kernel_ptr -> channel = kernel_channel;
            kernel_ptr -> num = kernel_num;

            kernel_ptr -> weights = (float*)malloc(sizeof(float) * kernel_row * kernel_col 
                * kernel_channel * kernel_num);
            kernel_ptr -> bias = (float*)malloc(sizeof(float) * kernel_num);\
            ++kernel_ptr;
            ++index;
        }
    }

    void import_kernel(
        const std::string& weights_name, 
        const std::string& bias_name,
        FeatureMap::Kernel* kernel_ptr,
        const uint& kernel_num,
        const uint& kernel_channel,
        const uint& kernel_row,
        const uint& kernel_col
    ){
        std::ifstream fin_weights;
        std::ifstream fin_bias;

        if(!fin_weights || !fin_bias){
            std::cerr << "Error : Unable to open txt format file" << std::endl;
            return;
        }

        float float_token;
        uint i, j, k, l;

        
    }

}