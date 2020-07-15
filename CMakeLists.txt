cmake_minimum_required(VERSION 3.17)
project(StringsToText)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp library.cpp library.h)
