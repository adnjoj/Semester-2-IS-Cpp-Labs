cmake_minimum_required(VERSION 3.24)
project(IS_Lab_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(IS_Lab_4 main.cpp include/i_shape.h include/vector2.h include/rectangle/rectangle.h src/vector2.cpp include/abstract_physical_body.h src/abstract_physical_body.cpp src/rectangle/rectangle.cpp include/rectangle/i_serializer.h include/rectangle/basic_serializer.h src/rectangle/basic_serializer.cpp include/rectangle/i_dialog_initializer.h include/rectangle/basic_dialog_initializer.h src/rectangle/basic_dialog_initializer.cpp include/isosceles_trapezoid/isosceles_trapezoid.h src/isosceles_trapezoid/isosceles_trapezoid.cpp include/isosceles_trapezoid/i_serializer.h include/isosceles_trapezoid/i_dialog_initializer.h include/isosceles_trapezoid/basic_serializer.h src/isosceles_trapezoid/basic_serializer.cpp include/isosceles_trapezoid/basic_dialog_initializer.h src/isosceles_trapezoid/basic_dialog_initializer.cpp include/shape_system.h src/shape_system.cpp include/i_serializable.h include/abstract_serializable_shape_body.h include/abstract_cpp_object.h)
