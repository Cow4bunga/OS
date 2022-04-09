cmake_minimum_required(VERSION 3.21)
project(MultiLinux)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(MultiLinux main.cpp Matrix.h)
