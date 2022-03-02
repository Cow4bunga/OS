cmake_minimum_required(VERSION 3.21)
project (Num)

set(CMAKE_CXX_STANDARD 14)

add_library(Num STATIC number.cpp number.h)
