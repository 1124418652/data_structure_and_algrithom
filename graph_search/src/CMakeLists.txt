cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(hello)
set(SRC_LIST main.cpp)
message(STATUS "This is binary directories " ${hello_BINARY_DIR})

add_executable(hello ${SRC_LIST})