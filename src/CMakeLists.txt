cmake_minimum_required(VERSION 3.20)

set(TWODE_DLL 1)

include(${TWODE_BIN}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c*)
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h*)
file(GLOB VENDOR_FILES ${VENDOR_DIR}/*/*.c*)

source_group("sources" FILES ${SOURCE_FILES})
source_group("headers" FILES ${HEADER_FILES})
source_group("vendor" FILES ${VENDOR_FILES})

include_directories(.)
include_directories(${CONAN_INCLUDE_DIRS})
include_directories(${VENDOR_DIR})

add_library(TwoDE SHARED ${SOURCE_FILES} ${VENDOR_FILES})

target_compile_definitions(TwoDE PRIVATE TWODE_DLL)

target_include_directories(TwoDE PRIVATE ${CONAN_INCLUDE_DIRS})
target_link_libraries(TwoDE PRIVATE ${CONAN_LIBS})

target_compile_definitions(${CMAKE_PROJECT_NAME}
        PUBLIC
        SPDLOG_COMPILED_LIB
        SPDLOG_FMT_EXTERNAL)

set_target_properties(TwoDE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set_target_properties(TwoDE PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

install (TARGETS TwoDE
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install)

add_custom_command(TARGET TwoDE POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_BINARY_DIR}/resources
        ${TWODE_BIN}/$\(Configuration\)/resources)