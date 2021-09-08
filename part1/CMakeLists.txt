cmake_minimum_required(VERSION 3.2)

project(Part1 VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})

configure_file(versions.h.in versions.h)

add_executable(Part1 main.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_include_directories(Part1 PUBLIC "${CMAKE_BINARY_DIR}")