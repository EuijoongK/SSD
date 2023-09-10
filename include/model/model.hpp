#ifndef NETWORK_H
#define NETWORK_H

#define MAX_LAYER_NUM 10
#define MAX_KERNEL_NUM 10000

#define CONV 1
#define CONV_WITH_RELU 2
#define FC 3
#define MAXPOOLING 4
#define RELU 5
#define SOFTMAX 6
#define ZEROPADDING 7
#define FLATTEN 8
#define DROPOUT 9

#include "../layer/convolution.hpp"
#include "../layer/maxpooling.hpp"
#include "../layer/zeropadding.hpp"
#include "../layer/fc.hpp"
#include "../layer/relu.hpp"
#include "../layer/softmax.hpp"

#include <vector>

namespace Network{
    class Network{
        public:
            uint layer_num;
            std::vector<uint> layer_list;
            FeatureMap::FeatureMap* input = NULL;

            FeatureMap::FeatureMap featuremap_arr[MAX_LAYER_NUM];
            FeatureMap::Kernel kernel_arr[MAX_KERNEL_NUM];

        public:
            Network();
            Network(const Network& ref);

            void add_layer(uint layer_type, const FeatureMap::Kernel& kernel);
            void run_model();
            void summary();
            
            ~Network();
    };
}

#endif