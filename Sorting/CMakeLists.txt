cmake_minimum_required(VERSION 3.24)
project(Sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorting main.cpp src/SM.cpp include/SM.h tests/tests.cpp include/tests.h)
