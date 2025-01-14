set(CMAKE_CXX_COMPILER gcc-11)
project(SSD)
cmake_minimum_required(VERSION 3.22)
set(CMAKE_BUILD_TYPE RELEASE)

find_package(OpenCV REQUIRED)

# add_compile_options(
#     # -ffloat-store
#     # -frounding-math          
#     # -fsignaling-nans   
#     # -fno-unsafe-math-optimizations 
#     # -fno-associative-math
# )

set(SRC_DIR src)

set(TENSOR_LIB_SRC
    ${SRC_DIR}/tensor/tensor.c
)

set(LAYER_LIB_SRC
    ${SRC_DIR}/layer/zeropadd_layer.c
    ${SRC_DIR}/layer/maxpool_layer.c
    ${SRC_DIR}/layer/conv_layer.c
)

set(MODEL_LIB_SRC
    ${SRC_DIR}/model/vgg.c
    ${SRC_DIR}/model/auxiliary.c
    ${SRC_DIR}/model/predict.c
    ${SRC_DIR}/model/ssd.c
)

set(DATAHANDLER_LIB_SRC
    ${SRC_DIR}/datahandler/datahandler.c
)

include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})

add_library(tensor STATIC ${TENSOR_LIB_SRC})
set_target_properties(tensor PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)

add_library(layer STATIC ${LAYER_LIB_SRC})
target_link_libraries(layer tensor)
set_target_properties(layer PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)

add_library(datahandler STATIC ${DATAHANDLER_LIB_SRC})
target_link_libraries(datahandler tensor)
set_target_properties(datahandler PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)

add_library(model STATIC ${MODEL_LIB_SRC})
target_link_libraries(model layer tensor datahandler m)
set_target_properties(model PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)

file(GLOB TEST_SOURCES "test/*.c")

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_directories(${TEST_NAME} PUBLIC ${OpenCV_LIB_DIRS})
    target_link_libraries(${TEST_NAME} tensor layer datahandler model ${OpenCV_LIBS})
    set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY build)
endforeach()