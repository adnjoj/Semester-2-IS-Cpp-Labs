cmake_minimum_required(VERSION 3.24)
project(IS_Lab_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(IS_Lab_1 main.cpp include/procedures.h include/circle.h include/vector_2.h src/circle.cpp src/vector.cpp src/procedures.cpp tests/procedures.cpp include/matrix_3x3.h src/matrix_3x3.cpp tests/circle.cpp tests/matrix_3x3.cpp)
