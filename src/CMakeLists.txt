cmake_minimum_required(VERSION 3.16)

#
#include_directories(build)
#include_directories(net)
#
#add_executable(test
#    build/sensor.pb.cc
#    build/sensor.pb.h
#    net/Server.cpp
#    net/Server.h
#    main.cpp)

project(TetrisLib CXX)
add_definitions("-std=c++2a")
# Download automatically, you can also just copy the conan.cmake file

# Parse all protobuff files
file(GLOB_RECURSE LIB_SOURCES LIST_DIRECTORIES false *.h *.cpp)

add_library(TetrisLib OBJECT ${LIB_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/src )
