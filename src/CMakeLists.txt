cmake_minimum_required(VERSION 3.16)

set(TWODE_DLL 1)

include(${TWODE_BIN}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${TWODE_SOURCE}/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ${TWODE_SOURCE}/*.h)
file(GLOB_RECURSE VENDOR_FILES ${VENDOR_DIR}/*.c*)

source_group("sources" FILES ${SOURCE_FILES})
source_group("headers" FILES ${HEADER_FILES})
source_group("vendor" FILES ${VENDOR_FILES})

include_directories(.)
include_directories(${CONAN_INCLUDE_DIRS})
include_directories(${VENDOR_DIR})

add_library(TwoDE SHARED ${SOURCE_FILES} ${VENDOR_FILES})

target_compile_definitions(TwoDE PRIVATE TWODE_DLL)

target_include_directories(TwoDE PRIVATE ${CONAN_INCLUDE_DIRS})

find_package(spdlog)
target_link_libraries(TwoDE PRIVATE ${CONAN_LIBS} spdlog::spdlog)

set_target_properties(TwoDE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TWODE_BIN})
set_target_properties(TwoDE PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${TWODE_BIN})

install (TARGETS TwoDE
         RUNTIME DESTINATION ${TWODE_BIN}/_install
         LIBRARY DESTINATION ${TWODE_BIN}/_install)

add_custom_command(TARGET TwoDE POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources
        ${TWODE_BIN}/resources)