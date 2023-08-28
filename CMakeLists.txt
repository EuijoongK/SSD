cmake_minimum_required(VERSION 3.12)

project(Mobilenet)

include_directories(include)

link_directories(build/lib)

add_executable(test src/test.cpp)

target_link_libraries(test network layer)