find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(Sandbox SandboxApp.cpp)

target_link_libraries(Sandbox PRIVATE TwoDE)
target_include_directories(Sandbox PUBLIC "${TWODE_SOURCE}")

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