include(${TWODE_BIN}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Sandbox SandboxApp.cpp)

target_link_libraries(Sandbox PRIVATE TwoDE ${CONAN_LIBS})
target_include_directories(Sandbox PUBLIC ${TWODE_SOURCE} ${CONAN_INCLUDE_DIRS})

message ("TWODE_BIN:" ${TWODE_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TWODE_BIN})

set_property(TARGET Sandbox PROPERTY FOLDER "tests")
set_target_properties(Sandbox PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

install (TARGETS Sandbox
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/resources
        ${TWODE_BIN}/$\(Configuration\)/resources)