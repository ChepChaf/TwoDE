add_executable(Primitives Primitives.cpp)

link_directories(${TWODE_LIB})
include_directories(${TWODE_SOURCE})

target_link_libraries(Primitives PRIVATE TwoDE)
target_include_directories(Primitives PRIVATE ${TWODE_SOURCE})

message ("TWODE_BIN:" ${TWODE_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TWODE_BIN})

set_property(TARGET Primitives PROPERTY FOLDER "tests")
set_target_properties(Primitives PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${TWODE_BIN})

install (TARGETS Primitives
    RUNTIME DESTINATION ${TWODE_BIN}/_install)

if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources)
add_custom_command(TARGET Primitives POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/resources
        ${CMAKE_CURRENT_BINARY_DIR}/bin/resources)
endif()