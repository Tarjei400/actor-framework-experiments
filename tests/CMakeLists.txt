cmake_minimum_required(VERSION 3.16)
project(TetrisTests CXX)

include(GoogleTest)
link_directories(${CONAN_LIB_DIRS})

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

add_executable(TetrisTests ${TEST_SOURCES})
target_link_libraries(TetrisTests ${CONAN_LIBS} )
target_include_directories(TetrisTests PRIVATE ${CMAKE_SOURCE_DIR}/lib)

gtest_add_tests(TARGET TetrisTests
        SOURCES ${TEST_SOURCES})