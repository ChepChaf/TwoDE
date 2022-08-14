cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)

project("TwoDE")

set(VENDOR_DIR "${PROJECT_SOURCE_DIR}/vendor")
set(TWODE_SOURCE "${PROJECT_SOURCE_DIR}/src")
set(TWODE_LIB "${PROJECT_SOURCE_DIR}/lib")
set(TWODE_BIN "${PROJECT_SOURCE_DIR}/build")

set(PROJECT_BINARY_DIR "${TWODE_BIN}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory("src")

# TODO: Make this an optional arg
add_subdirectory("tests")