cmake_minimum_required(VERSION 3.0)
project(FamilyTree)

set(CMAKE_CXX_STANDARD 11)

include_directories($ENV{HOME}/Programming/include)

link_directories($ENV{HOME}/Programming/lib)

add_executable(FamilyTree main.cpp familyTree.cpp familyTree.h)
target_link_libraries(FamilyTree libdataStructures.a)