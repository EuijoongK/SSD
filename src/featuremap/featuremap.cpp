#include "../../include/featuremap/featuremap.hpp"

#define CORE_DEBUG 0

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
    row = 1;
    col = sz;
    channel = 1;
}

void FeatureMap::FeatureMap::summary(){
    uint i, j, k, l;
    uint sz = row * col;

    std::cout << "FeatureMap summary" << std::endl;
    std::cout << "Size : " << row << " x " << col << " x " << channel << std::endl;
    for(i = 0; i < channel; ++i){
        for(j = 0; j < row; ++j){
            for(l = 0; l < col; ++l){
                std::cout << *(data + i * sz + j * col + l) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
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
    weights = NULL;
    bias = NULL;
    row = 0;
    col = 0;
    channel = 0;
    num = 0;
    type = 0;
}

FeatureMap::Kernel::Kernel(const Kernel& ref){
    if(CORE_DEBUG){
        std::cout << "Kernel copy constructor called" << std::endl;
    }
    row = ref.row;
    col = ref.col;
    channel = ref.channel;
    num = ref.num;
    type = ref.type;
    bias = ref.bias;

    weights = (float*)malloc(sizeof(float) * row * col * channel * num);
    memcpy(weights, ref.weights, sizeof(float) * row * col * channel * num);

    bias = (float*)malloc(sizeof(float) * num);
    memcpy(bias, ref.bias, sizeof(float) * num);
}

FeatureMap::Kernel::Kernel(float* _weights, float* _bias, uint _row, uint _col, uint _channel, uint _num, uint _type){
    if(CORE_DEBUG){
        std::cout << "Kernel class constructor called" << std::endl;
    }
    weights = _weights;
    bias = _bias;
    row = _row;
    col = _col;
    channel = _channel;
    num = _num;
    type = _type;
}

void FeatureMap::Kernel::summary(){
    uint i, j, k, l;
    uint sz1 = row * col * channel;
    uint sz2 = row * col;

    std::cout << "Kernel Sumamry" << std::endl;
    std::cout << "Size : " << row << " x " << col << " x " << channel << " x " << num << std::endl;
    for(i = 0; i < num; ++i){
        std::cout << "K " << i + 1 << std::endl;
        for(j = 0; j < channel; ++j){
            for(k = 0; k < row; ++k){
                for(l = 0; l < col; ++l){
                    std::cout << *(weights + i * sz1 + j * sz2 + k * col + l) << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

FeatureMap::Kernel::~Kernel(){
    if(CORE_DEBUG){
        std::cout << "Kernel class destructor called" << std::endl;
    }
    free(weights);
    free(bias);
};