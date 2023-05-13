cmake_minimum_required(VERSION 3.24)
project(IS_Lab_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(IS_Lab_2 main.cpp include/complex_number.h src/complex_number.cpp include/string_queue.h src/string_queue.cpp include/file_writer.h src/file_writer.cpp include/menu.h src/menu.cpp include/string_parser.h src/string_parser.cpp include/complex_number_handler.h src/complex_number_handler.cpp include/string_validator.h src/string_validator.cpp include/string_queue_handler.h src/string_queue_handler.cpp src/file_writer_handler.cpp include/file_writer_handler.h)
