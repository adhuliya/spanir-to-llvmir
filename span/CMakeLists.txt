cmake_minimum_required(VERSION 3.12)
project(span)

set(CMAKE_CXX_STANDARD 14)

add_library(span SHARED library.cpp library.h)