cmake_minimum_required(VERSION 3.24)
project(IS_Lab_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(IS_Lab_3 main.cpp include/square.h include/vector2.h src/vector2.cpp src/square.cpp tests/square_test.cpp include/int_queue.h src/int_queue.cpp tests/int_queue_test.cpp)
