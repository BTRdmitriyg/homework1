cmake_minimum_required(VERSION 3.2)

project(ip_filter)

add_executable(ip_filter main.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_include_directories(ip_filter PUBLIC "${CMAKE_BINARY_DIR}")