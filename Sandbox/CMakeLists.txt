cmake_minimum_required(VERSION 3.2)

add_executable(Sandbox SandboxApp.cpp)

target_link_libraries(Sandbox TwoDE)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${PROJECT_BINARY_DIR}")