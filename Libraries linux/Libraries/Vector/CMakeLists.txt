cmake_minimum_required(VERSION 3.20)
project(Vector)

set(CMAKE_CXX_STANDARD 14)

add_library(Vector SHARED
        library.h
        library.cpp
        )

add_library(Number
        library.h
        library.cpp)

target_link_libraries(Vector PUBLIC Number)
