#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "../datahandler/datahandler.h"
#include "../layer/layer.h"

struct Auxiliary{
    struct Tensor conv8_1_weight[256];
    struct Tensor conv8_1_bias[256];
    struct Tensor conv8_2_weight[512];
    struct Tensor conv8_2_bias[512];

    struct Tensor conv9_1_weight[128];
    struct Tensor conv9_1_bias[128];
    struct Tensor conv9_2_weight[256];
    struct Tensor conv9_2_bias[256];

    struct Tensor conv10_1_weight[128];
    struct Tensor conv10_1_bias[128];
    struct Tensor conv10_2_weight[256];
    struct Tensor conv10_2_bias[256];

    struct Tensor conv11_1_weight[128];
    struct Tensor conv11_1_bias[128];
    struct Tensor conv11_2_weight[256];
    struct Tensor conv11_2_bias[256];  
};


void auxiliary_init(struct Auxiliary* aux);
void auxiliary_load_param(struct Auxiliary* aux);
void auxiliary_destroy(struct Auxiliary* aux);

struct Tensor** auxilairy_run(struct Auxiliary* aux, struct Tensor* input);

#endif