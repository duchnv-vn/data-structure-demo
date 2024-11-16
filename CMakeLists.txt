cmake_minimum_required(VERSION 3.29)
project(data_structure_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(linked_list)
include_directories(linked_list/c)
include_directories(linked_list/cpp)

add_executable(data_structure_demo
    linked_list/c/single-linked-list.c
    linked_list/cpp/single_linked_list.cpp
    linked_list/cpp/single_linked_list.h)
