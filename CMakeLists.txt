cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)

project("TwoDE")

set(VENDOR_DIR "${PROJECT_BINARY_DIR}/vendor")
set(TWODE_SOURCE "${PROJECT_BINARY_DIR}/src")
set(TWODE_LIB "${PROJECT_BINARY_DIR}/lib")
set(TWODE_BIN "${PROJECT_BINARY_DIR}/bin")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory("src")

# TODO: Make this an optional arg
add_subdirectory("tests")