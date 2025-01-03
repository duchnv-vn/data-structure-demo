cmake_minimum_required(VERSION 3.29)
project(data_structure_demo)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(data_structure_demo
        hash_table/cpp/challenges/union_and_intersection_linked_list.cpp)
