cmake_minimum_required(VERSION 3.21)
project(Vect)

set(CMAKE_CXX_STANDARD 14)

add_library(Vect SHARED library.cpp)

add_library(Num STATIC library.cpp)

target_link_libraries(Vect PUBLIC Num)
