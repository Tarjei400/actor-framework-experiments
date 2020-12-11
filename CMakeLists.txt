cmake_minimum_required(VERSION 3.16)



project(Tetris CXX)
add_definitions("-std=c++2a")

message("${CMAKE_BINARY_DIR}/conan.cmake Conan path")
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/develop/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt
        BASIC_SETUP BUILD missing KEEP_PATHS)

enable_testing()

#find_package(GTest REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)


add_executable(Tetris main.cpp)
message("Linking conan libraries: ${CONAN_LIBS} ")
target_link_libraries(Tetris TetrisLib ${CONAN_LIBS} )

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.json
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
# target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/src )
