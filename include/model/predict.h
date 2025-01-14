#ifndef PREDICT_H
#define PREDICT_H

#include "../datahandler/datahandler.h"
#include "../layer/layer.h"

#define N_BOX_CONV4_3       4
#define N_BOX_CONV7         6
#define N_BOX_CONV8_2       6
#define N_BOX_CONV9_2       6
#define N_BOX_CONV10_2      4
#define N_BOX_CONV11_2      4

#define N_CLASS             21


struct Predict{
    struct Tensor loc_conv4_3_weight[N_BOX_CONV4_3 * 4];
    struct Tensor loc_conv4_3_bias[N_BOX_CONV4_3 * 4];

    struct Tensor loc_conv7_weight[N_BOX_CONV7 * 4];
    struct Tensor loc_conv7_bias[N_BOX_CONV7 * 4];

    struct Tensor loc_conv8_2_weight[N_BOX_CONV8_2 * 4];
    struct Tensor loc_conv8_2_bias[N_BOX_CONV8_2 * 4];

    struct Tensor loc_conv9_2_weight[N_BOX_CONV9_2 * 4];
    struct Tensor loc_conv9_2_bias[N_BOX_CONV9_2 * 4];

    struct Tensor loc_conv10_2_weight[N_BOX_CONV10_2 * 4];
    struct Tensor loc_conv10_2_bias[N_BOX_CONV10_2 * 4];

    struct Tensor loc_conv11_2_weight[N_BOX_CONV11_2 * 4];
    struct Tensor loc_conv11_2_bias[N_BOX_CONV11_2 * 4];



    struct Tensor cl_conv4_3_weight[N_BOX_CONV4_3 * N_CLASS];
    struct Tensor cl_conv4_3_bias[N_BOX_CONV4_3 * N_CLASS];

    struct Tensor cl_conv7_weight[N_BOX_CONV7 * N_CLASS];
    struct Tensor cl_conv7_bias[N_BOX_CONV7 * N_CLASS];

    struct Tensor cl_conv8_2_weight[N_BOX_CONV8_2 * N_CLASS];
    struct Tensor cl_conv8_2_bias[N_BOX_CONV8_2 * N_CLASS];

    struct Tensor cl_conv9_2_weight[N_BOX_CONV9_2 * N_CLASS];
    struct Tensor cl_conv9_2_bias[N_BOX_CONV9_2 * N_CLASS];

    struct Tensor cl_conv10_2_weight[N_BOX_CONV10_2 * N_CLASS];
    struct Tensor cl_conv10_2_bias[N_BOX_CONV10_2 * N_CLASS];

    struct Tensor cl_conv11_2_weight[N_BOX_CONV11_2 * N_CLASS];
    struct Tensor cl_conv11_2_bias[N_BOX_CONV11_2 * N_CLASS];
};


void pred_init(struct Predict* pred);
void pred_load_param(struct Predict* pred);
void pred_destroy(struct Predict* pred);

struct Tensor** predict_run(struct Predict* predict, struct Tensor** input);

#endif