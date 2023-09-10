#include "../model/model.hpp"

#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <fstream>

namespace Datahandler{

    class Datahandler{
        private:
            std::string file_format;
            std::string file_directory;
        public:
            Datahandler();
            Datahandler(const std::string& _file_format);
            void set_file_format(const std::string& _file_format);
            void set_directory(const std::string& _file_directory);

            void import_model_info_to(Model::Model* model_ptr);
            void import_layer_to(Model::Model* model_ptr);
            ~Datahandler();
    };

    void import_model_info(
        const std::string& file_name,
        Model::Model* model_ptr
    );

    void import_kernel(
        const std::string& weights_name, 
        const std::string& bias_name,
        FeatureMap::Kernel* kernel_ptr
    );

}

#endif