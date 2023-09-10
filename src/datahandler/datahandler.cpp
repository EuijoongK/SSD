#include "../../include/datahandler/datahandler.hpp"

Datahandler::Datahandler::Datahandler(std::string& _file_format){
    file_format = _file_format;
}

void Datahandler::Datahandler::set_file_format(std::string& _file_format){
    file_format = _file_format;
}

Datahandler::Datahandler::~Datahandler(){

}

namespace Datahandler{

    void import_model_info(
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
                fin >> kernel_num;
                fin >> type;
                if(type == 2){
                    kernel_col = static_cast<uint>(param_num / kernel_num) - 1;
                }
                else{
                    kernel_col =  static_cast<uint>(param_num / kernel_num);
                }
                kernel_row = 1;
                kernel_channel = 1;
            }
            else if(str_token.substr(0, 4) == "conv"){
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
            else if(str_token.substr(0, 11) == "max_pooling"){
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
        fin.close();
    }

    void import_kernel(
        const std::string& weights_name, 
        const std::string& bias_name,
        FeatureMap::Kernel* kernel_ptr
    ){
        std::ifstream fin_weights;
        std::ifstream fin_bias;

        fin_weights.open(weights_name);
        fin_bias.open(bias_name);

        if(!fin_weights || !fin_bias){
            std::cerr << "Error : Unable to open txt format file" << std::endl;
            return;
        }

        uint i, j, k, l;
        uint kernel_row = kernel_ptr -> row;
        uint kernel_col = kernel_ptr -> col;
        uint kernel_channel = kernel_ptr -> channel;
        uint kernel_num = kernel_ptr -> num;
        float* kernel_weights = kernel_ptr -> weights;
        float* kernel_bias = kernel_ptr -> bias;

        uint sz1 = kernel_row * kernel_col * kernel_channel;
        uint sz2 = kernel_row * kernel_col;

        for(i = 0; i < kernel_num; ++i){
            fin_bias >> *(kernel_bias + i);
            for(j = 0; j < kernel_channel; ++j){
                for(k = 0; k < kernel_row; ++k){
                    for(l = 0; l < kernel_col; ++l){
                        fin_weights >> *(kernel_weights + i * sz1 
                            + j * sz2 + k * kernel_col + l);
                    }
                }
            }
        }

        fin_weights.close();
        fin_bias.close();
    }

    void import_model(Network::Network* model_ptr){
        import_model_info("layer_info.txt", model_ptr);
        auto layer_list = model_ptr -> layer_list;

        uint index = 0;
        
    }

}