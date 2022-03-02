cmake_minimum_required(VERSION 3.21)
project(Vect)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_library(Vect SHARED vector.cpp
        vector.h)