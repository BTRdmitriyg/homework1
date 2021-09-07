cmake_minimum_required(VERSION 3.2)

project(Homework1 VERSION 1)

configure_file(versions.h.in versions.h)

add_executable(Homework1 main.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_include_directories(Homework1 PUBLIC "${CMAKE_BINARY_DIR}")