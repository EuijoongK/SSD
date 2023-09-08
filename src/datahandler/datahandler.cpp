#include "../../include/datahandler/datahandler.hpp"

namespace Datahandler{

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
    
    /*void get_network_info(const std::string& filename, Network::Network* network_ptr){
        std::ifstream fin;
        fin.open(filename);

        if(!fin){
            std::cerr << "Error : Unable to open " << filename << std::endl;
            return;
        }

        uint int_token;
        std::string str_token;

        uint layer_number;
        fin >> int_token;

        layer_number = int_token;
        network_ptr -> layer_num = int_token;

        uint index = 1;
        FeatureMap::Kernel* kernel_ptr = network_ptr -> kernel_arr;
        while(index <= layer_number){
            fin >> str_token;
            if(str_token.substr(0, 5) == "dense"){

                kernel_ptr -> type == FC;           
                fin >> int_token;
                kernel_ptr -> row = int_token;
                kernel_ptr -> col = 1;
                kernel_ptr -> channel = 1;
                kernel_ptr -> num = 1;

            }else if(str_token.substr(0, 6) == "conv2d"){

                kernel_ptr -> type = CONV;
                fin >> int_token;

            }
            else if(str_token.substr(0, 7) == "flatten"){

            }
            else if(str_token.substr(0, 7) == "dropout"){

            }
            else if(str_token.substr(0, 13) == "max_pooling2d"){

            }
            ++kernel_ptr;
            ++index;
        }
    }*/


}