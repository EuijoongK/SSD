#include "../network/model.hpp"

#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <fstream>

namespace Datahandler{

    void import_model_info(
        const std::string& file_name,
        Network::Network* model_ptr
    );

    void import_kernel(
        const std::string& weights_name, 
        const std::string& bias_name,
        FeatureMap::Kernel* kernel_ptr
    );

    void import_layer();
}

#endif