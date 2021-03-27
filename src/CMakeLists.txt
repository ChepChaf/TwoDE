find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c*)
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h*)
file(GLOB VENDOR_FILES ${VENDOR_DIR}/*/*.c*)

source_group("sources" FILES ${SOURCE_FILES})
source_group("headers" FILES ${HEADER_FILES})
source_group("vendor" FILES ${VENDOR_FILES})

include_directories(.)
include_directories(${VENDOR_DIR})

add_library(TwoDE SHARED ${SOURCE_FILES} ${VENDOR_FILES})
target_compile_definitions(TwoDE PRIVATE TWODE_DLL)

target_link_libraries(TwoDE PRIVATE glad::glad glfw glm spdlog::spdlog)

set_target_properties(TwoDE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set_target_properties(TwoDE PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

install (TARGETS TwoDE
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install)

add_custom_command(TARGET TwoDE POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_BINARY_DIR}/resources
        ${TWODE_BIN}/$\(Configuration\)/resources)