#ifndef VGG_H
#define VGG_H

#include "../datahandler/datahandler.h"


struct VGGBase{
    // Input dimension : (300, 300, 3)
    struct Tensor conv1_1_weight[64];
    struct Tensor conv1_1_bias[64];
    struct Tensor conv1_2_weight[64];
    struct Tensor conv1_2_bias[64];
    // Output dimension : (300, 300, 64)

    // Maxpooling : kernel_sz = 2, stride = 2

    // Input dimension : (150, 150, 64)
    struct Tensor conv2_1_weight[128];
    struct Tensor conv2_1_bias[128];
    struct Tensor conv2_2_weight[128];
    struct Tensor conv2_2_bias[128];
    // Output dimension : (150, 150, 128)

    // Maxpooling : kernel_sz = 2, stride = 2

    // Input dimension : (75, 75, 128)
    struct Tensor conv3_1_weight[256];
    struct Tensor conv3_1_bias[256];
    struct Tensor conv3_2_weight[256];
    struct Tensor conv3_2_bias[256];
    struct Tensor conv3_3_weight[256];
    struct Tensor conv3_3_bias[256];
    // Output dimension : (75, 75, 256)

    // Maxpooling : kernel_sz = 2, stride = 2, ceil_mode = True

    // Input dimension : (38, 38, 256)
    struct Tensor conv4_1_weight[512];
    struct Tensor conv4_1_bias[512];
    struct Tensor conv4_2_weight[512];
    struct Tensor conv4_2_bias[512];
    struct Tensor conv4_3_weight[512];
    struct Tensor conv4_3_bias[512];
    // Output dimension : (38, 38, 512)

    // Maxpooling : kernel_sz = 2, stride = 2
    
    // Input dimension : (19, 19, 512)
    struct Tensor conv5_1_weight[512];
    struct Tensor conv5_1_bias[512];
    struct Tensor conv5_2_weight[512];
    struct Tensor conv5_2_bias[512];
    struct Tensor conv5_3_weight[512];
    struct Tensor conv5_3_bias[512];
    // Output dimension : (19, 19, 512)

    // Maxpooling : kernel_sz = 3, stride = 1, padding = 1

    // Input dimension : (19, 19, 512)
    struct Tensor conv6_weight[1024];
    struct Tensor conv6_bias[1024];
    // Output dimension : (19, 19, 1024)

    // Input dimension : (19, 19, 1024)
    struct Tensor conv7_weight[1024];
    struct Tensor conv7_bias[1024];
    // Output dimension : (19, 19, 1024)
};


void vgg_init(struct VGGBase* vggbase);
void vgg_load_param(struct VGGBase* vggbase);
void vgg_destroy(struct VGGBase* vggbase);

struct Tensor* vgg_run(struct VGGBase* vggbase, struct Tensor* input);

#endif