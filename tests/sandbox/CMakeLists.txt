find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(Sandbox SandboxApp.cpp)

target_link_libraries(Sandbox PRIVATE TwoDE)
target_include_directories(Sandbox PUBLIC "${TwoDE_SOURCE_DIR}/src")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${Sandbox_BINARY_DIR}/resources")

add_custom_command(TARGET Sandbox 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} copy ${CMAKE_BINARY_DIR}/TwoDE.dll ${CMAKE_CURRENT_BINARY_DIR}/TwoDE.dll)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "")
endif()