cmake_minimum_required(VERSION 2.8)
project(parser-generator)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(GLOB SOURCE_FILES ./*.c)
add_executable(parser-generator ${SOURCE_FILES})
