cmake_minimum_required(VERSION 3.8)
project(Fractions)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Fraction.cpp Fraction.h)
add_executable(Fractions ${SOURCE_FILES})