cmake_minimum_required(VERSION 3.12)

project(MyProject)

# C++ 컴파일러 설정 (g++를 사용하려면 CC 변수를 설정해야 함)
set(CMAKE_CXX_COMPILER ${CC})

# 컴파일러 플래그 설정
set(CMAKE_CXX_FLAGS "${CCFLAGS} -fno-elide-constructors")

# 소스 파일 경로 설정
set(SRC_DIR src)

# 라이브러리 소스 파일 목록
set(LIB_SRC
    ${SRC_DIR}/core/core.cpp
    ${SRC_DIR}/layer/zeropadding.cpp
    ${SRC_DIR}/layer/maxpooling.cpp
    ${SRC_DIR}/layer/convolution.cpp
    ${SRC_DIR}/layer/relu.cpp
    ${SRC_DIR}/layer/fc.cpp
    ${SRC_DIR}/layer/softmax.cpp
    ${SRC_DIR}/network/model.cpp
    ${SRC_DIR}/datahandler/datahandler.cpp
)

# 헤더 파일 경로 설정
include_directories(include)

# 정적 라이브러리 빌드
add_library(layer STATIC ${LIB_SRC})
set_target_properties(layer PROPERTIES ARCHIVE_OUTPUT_DIRECTORY build/lib)
add_library(network STATIC ${LIB_SRC})
set_target_properties(network PROPERTIES ARCHIVE_OUTPUT_DIRECTORY build/lib)

# 실행 파일 빌드
add_executable(test ${SRC_DIR}/test.cpp)

# 라이브러리 링크 설정
target_link_libraries(test layer network)
