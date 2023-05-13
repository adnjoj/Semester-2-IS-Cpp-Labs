cmake_minimum_required(VERSION 3.24)
project(IS_Lab_5)

set(CMAKE_CXX_STANDARD 20)

add_executable(IS_Lab_5 main.cpp include/power.h tests/power_test.cpp include/array.h include/index_out_of_bound_exception.h tests/array_test.cpp)
