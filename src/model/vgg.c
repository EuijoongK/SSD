#include "../../include/model/vgg.h"

void vgg_init(struct VGGBase* vggbase)
{
    // Initialize conv1
    for(int i = 0; i < 64; ++i){
        (vggbase -> conv1_1_weight)[i].row        = 3;
        (vggbase -> conv1_1_weight)[i].col        = 3;
        (vggbase -> conv1_1_weight)[i].channel    = 3;
        (vggbase -> conv1_1_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 3);
        
        (vggbase -> conv1_1_bias)[i].row          = 1;
        (vggbase -> conv1_1_bias)[i].col          = 1;
        (vggbase -> conv1_1_bias)[i].channel      = 1;
        (vggbase -> conv1_1_bias)[i].data         = (float*)malloc(sizeof(float));

        (vggbase -> conv1_2_weight)[i].row        = 3;
        (vggbase -> conv1_2_weight)[i].col        = 3;
        (vggbase -> conv1_2_weight)[i].channel    = 64;
        (vggbase -> conv1_2_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 64);
        
        (vggbase -> conv1_2_bias)[i].row          = 1;
        (vggbase -> conv1_2_bias)[i].col          = 1;
        (vggbase -> conv1_2_bias)[i].channel      = 1;
        (vggbase -> conv1_2_bias)[i].data         = (float*)malloc(sizeof(float));
    }


    // Initialize conv2
    for(int i = 0; i < 128; ++i){
        (vggbase -> conv2_1_weight)[i].row        = 3;
        (vggbase -> conv2_1_weight)[i].col        = 3;
        (vggbase -> conv2_1_weight)[i].channel    = 64;
        (vggbase -> conv2_1_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 64);
        
        (vggbase -> conv2_1_bias)[i].row          = 1;
        (vggbase -> conv2_1_bias)[i].col          = 1;
        (vggbase -> conv2_1_bias)[i].channel      = 1;
        (vggbase -> conv2_1_bias)[i].data         = (float*)malloc(sizeof(float));

        (vggbase -> conv2_2_weight)[i].row        = 3;
        (vggbase -> conv2_2_weight)[i].col        = 3;
        (vggbase -> conv2_2_weight)[i].channel    = 128;
        (vggbase -> conv2_2_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 128);
        
        (vggbase -> conv2_2_bias)[i].row          = 1;
        (vggbase -> conv2_2_bias)[i].col          = 1;
        (vggbase -> conv2_2_bias)[i].channel      = 1;
        (vggbase -> conv2_2_bias)[i].data         = (float*)malloc(sizeof(float));
    }


    // Initialize conv3
    for(int i = 0; i < 256; ++i){
        (vggbase -> conv3_1_weight)[i].row        = 3;
        (vggbase -> conv3_1_weight)[i].col        = 3;
        (vggbase -> conv3_1_weight)[i].channel    = 128;
        (vggbase -> conv3_1_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 128);

        (vggbase -> conv3_1_bias)[i].row          = 1;
        (vggbase -> conv3_1_bias)[i].col          = 1;
        (vggbase -> conv3_1_bias)[i].channel      = 1;
        (vggbase -> conv3_1_bias)[i].data         = (float*)malloc(sizeof(float));
    
        (vggbase -> conv3_2_weight)[i].row        = 3;
        (vggbase -> conv3_2_weight)[i].col        = 3;
        (vggbase -> conv3_2_weight)[i].channel    = 256;
        (vggbase -> conv3_2_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (vggbase -> conv3_2_bias)[i].row          = 1;
        (vggbase -> conv3_2_bias)[i].col          = 1;
        (vggbase -> conv3_2_bias)[i].channel      = 1;
        (vggbase -> conv3_2_bias)[i].data         = (float*)malloc(sizeof(float));
 
        (vggbase -> conv3_3_weight)[i].row        = 3;
        (vggbase -> conv3_3_weight)[i].col        = 3;
        (vggbase -> conv3_3_weight)[i].channel    = 256;
        (vggbase -> conv3_3_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (vggbase -> conv3_3_bias)[i].row          = 1;
        (vggbase -> conv3_3_bias)[i].col          = 1;
        (vggbase -> conv3_3_bias)[i].channel      = 1;
        (vggbase -> conv3_3_bias)[i].data         = (float*)malloc(sizeof(float));
    }


    // Initialize conv4
    for(int i = 0; i < 512; ++i){
        (vggbase -> conv4_1_weight)[i].row        = 3;
        (vggbase -> conv4_1_weight)[i].col        = 3;
        (vggbase -> conv4_1_weight)[i].channel    = 256;
        (vggbase -> conv4_1_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 256);

        (vggbase -> conv4_1_bias)[i].row          = 1;
        (vggbase -> conv4_1_bias)[i].col          = 1;
        (vggbase -> conv4_1_bias)[i].channel      = 1;
        (vggbase -> conv4_1_bias)[i].data         = (float*)malloc(sizeof(float));

        (vggbase -> conv4_2_weight)[i].row        = 3;
        (vggbase -> conv4_2_weight)[i].col        = 3;
        (vggbase -> conv4_2_weight)[i].channel    = 512;
        (vggbase -> conv4_2_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (vggbase -> conv4_2_bias)[i].row          = 1;
        (vggbase -> conv4_2_bias)[i].col          = 1;
        (vggbase -> conv4_2_bias)[i].channel      = 1;
        (vggbase -> conv4_2_bias)[i].data         = (float*)malloc(sizeof(float));

        (vggbase -> conv4_3_weight)[i].row        = 3;
        (vggbase -> conv4_3_weight)[i].col        = 3;
        (vggbase -> conv4_3_weight)[i].channel    = 512;
        (vggbase -> conv4_3_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (vggbase -> conv4_3_bias)[i].row          = 1;
        (vggbase -> conv4_3_bias)[i].col          = 1;
        (vggbase -> conv4_3_bias)[i].channel      = 1;
        (vggbase -> conv4_3_bias)[i].data         = (float*)malloc(sizeof(float));
    }


    // Initialize conv5
    for(int i = 0; i < 512; ++i){
        (vggbase -> conv5_1_weight)[i].row        = 3;
        (vggbase -> conv5_1_weight)[i].col        = 3;
        (vggbase -> conv5_1_weight)[i].channel    = 512;
        (vggbase -> conv5_1_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (vggbase -> conv5_1_bias)[i].row          = 1;
        (vggbase -> conv5_1_bias)[i].col          = 1;
        (vggbase -> conv5_1_bias)[i].channel      = 1;
        (vggbase -> conv5_1_bias)[i].data         = (float*)malloc(sizeof(float));

        (vggbase -> conv5_2_weight)[i].row        = 3;
        (vggbase -> conv5_2_weight)[i].col        = 3;
        (vggbase -> conv5_2_weight)[i].channel    = 512;
        (vggbase -> conv5_2_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (vggbase -> conv5_2_bias)[i].row          = 1;
        (vggbase -> conv5_2_bias)[i].col          = 1;
        (vggbase -> conv5_2_bias)[i].channel      = 1;
        (vggbase -> conv5_2_bias)[i].data         = (float*)malloc(sizeof(float));

        (vggbase -> conv5_3_weight)[i].row        = 3;
        (vggbase -> conv5_3_weight)[i].col        = 3;
        (vggbase -> conv5_3_weight)[i].channel    = 512;
        (vggbase -> conv5_3_weight)[i].data       = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (vggbase -> conv5_3_bias)[i].row          = 1;
        (vggbase -> conv5_3_bias)[i].col          = 1;
        (vggbase -> conv5_3_bias)[i].channel      = 1;
        (vggbase -> conv5_3_bias)[i].data         = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < 1024; ++i){
        (vggbase -> conv6_weight)[i].row          = 3;
        (vggbase -> conv6_weight)[i].col          = 3;
        (vggbase -> conv6_weight)[i].channel      = 512;
        (vggbase -> conv6_weight)[i].data         = (float*)malloc(sizeof(float) * 3 * 3 * 512);

        (vggbase -> conv6_bias)[i].row            = 1;
        (vggbase -> conv6_bias)[i].col            = 1;
        (vggbase -> conv6_bias)[i].channel        = 1;
        (vggbase -> conv6_bias)[i].data           = (float*)malloc(sizeof(float));
    }

    for(int i = 0; i < 1024; ++i){
        (vggbase -> conv7_weight)[i].row          = 1;
        (vggbase -> conv7_weight)[i].col          = 1;
        (vggbase -> conv7_weight)[i].channel      = 1024;
        (vggbase -> conv7_weight)[i].data         = (float*)malloc(sizeof(float) * 1 * 1 * 1024);

        (vggbase -> conv7_bias)[i].row            = 1;
        (vggbase -> conv7_bias)[i].col            = 1;
        (vggbase -> conv7_bias)[i].channel        = 1;
        (vggbase -> conv7_bias)[i].data           = (float*)malloc(sizeof(float));
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


    import_conv_weight(conv1_1_weight_path, vggbase -> conv1_1_weight, 3, 3, 3, 64);
    import_conv_bias(conv1_1_bias_path, vggbase -> conv1_1_bias, 1, 1, 1, 64);
    import_conv_weight(conv1_2_weight_path, vggbase -> conv1_2_weight, 3, 3, 64, 64);
    import_conv_bias(conv1_2_bias_path, vggbase -> conv1_2_bias, 1, 1, 1, 64);

    import_conv_weight(conv2_1_weight_path, vggbase -> conv2_1_weight, 3, 3, 64, 128);
    import_conv_bias(conv2_1_bias_path, vggbase -> conv2_1_bias, 1, 1, 1, 128);
    import_conv_weight(conv2_2_weight_path, vggbase -> conv2_2_weight, 3, 3, 128, 128);
    import_conv_bias(conv2_2_bias_path, vggbase -> conv2_2_bias, 1, 1, 1, 128);

    import_conv_weight(conv3_1_weight_path, vggbase -> conv3_1_weight, 3, 3, 128, 256);
    import_conv_bias(conv3_1_bias_path, vggbase -> conv3_1_bias, 1, 1, 1, 256);
    import_conv_weight(conv3_2_weight_path, vggbase -> conv3_2_weight, 3, 3, 256, 256);
    import_conv_bias(conv3_2_bias_path, vggbase -> conv3_2_bias, 1, 1, 1, 256);
    import_conv_weight(conv3_3_weight_path, vggbase -> conv3_3_weight, 3, 3, 256, 256);
    import_conv_bias(conv3_3_bias_path, vggbase -> conv3_3_bias, 1, 1, 1, 256);

    import_conv_weight(conv4_1_weight_path, vggbase -> conv4_1_weight, 3, 3, 256, 512);
    import_conv_bias(conv4_1_bias_path, vggbase -> conv4_1_bias, 1, 1, 1, 512);
    import_conv_weight(conv4_2_weight_path, vggbase -> conv4_2_weight, 3, 3, 512, 512);
    import_conv_bias(conv4_2_bias_path, vggbase -> conv4_2_bias, 1, 1, 1, 512);
    import_conv_weight(conv4_3_weight_path, vggbase -> conv4_3_weight, 3, 3, 512, 512);
    import_conv_bias(conv4_3_bias_path, vggbase -> conv4_3_bias, 1, 1, 1, 512);

    import_conv_weight(conv5_1_weight_path, vggbase -> conv5_1_weight, 3, 3, 512, 512);
    import_conv_bias(conv5_1_bias_path, vggbase -> conv5_1_bias, 1, 1, 1, 512);
    import_conv_weight(conv5_2_weight_path, vggbase -> conv5_2_weight, 3, 3, 512, 512);
    import_conv_bias(conv5_2_bias_path, vggbase -> conv5_2_bias, 1, 1, 1, 512);
    import_conv_weight(conv5_3_weight_path, vggbase -> conv5_3_weight, 3, 3, 512, 512);
    import_conv_bias(conv5_3_bias_path, vggbase -> conv5_3_bias, 1, 1, 1, 512);

    import_conv_weight(conv6_weight_path, vggbase -> conv6_weight, 3, 3, 512, 1024);
    import_conv_bias(conv6_bias_path, vggbase -> conv6_bias, 1, 1, 1, 1024);

    import_conv_weight(conv7_weight_path, vggbase -> conv7_weight, 1, 1, 1024, 1024);
    import_conv_bias(conv7_bias_path, vggbase -> conv7_bias, 1, 1, 1, 1024);
}


struct Tensor** vgg_run(struct VGGBase* vggbase, struct Tensor* input)
{   
    struct Tensor** output = (struct Tensor**)malloc(sizeof(struct Tensor*) * 2);
    // Convolution layer1
    // printf("Conv1_1\n");
    struct Tensor* out_conv1_1 = convolution(input, vggbase -> conv1_1_weight, vggbase -> conv1_1_bias, 64, 1, 1, 1, 1, 1);
    destroy_tensor(input);
    // printf("Conv1_2\n");
    struct Tensor* out_conv1_2 = convolution(out_conv1_1, vggbase -> conv1_2_weight, vggbase -> conv1_2_bias, 64, 1, 1, 1, 1, 1);
    destroy_tensor(out_conv1_1);
    // printf("Maxpooling1\n");
    struct Tensor* maxpool1 = maxpool(out_conv1_2, 2, 2, 2, 2, 0);
    destroy_tensor(out_conv1_2);
    // printf("%d %d %d\n", maxpool1 -> row, maxpool1 -> col, maxpool1 -> channel);
    
    // Convolution layer2
    // printf("Conv2_1\n");
    struct Tensor* out_conv2_1 = convolution(maxpool1, vggbase -> conv2_1_weight, vggbase -> conv2_1_bias, 128, 1, 1, 1, 1, 1);
    destroy_tensor(maxpool1);
    // printf("Conv2_2\n");
    struct Tensor* out_conv2_2 = convolution(out_conv2_1, vggbase -> conv2_2_weight, vggbase -> conv2_2_bias, 128, 1, 1, 1, 1, 1);
    destroy_tensor(out_conv2_1);
    // printf("Maxpooling2\n");
    struct Tensor* maxpool2 = maxpool(out_conv2_2, 2, 2, 2, 2, 0);
    destroy_tensor(out_conv2_2);
    // printf("%d %d %d\n", maxpool2 -> row, maxpool2 -> col, maxpool2 -> channel);

    // Convolution layer3
    // printf("Conv3_1\n");
    struct Tensor* out_conv3_1 = convolution(maxpool2, vggbase -> conv3_1_weight, vggbase -> conv3_1_bias, 256, 1, 1, 1, 1, 1);
    destroy_tensor(maxpool2);
    // printf("Conv3_2\n");
    struct Tensor* out_conv3_2 = convolution(out_conv3_1, vggbase -> conv3_2_weight, vggbase -> conv3_2_bias, 256, 1, 1, 1, 1, 1);
    destroy_tensor(out_conv3_1);
    // printf("Conv3_3\n");
    struct Tensor* out_conv3_3 = convolution(out_conv3_2, vggbase -> conv3_3_weight, vggbase -> conv3_3_bias, 256, 1, 1, 1, 1, 1);
    destroy_tensor(out_conv3_2);
    // printf("%d %d %d\n", out_conv3_3 -> row, out_conv3_3 -> col, out_conv3_3 -> channel);
    // printf("Maxpooling3\n");                                                                                                                            // ceiling_mode = true
    struct Tensor* maxpool3 = maxpool(out_conv3_3, 2, 2, 2, 2, 1);
    destroy_tensor(out_conv3_3);
    // printf("%d %d %d\n", maxpool3 -> row, maxpool3 -> col, maxpool3 -> channel);

    // Convolution layer4
    // printf("Conv4_1\n");
    struct Tensor* out_conv4_1 = convolution(maxpool3, vggbase -> conv4_1_weight, vggbase -> conv4_1_bias, 512, 1, 1, 1, 1, 1);
    destroy_tensor(maxpool3);
    // printf("Conv4_2\n");
    struct Tensor* out_conv4_2 = convolution(out_conv4_1, vggbase -> conv4_2_weight, vggbase -> conv4_2_bias, 512, 1, 1, 1, 1, 1);
    destroy_tensor(out_conv4_1);
    // printf("Conv4_3\n");
    struct Tensor* out_conv4_3 = convolution(out_conv4_2, vggbase -> conv4_3_weight, vggbase -> conv4_3_bias, 512, 1, 1, 1, 1, 1);
    destroy_tensor(out_conv4_2);
    output[0] = out_conv4_3;

    // printf("Maxpooling4\n");
    struct Tensor* maxpool4 = maxpool(out_conv4_3, 2, 2, 2, 2, 0);
    // destroy_tensor(out_conv4_3);
    

    // Convolution layer5
    // printf("Conv5_1\n");
    struct Tensor* out_conv5_1 = convolution(maxpool4, vggbase -> conv5_1_weight, vggbase -> conv5_1_bias, 512, 1, 1, 1, 1, 1);
    destroy_tensor(maxpool4);
    // printf("Conv5_2\n");
    struct Tensor* out_conv5_2 = convolution(out_conv5_1, vggbase -> conv5_2_weight, vggbase -> conv5_2_bias, 512, 1, 1, 1, 1, 1);
    destroy_tensor(out_conv5_1);
    // printf("Conv5_3\n");
    struct Tensor* out_conv5_3 = convolution(out_conv5_2, vggbase -> conv5_3_weight, vggbase -> conv5_3_bias, 512, 1, 1, 1, 1, 1);
    destroy_tensor(out_conv5_2);
    // printf("Maxpooling5\n");

    struct Tensor* temp = zeropadd(out_conv5_3, 1);
    destroy_tensor(out_conv5_3);

    struct Tensor* maxpool5 = maxpool(temp, 3, 3, 1, 1, 0);
    destroy_tensor(temp);
    
    // Convolution layer6
    // printf("Conv6\n");
    struct Tensor* out_conv6 = convolution(maxpool5, vggbase -> conv6_weight, vggbase -> conv6_bias, 1024, 1, 1, 6, 6, 1);
    destroy_tensor(maxpool5);

    // Convolution layer7
    // printf("Conv7\n");
    struct Tensor* out_conv7 = convolution(out_conv6, vggbase -> conv7_weight, vggbase -> conv7_bias, 1024, 1, 1, 0, 1, 1);
    destroy_tensor(out_conv6);
    output[1] = out_conv7;
    return output;
}