cmake_minimum_required(VERSION 3.16)

set(TWODE_DLL 1)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${TWODE_SOURCE}/*.cpp)
source_group("sources" FILES ${SOURCE_FILES})

include_directories(.)
include_directories(${VENDOR_DIR})

add_library(TwoDE SHARED ${SOURCE_FILES} ${VENDOR_DIR}/stb_image/stb_image.cpp)

target_compile_definitions(TwoDE PRIVATE TWODE_DLL)

find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

target_link_libraries(TwoDE GLEW::GLEW glfw)

set_target_properties(TwoDE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TWODE_BIN})
set_target_properties(TwoDE PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${TWODE_BIN})

install (TARGETS TwoDE
         RUNTIME DESTINATION ${TWODE_BIN}/_install
         LIBRARY DESTINATION ${TWODE_BIN}/_install)