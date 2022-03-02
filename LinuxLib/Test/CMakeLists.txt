cmake_minimum_required(VERSION 3.21)
project(Test)

set(CMAKE_CXX_STANDARD 14)
include_directories(includes)
file(GLOB numberLib "libs/libNum.a")
file(GLOB vectorLib "libs/libVect.so")

add_executable(Test main.cpp ${numberLib} ${vectorLib})
target_link_libraries(Test ${numberLib} ${vectorLib})