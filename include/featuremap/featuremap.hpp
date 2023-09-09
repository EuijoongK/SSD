#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <algorithm>

#define FC_KERNEL 1
#define CONV_KERNEL 2

namespace FeatureMap{
    
    class FeatureMap{
        public:
            float* data;
            uint row;
            uint col;
            uint channel;
        public:
            FeatureMap();
            FeatureMap(const FeatureMap& ref);
            FeatureMap(float* _data, uint _row, uint _col, uint _channel);
            void flatten();
            void summary();
            ~FeatureMap();
    };

    class Kernel{
        public:
            float* weights;
            float* bias;
            uint row;
            uint col;
            uint channel;
            uint num;
            uint type;
        public:
            Kernel();
            Kernel(const Kernel& ref);
            Kernel(float* _weights, float* _bias, uint _row, uint _col, uint _channel, uint _num, uint _type);
            void summary();
            ~Kernel();
    };
}

#endif