cmake_minimum_required(VERSION 3.6)
project(s3_vector)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp vector.h)
add_executable(s3_vector ${SOURCE_FILES})