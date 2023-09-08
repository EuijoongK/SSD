#include "../network/model.hpp"

#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <fstream>

namespace Datahandler{
    void import_model(
        const std::string& file_name,
        Network::Network* model_ptr
    );
}

#endif