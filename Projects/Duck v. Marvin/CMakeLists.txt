cmake_minimum_required(VERSION 2.8)
project(Duck_v__Marvin)

#set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-std=c++11")
set(SOURCE_FILES duckDodgers.cpp duckDodgers.h main.cpp)

#target_link_libraries(dataStructures $ENV{HOME}/Programming/lib/libdataStructures.a)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

include_directories($ENV{HOME}/Programming/include)


link_directories($ENV{HOME}/Programming/lib)

add_executable(Duck_v__Marvin ${SOURCE_FILES} duckDodgers.cpp duckDodgers.h)
target_link_libraries(Duck_v__Marvin libdataStructures.a)
