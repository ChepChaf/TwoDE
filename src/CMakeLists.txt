find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c*)
file(GLOB VENDOR_FILES ${VENDOR_DIR}/*/*.c*)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${VENDOR_DIR})

add_library(TwoDE SHARED ${SOURCE_FILES} ${VENDOR_FILES})
target_compile_definitions(TwoDE PRIVATE TWODE_DLL)

target_link_libraries(TwoDE PRIVATE glad::glad glfw glm spdlog::spdlog)