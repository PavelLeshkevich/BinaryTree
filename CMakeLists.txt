cmake_minimum_required(VERSION 3.5)
project(BinaryTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test.cpp binary_tree.h)
add_executable(BinaryTree ${SOURCE_FILES})