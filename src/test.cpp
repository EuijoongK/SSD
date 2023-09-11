#include "model/model.hpp"
#include "datahandler/datahandler.hpp"
#include <iostream>

int main() {
    std::string file_directory = "./Keras";
    std::string file_format = "layer";

    Model::Model model;
    Datahandler::Datahandler dhd;
    dhd.set_directory(file_directory);
    dhd.set_file_format(file_format);

    dhd.import_model_info_to(&model);
    
    model.summary();
}