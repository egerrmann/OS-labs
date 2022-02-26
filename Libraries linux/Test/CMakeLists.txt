cmake_minimum_required(VERSION 3.21)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_library(
        Number
        ../Libraries/Number/library.cpp
        ../Libraries/Number/library.h
)

add_library(
        Vector SHARED
        ../Libraries/Vector/library.cpp
        ../Libraries/Vector/library.h
)

add_executable(Test main.cpp)

target_link_libraries(Test PRIVATE Number Vector)
