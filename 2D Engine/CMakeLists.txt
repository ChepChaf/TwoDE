cmake_minimum_required(VERSION 3.2)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c*)
file(GLOB VENDOR_FILES ${CMAKE_CURRENT_SOURCE_DIR}/vendor/*/*.c*)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vendor)

add_library(TwoDE ${SOURCE_FILES} ${VENDOR_FILES})

target_link_libraries(TwoDE PRIVATE glad glfw glm spdlog::spdlog spdlog::spdlog_headers_only)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${PROJECT_BINARY_DIR}")