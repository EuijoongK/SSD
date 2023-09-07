#ifndef NETWORK_H
#define NETWORK_H

#define MAX_LAYER_NUM 10
#define MAX_KERNEL_NUM 10000

#define CONV 1
#define FC 2
#define MAXPOOLING 3
#define RELU 4
#define SOFTMAX 5
#define ZEROPADDING 6

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

            FeatureMap::FeatureMap map_arr[MAX_LAYER_NUM];
            FeatureMap::Kernel kernel_arr[MAX_KERNEL_NUM];

        public:
            Network();
            Network(const Network& ref);

            void add_layer(uint layer_type, const FeatureMap::Kernel& kernel);
            void run_model();

            ~Network();
    };
}

#endif