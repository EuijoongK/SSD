#ifndef NETWORK_H
#define NETWORK_H

#define MAX_LAYER_NUM 5

#define EMPTY 0
#define CONVOLUTION 1
#define MAXPOOLING 2
#define ZEROPADDING 3
#define FLATTEN 4
#define FULLYCONNECTED 5

#include "../layer/convolution.hpp"
#include "../layer/maxpooling.hpp"
#include "../layer/zeropadding.hpp"

#include <vector>

namespace Network{
    class Network{
        public:
            uint layer_num;
            std::vector<uint> layer_list;
            FeatureMap::FeatureMap* input = NULL;

            FeatureMap::Kernel kernel_arr[MAX_LAYER_NUM];
            FeatureMap::FeatureMap map_arr[MAX_LAYER_NUM];

        public:
            Network();
            Network(const Network& ref);
            void run_model_step();
            ~Network();
    };
}

#endif