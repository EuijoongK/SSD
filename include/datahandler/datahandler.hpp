#include "../model/model.hpp"

#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <fstream>

namespace Datahandler{

    class Datahandler{
        public:
            std::string file_format;
        public:
            Datahandler(std::string& _file_format);
            void set_file_format(std::string& _file_format);
            ~Datahandler();
    };

    void import_model_info(
        const std::string& file_name,
        Network::Network* model_ptr
    );

    void import_kernel(
        const std::string& weights_name, 
        const std::string& bias_name,
        FeatureMap::Kernel* kernel_ptr
    );

}

#endif