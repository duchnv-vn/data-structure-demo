cmake_minimum_required(VERSION 3.29)
project(data_structure_demo)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(data_structure_demo
        singly_linked_list/cpp/challenges/insert_at_tail.cpp
        singly_linked_list/cpp/challenges/search_in_singly_linked_list.cpp
        singly_linked_list/cpp/challenges/delete_by_value.cpp
        singly_linked_list/cpp/challenges/find_length_linked_list.cpp
)
