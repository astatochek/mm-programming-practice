cmake_minimum_required(VERSION 3.20)
project(Task_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(Google_tests)

add_executable(Task_5 main.cpp Google_tests/source.cpp Google_tests/source.h)

add_subdirectory(Google_tests)
