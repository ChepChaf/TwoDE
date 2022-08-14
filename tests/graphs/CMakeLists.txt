set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TWODE_BIN})

file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*/.h*)
add_executable(Graphs Graphs.cpp)

set_property(TARGET Graphs PROPERTY FOLDER "tests")
set_target_properties(Graphs PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

link_directories(${TWODE_LIB})
include_directories(${TWODE_SOURCE} ${HEADER_FILES})

target_link_libraries(Graphs PRIVATE TwoDE)
target_include_directories(Graphs PRIVATE ${TWODE_SOURCE} ${VENDOR_DIR})

install(TARGETS Graphs
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)

if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources)
    message(DEBUG "Copying resources to ${CMAKE_CURRENT_BINARY_DIR}/resources")
    add_custom_command(TARGET Graphs POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/resources
            ${CMAKE_CURRENT_BINARY_DIR}/bin/resources)
endif ()
