#include "../../include/core/core.hpp"

#define CORE_DEBUG 1

FeatureMap::FeatureMap::FeatureMap(){
    if(CORE_DEBUG){
        std::cout << "FeatureMap class constructor called" << std::endl;
    }
    data = NULL;
    row = 0;
    col = 0;
    channel = 0;
}

FeatureMap::FeatureMap::FeatureMap(const FeatureMap& ref){
    if(CORE_DEBUG){
        std::cout << "FeatureMap copy constructor called" << std::endl;
    }
    row = ref.row;
    col = ref.col;
    channel = ref.channel;

    data = (float*)malloc(sizeof(float) * row * col * channel);
    memcpy(data, ref.data, sizeof(float) * row * col * channel);
}

FeatureMap::FeatureMap::FeatureMap(float* _data, uint _row, uint _col, uint _channel){
    if(CORE_DEBUG){
        std::cout << "FeatureMap class constructor called" << std::endl;
    }
    data = _data;
    row = _row;
    col = _col;
    channel = _channel;
}

void FeatureMap::FeatureMap::flatten(){
    uint sz = row * col * channel;
    row = sz;
    col = 1;
    channel = 1;
}

FeatureMap::FeatureMap::~FeatureMap(){
    if(CORE_DEBUG){
        std::cout << "FeatureMap class destructor called" << std::endl;
    }
    free(data);
};

FeatureMap::Kernel::Kernel(){
    if(CORE_DEBUG){
        std::cout << "Kernel class constructor called" << std::endl;
    }
    data = NULL;
    row = 0;
    col = 0;
    channel = 0;
    num = 0;
}

FeatureMap::Kernel::Kernel(const Kernel& ref){
    if(CORE_DEBUG){
        std::cout << "Kernel copy constructor called" << std::endl;
    }
    row = ref.row;
    col = ref.col;
    channel = ref.channel;
    num = ref.num;

    data = (float*)malloc(sizeof(float) * row * col * channel * num);
    memcpy(data, ref.data, sizeof(float) * row * col * channel * num);
}

FeatureMap::Kernel::Kernel(float* _data, uint _row, uint _col, uint _channel, uint _num){
    if(CORE_DEBUG){
        std::cout << "Kernel class constructor called" << std::endl;
    }
    data = _data;
    row = _row;
    col = _col;
    channel = _channel;
    num = _num;
}
FeatureMap::Kernel::~Kernel(){
    if(CORE_DEBUG){
        std::cout << "Kernel class destructor called" << std::endl;
    }
    free(data);
};