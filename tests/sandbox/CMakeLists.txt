add_executable(Sandbox SandboxApp.cpp)

link_directories(${TWODE_LIB})
include_directories(${TWODE_SOURCE})

target_link_libraries(Sandbox PRIVATE TwoDE)
target_include_directories(Sandbox PUBLIC ${TWODE_SOURCE} ${VENDOR_DIR})

message ("TWODE_BIN:" ${TWODE_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TWODE_BIN})

set_property(TARGET Sandbox PROPERTY FOLDER "tests")
set_target_properties(Sandbox PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

install (TARGETS Sandbox
    RUNTIME DESTINATION ${TWODE_BIN}/_install)

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/resources
        ${CMAKE_CURRENT_BINARY_DIR}/bin/resources)
