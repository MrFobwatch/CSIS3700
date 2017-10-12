cmake_minimum_required(VERSION 3.8)
project(Calculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        calculator.cpp
        calculator.cpp calculator.h)

add_executable(Calculator ${SOURCE_FILES})
