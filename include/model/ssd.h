#ifndef SSD_H
#define SSD_H

#include "vgg.h"
#include "auxiliary.h"
#include "predict.h"

#define NUM_FMAPS       6
#define MAX_PRIORS      8732

enum label{
    BACKGROUND, AEROPLANE, BICYCLE, BIRD, BOAT, BOTTLE,                     
    BUS, CAR, CAT, CHAIR, COW, DINING_TABLE, DOG,         
    HORSE, MOTORBIKE, PERSON, POTTEDPLANT, SHEEP, SOFA, TRAIN, TVMONITOR
};

struct SSD{
    struct VGGBase* vgg;
    struct Auxiliary* aux;
    struct Predict* pred;
    struct Tensor* rescale_factor;
};

void create_prior_box(float prior[][4]);
void gcxgcy_to_cxcy(float* gcxgcy, float priors_cxcy[][4], float output[][4], int n_priors);
void cxcy_to_xy(float cxcy[][4], float output[][4], int n_boxes);
void nms(float* score, int* suppress, int num_prior, int num_class, float min_score, int top_k);

void SSD_init(struct SSD* ssd);
void SSD_load_param(struct SSD* ssd);
void SSD_destroy(struct SSD* ssd);

struct Tensor** SSD_run(struct SSD* ssd, struct Tensor* input);

#endif