cmake_minimum_required(VERSION 3.29)
project(data_structure_demo)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(data_structure_demo
        ptit/section-3-backtracking-and-branch-bound/main.cpp
        ptit/section-3-backtracking-and-branch-bound/string_permutations.h
)
