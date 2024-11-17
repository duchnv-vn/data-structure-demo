    cmake_minimum_required(VERSION 3.29)
project(data_structure_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(singly_linked_list)
include_directories(singly_linked_list/c)
include_directories(singly_linked_list/cpp)

add_executable(data_structure_demo
        singly_linked_list/c/single-linked-list.c
        singly_linked_list/cpp/single_linked_list.cpp
        singly_linked_list/cpp/single_linked_list.h
        vector/cpp/vector.h
        vector/cpp/vector.cpp
        doubly_linked_list/cpp/doubly_linked_list.cpp
        doubly_linked_list/cpp/doubly_linked_list.h)
