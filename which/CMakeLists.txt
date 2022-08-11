cmake_minimum_required(VERSION 3.20)

project(which)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
    which
    src/main.cpp
    src/which.cpp
    src/platform.cpp
)

target_include_directories(
    which
    PRIVATE
    src
)