cmake_minimum_required(VERSION 3.24)
project(coffer LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(coffer src/find_array2D_value/main.cpp)
add_executable(btree src/binary_tree/btree_algorithm.h src/binary_tree/main.cpp)
add_executable(test tests/test.cpp)
add_executable(stringop src/replace_str/main.cpp src/replace_str/main.cpp)
add_executable(listnode src/linked_list/main.cpp src/linked_list/listnode.h)
add_executable(arraylist src/array_list/main.cpp src/array_list/NumArray.cpp src/array_list/NumArray.h src/array_list/Difference.cpp src/array_list/Difference.h)