find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(Primitives Primitives.cpp)

target_link_libraries(Primitives PRIVATE TwoDE)
target_include_directories(Primitives PUBLIC "${TWODE_SOURCE}")

message ("TWODE_BIN:" ${TWODE_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TWODE_BIN})

set_property(TARGET Primitives PROPERTY FOLDER "tests")
set_target_properties(Primitives PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

install (TARGETS Primitives
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)

if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources)
add_custom_command(TARGET Primitives POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/resources
        ${TWODE_BIN}/$\(Configuration\)/resources)
endif()