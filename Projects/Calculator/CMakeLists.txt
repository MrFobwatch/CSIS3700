cmake_minimum_required(VERSION 3.8)
project(Calculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        calculator.cpp
        calculator.h)
include_directories($ENV{HOME}/Programming/include)
add_library(dataStructures STATIC IMPORTED)

link_directories($ENV{HOME}/Programming/lib)
add_executable(Calculator ${SOURCE_FILES})
target_link_libraries(Calculator libdataStructures.a)