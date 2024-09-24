#include "../../include/model/vgg.h"

void vgg_init(struct VGGBase* vggbase)
{
    // Initialize conv1
    for(int i = 0; i < 64; ++i){
        vggbase -> conv1_1_weight[i].row        = 3;
        vggbase -> conv1_1_weight[i].col        = 3;
        vggbase -> conv1_1_weight[i].channel    = 3;
        vggbase -> conv1_1_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 3);
        
        vggbase -> conv1_1_bias[i].row          = 1;
        vggbase -> conv1_1_bias[i].col          = 1;
        vggbase -> conv1_1_bias[i].channel      = 1;
        vggbase -> conv1_1_bias[i].data         = (float*)malloc(sizeof(float));

        vggbase -> conv1_2_weight[i].row        = 3;
        vggbase -> conv1_2_weight[i].col        = 3;
        vggbase -> conv1_2_weight[i].channel    = 64;
        vggbase -> conv1_2_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 64);
        
        vggbase -> conv1_2_bias[i].row          = 1;
        vggbase -> conv1_2_bias[i].col          = 1;
        vggbase -> conv1_2_bias[i].channel      = 1;
        vggbase -> conv1_2_bias[i].data         = (float*)malloc(sizeof(float));
    }


    // Initialize conv2
    for(int i = 0; i < 128; ++i){
        vggbase -> conv2_1_weight[i].row        = 3;
        vggbase -> conv2_1_weight[i].col        = 3;
        vggbase -> conv2_1_weight[i].channel    = 64;
        vggbase -> conv2_1_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 64);
        
        vggbase -> conv2_1_bias[i].row          = 1;
        vggbase -> conv2_1_bias[i].col          = 1;
        vggbase -> conv2_1_bias[i].channel      = 1;
        vggbase -> conv2_1_bias[i].data         = (float*)malloc(sizeof(float));

        vggbase -> conv2_2_weight[i].row        = 3;
        vggbase -> conv2_2_weight[i].col        = 3;
        vggbase -> conv2_2_weight[i].channel    = 128;
        vggbase -> conv2_2_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 128);
        
        vggbase -> conv2_2_bias[i].row          = 1;
        vggbase -> conv2_2_bias[i].col          = 1;
        vggbase -> conv2_2_bias[i].channel      = 1;
        vggbase -> conv2_2_bias[i].data         = (float*)malloc(sizeof(float));
    }


    // Initialize conv3
    for(int i = 0; i < 256; ++i){
        vggbase -> conv3_1_weight[i].row        = 3;
        vggbase -> conv3_1_weight[i].col        = 3;
        vggbase -> conv3_1_weight[i].channel    = 128;
        vggbase -> conv3_1_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 128);

        vggbase -> conv3_1_bias[i].row          = 1;
        vggbase -> conv3_1_bias[i].col          = 1;
        vggbase -> conv3_1_bias[i].channel      = 1;
        vggbase -> conv3_1_bias[i].data         = (float*)malloc(sizeof(float));
    
        vggbase -> conv3_2_weight[i].row        = 3;
        vggbase -> conv3_2_weight[i].col        = 3;
        vggbase -> conv3_2_weight[i].channel    = 256;
        vggbase -> conv3_2_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        vggbase -> conv3_2_bias[i].row          = 1;
        vggbase -> conv3_2_bias[i].col          = 1;
        vggbase -> conv3_2_bias[i].channel      = 1;
        vggbase -> conv3_2_bias[i].data         = (float*)malloc(sizeof(float));
 
        vggbase -> conv3_3_weight[i].row        = 3;
        vggbase -> conv3_3_weight[i].col        = 3;
        vggbase -> conv3_3_weight[i].channel    = 256;
        vggbase -> conv3_3_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        vggbase -> conv3_3_bias[i].row          = 1;
        vggbase -> conv3_3_bias[i].col          = 1;
        vggbase -> conv3_3_bias[i].channel      = 1;
        vggbase -> conv3_3_bias[i].data         = (float*)malloc(sizeof(float));
    }


    // Initialize conv4
    for(int i = 0; i < 512; ++i){
        vggbase -> conv4_1_weight[i].row        = 3;
        vggbase -> conv4_1_weight[i].col        = 3;
        vggbase -> conv4_1_weight[i].channel    = 256;
        vggbase -> conv4_1_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        vggbase -> conv4_1_bias[i].row          = 1;
        vggbase -> conv4_1_bias[i].col          = 1;
        vggbase -> conv4_1_bias[i].channel      = 1;
        vggbase -> conv4_1_bias[i].data         = (float*)malloc(sizeof(float));

        vggbase -> conv4_2_weight[i].row        = 3;
        vggbase -> conv4_2_weight[i].col        = 3;
        vggbase -> conv4_2_weight[i].channel    = 512;
        vggbase -> conv4_2_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        vggbase -> conv4_2_bias[i].row          = 1;
        vggbase -> conv4_2_bias[i].col          = 1;
        vggbase -> conv4_2_bias[i].channel      = 1;
        vggbase -> conv4_2_bias[i].data         = (float*)malloc(sizeof(float));

        vggbase -> conv4_3_weight[i].row        = 3;
        vggbase -> conv4_3_weight[i].col        = 3;
        vggbase -> conv4_3_weight[i].channel    = 512;
        vggbase -> conv4_3_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        vggbase -> conv4_3_bias[i].row          = 1;
        vggbase -> conv4_3_bias[i].col          = 1;
        vggbase -> conv4_3_bias[i].channel      = 1;
        vggbase -> conv4_3_bias[i].data         = (float*)malloc(sizeof(float));
    }


    // Initialize conv5
    for(int i = 0; i < 512; ++i){
        vggbase -> conv5_1_weight[i].row        = 3;
        vggbase -> conv5_1_weight[i].col        = 3;
        vggbase -> conv5_1_weight[i].channel    = 512;
        vggbase -> conv5_1_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        vggbase -> conv5_1_bias[i].row          = 1;
        vggbase -> conv5_1_bias[i].col          = 1;
        vggbase -> conv5_1_bias[i].channel      = 1;
        vggbase -> conv5_1_bias[i].data         = (float*)malloc(sizeof(float));

        vggbase -> conv5_2_weight[i].row        = 3;
        vggbase -> conv5_2_weight[i].col        = 3;
        vggbase -> conv5_2_weight[i].channel    = 512;
        vggbase -> conv5_2_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        vggbase -> conv5_2_bias[i].row          = 1;
        vggbase -> conv5_2_bias[i].col          = 1;
        vggbase -> conv5_2_bias[i].channel      = 1;
        vggbase -> conv5_2_bias[i].data         = (float*)malloc(sizeof(float));

        vggbase -> conv5_3_weight[i].row        = 3;
        vggbase -> conv5_3_weight[i].col        = 3;
        vggbase -> conv5_3_weight[i].channel    = 512;
        vggbase -> conv5_3_weight[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        vggbase -> conv5_3_bias[i].row          = 1;
        vggbase -> conv5_3_bias[i].col          = 1;
        vggbase -> conv5_3_bias[i].channel      = 1;
        vggbase -> conv5_3_bias[i].data         = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < 1024; ++i){
        vggbase -> conv6_weight[i].row          = 3;
        vggbase -> conv6_weight[i].col          = 3;
        vggbase -> conv6_weight[i].channel      = 512;
        vggbase -> conv6_weight[i].data         = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        vggbase -> conv6_bias[i].row            = 1;
        vggbase -> conv6_bias[i].col            = 1;
        vggbase -> conv6_bias[i].channel        = 1;
        vggbase -> conv6_bias[i].data           = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < 1024; ++i){
        vggbase -> conv7_weight[i].row          = 3;
        vggbase -> conv7_weight[i].col          = 3;
        vggbase -> conv7_weight[i].channel      = 1024;
        vggbase -> conv7_weight[i].data         = (float*)malloc(sizeof(float) * 3 * 3 * 1024);

        vggbase -> conv7_bias[i].row            = 1;
        vggbase -> conv7_bias[i].col            = 1;
        vggbase -> conv7_bias[i].channel        = 1;
        vggbase -> conv7_bias[i].data           = (float*)malloc(sizeof(float));
    }
}


void vgg_destroy(struct VGGBase* vggbase)
{
    for(int i = 0; i < 64; ++i){
        free(vggbase -> conv1_1_weight[i].data);
        free(vggbase -> conv1_1_bias[i].data);
        free(vggbase -> conv1_2_weight[i].data);
        free(vggbase -> conv1_2_bias[i].data);

        vggbase -> conv1_1_weight[i].data = NULL;
        vggbase -> conv1_1_bias[i].data = NULL;
        vggbase -> conv1_2_weight[i].data = NULL;
        vggbase -> conv1_2_bias[i].data = NULL;
    }

    for(int i = 0; i < 128; ++i){
        free(vggbase -> conv2_1_weight[i].data);
        free(vggbase -> conv2_1_bias[i].data);
        free(vggbase -> conv2_2_weight[i].data);
        free(vggbase -> conv2_2_bias[i].data);

        vggbase -> conv2_1_weight[i].data = NULL;
        vggbase -> conv2_1_bias[i].data = NULL;
        vggbase -> conv2_2_weight[i].data = NULL;
        vggbase -> conv2_2_bias[i].data = NULL;
    }

    for(int i = 0; i < 256; ++i){
        free(vggbase -> conv3_1_weight[i].data);
        free(vggbase -> conv3_1_bias[i].data);
        free(vggbase -> conv3_2_weight[i].data);
        free(vggbase -> conv3_2_bias[i].data);
        free(vggbase -> conv3_3_weight[i].data);
        free(vggbase -> conv3_3_bias[i].data);

        vggbase -> conv3_1_weight[i].data = NULL;
        vggbase -> conv3_1_bias[i].data = NULL;
        vggbase -> conv3_2_weight[i].data = NULL;
        vggbase -> conv3_2_bias[i].data = NULL;
        vggbase -> conv3_3_weight[i].data = NULL;
        vggbase -> conv3_3_bias[i].data = NULL;
    }

    for(int i = 0; i < 512; ++i){
        free(vggbase -> conv4_1_weight[i].data);
        free(vggbase -> conv4_1_bias[i].data);
        free(vggbase -> conv4_2_weight[i].data);
        free(vggbase -> conv4_2_bias[i].data);
        free(vggbase -> conv4_3_weight[i].data);
        free(vggbase -> conv4_3_bias[i].data);

        vggbase -> conv4_1_weight[i].data = NULL;
        vggbase -> conv4_1_bias[i].data = NULL;
        vggbase -> conv4_2_weight[i].data = NULL;
        vggbase -> conv4_2_bias[i].data = NULL;
        vggbase -> conv4_3_weight[i].data = NULL;
        vggbase -> conv4_3_bias[i].data = NULL;
    }

    for(int i = 0; i < 512; ++i){
        free(vggbase -> conv5_1_weight[i].data);
        free(vggbase -> conv5_1_bias[i].data);
        free(vggbase -> conv5_2_weight[i].data);
        free(vggbase -> conv5_2_bias[i].data);
        free(vggbase -> conv5_3_weight[i].data);
        free(vggbase -> conv5_3_bias[i].data);

        vggbase -> conv5_1_weight[i].data = NULL;
        vggbase -> conv5_1_bias[i].data = NULL;
        vggbase -> conv5_2_weight[i].data = NULL;
        vggbase -> conv5_2_bias[i].data = NULL;
        vggbase -> conv5_3_weight[i].data = NULL;
        vggbase -> conv5_3_bias[i].data = NULL;
    }

    for(int i = 0; i < 1024; ++i){
        free(vggbase -> conv6_weight[i].data);
        free(vggbase -> conv6_bias[i].data);

        vggbase -> conv6_weight[i].data = NULL;
        vggbase -> conv6_bias[i].data = NULL;
    }

    for(int i = 0; i < 1024; ++i){
        free(vggbase -> conv7_weight[i].data);
        free(vggbase -> conv7_bias[i].data);

        vggbase -> conv7_weight[i].data = NULL;
        vggbase -> conv7_bias[i].data = NULL;
    }
}


void vgg_load_param(struct VGGBase* vggbase)
{   
    char* conv1_1_weight_path   = "./param/base_conv1_1_weight.bin";
    char* conv1_1_bias_path     = "./param/base_conv1_1_bias.bin";
    char* conv1_2_weight_path   = "./param/base_conv1_2_weight.bin";
    char* conv1_2_bias_path     = "./param/base_conv1_2_bias.bin";

    char* conv2_1_weight_path   = "./param/base_conv2_1_weight.bin";
    char* conv2_1_bias_path     = "./param/base_conv2_1_bias.bin";
    char* conv2_2_weight_path   = "./param/base_conv2_2_weight.bin";
    char* conv2_2_bias_path     = "./param/base_conv2_2_bias.bin";

    char* conv3_1_weight_path   = "./param/base_conv3_1_weight.bin";
    char* conv3_1_bias_path     = "./param/base_conv3_1_bias.bin";
    char* conv3_2_weight_path   = "./param/base_conv3_2_weight.bin";
    char* conv3_2_bias_path     = "./param/base_conv3_2_bias.bin";
    char* conv3_3_weight_path   = "./param/base_conv3_3_weight.bin";
    char* conv3_3_bias_path     = "./param/base_conv3_3_bias.bin";

    char* conv4_1_weight_path   = "./param/base_conv4_1_weight.bin";
    char* conv4_1_bias_path     = "./param/base_conv4_1_bias.bin";
    char* conv4_2_weight_path   = "./param/base_conv4_2_weight.bin";
    char* conv4_2_bias_path     = "./param/base_conv4_2_bias.bin";
    char* conv4_3_weight_path   = "./param/base_conv4_3_weight.bin";
    char* conv4_3_bias_path     = "./param/base_conv4_3_bias.bin";

    char* conv5_1_weight_path   = "./param/base_conv5_1_weight.bin";
    char* conv5_1_bias_path     = "./param/base_conv5_1_bias.bin";
    char* conv5_2_weight_path   = "./param/base_conv5_2_weight.bin";
    char* conv5_2_bias_path     = "./param/base_conv5_2_bias.bin";
    char* conv5_3_weight_path   = "./param/base_conv5_3_weight.bin";
    char* conv5_3_bias_path     = "./param/base_conv5_3_bias.bin";

    char* conv6_weight_path     = "./param/base_conv6_weight.bin";
    char* conv6_bias_path       = "./param/base_conv6_bias.bin";

    char* conv7_weight_path     = "./param/base_conv7_weight.bin";
    char* conv7_bias_path       = "./param/base_conv7_bias.bin";


    import_conv_param(conv1_1_weight_path, vggbase -> conv1_1_weight, 3, 3, 3, 64);
    import_conv_param(conv1_1_bias_path, vggbase -> conv1_1_bias, 1, 1, 1, 64);
    import_conv_param(conv1_2_weight_path, vggbase -> conv1_2_weight, 3, 3, 64, 64);
    import_conv_param(conv1_2_bias_path, vggbase -> conv1_2_bias, 1, 1, 1, 64);

    import_conv_param(conv2_1_weight_path, vggbase -> conv2_1_weight, 3, 3, 64, 128);
    import_conv_param(conv2_1_bias_path, vggbase -> conv2_1_bias, 1, 1, 1, 128);
    import_conv_param(conv2_2_weight_path, vggbase -> conv2_2_weight, 3, 3, 128, 128);
    import_conv_param(conv2_2_bias_path, vggbase -> conv2_2_bias, 1, 1, 1, 128);

    import_conv_param(conv3_1_weight_path, vggbase -> conv3_1_weight, 3, 3, 128, 256);
    import_conv_param(conv3_1_bias_path, vggbase -> conv3_1_bias, 1, 1, 1, 256);
    import_conv_param(conv3_2_weight_path, vggbase -> conv3_2_weight, 3, 3, 256, 256);
    import_conv_param(conv3_2_bias_path, vggbase -> conv3_2_bias, 1, 1, 1, 256);
    import_conv_param(conv3_3_weight_path, vggbase -> conv3_3_weight, 3, 3, 256, 256);
    import_conv_param(conv3_3_bias_path, vggbase -> conv3_3_bias, 1, 1, 1, 256);

    import_conv_param(conv4_1_weight_path, vggbase -> conv4_1_weight, 3, 3, 256, 512);
    import_conv_param(conv4_1_bias_path, vggbase -> conv4_1_bias, 1, 1, 1, 512);
    import_conv_param(conv4_2_weight_path, vggbase -> conv4_2_weight, 3, 3, 512, 512);
    import_conv_param(conv4_2_bias_path, vggbase -> conv4_2_bias, 1, 1, 1, 512);
    import_conv_param(conv4_3_weight_path, vggbase -> conv4_3_weight, 3, 3, 512, 512);
    import_conv_param(conv4_3_bias_path, vggbase -> conv4_3_bias, 1, 1, 1, 512);

    import_conv_param(conv5_1_weight_path, vggbase -> conv5_1_weight, 3, 3, 512, 512);
    import_conv_param(conv5_1_bias_path, vggbase -> conv5_1_bias, 1, 1, 1, 512);
    import_conv_param(conv5_2_weight_path, vggbase -> conv5_2_weight, 3, 3, 512, 512);
    import_conv_param(conv5_2_bias_path, vggbase -> conv5_2_bias, 1, 1, 1, 512);
    import_conv_param(conv5_3_weight_path, vggbase -> conv5_3_weight, 3, 3, 512, 512);
    import_conv_param(conv5_3_bias_path, vggbase -> conv5_3_bias, 1, 1, 1, 512);

    import_conv_param(conv6_weight_path, vggbase -> conv6_weight, 3, 3, 512, 1024);
    import_conv_param(conv6_bias_path, vggbase -> conv6_bias, 1, 1, 1, 1024);

    import_conv_param(conv7_weight_path, vggbase -> conv7_weight, 3, 3, 1024, 1024);
    import_conv_param(conv7_bias_path, vggbase -> conv7_bias, 1, 1, 1, 1024);
}


struct Tensor* vgg_run(struct VGGBase* vggbase, struct Tensor* input)
{
    struct Tensor* output = (struct Tensor*)malloc(sizeof(struct Tensor));
    return output;
}