cmake_minimum_required(VERSION 3.21)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test main.cpp)

add_library(Num STATIC ../../Libraries/Num/library.cpp)
add_library(Vect SHARED ../../Libraries/Vect/library.cpp)

target_link_libraries(Test PRIVATE Num)

target_link_libraries(Test PRIVATE Vect)