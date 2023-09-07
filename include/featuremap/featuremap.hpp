#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <algorithm>

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
            ~FeatureMap();
    };

    class Kernel{
        public:
            float* data;
            uint row;
            uint col;
            uint channel;
            uint num;
            uint type;
            float bias;
        public:
            Kernel();
            Kernel(const Kernel& ref);
            Kernel(float* data, uint _row, uint _col, uint _channel, uint _num, uint _type, float _bias);
            ~Kernel();
    };
}

#endif