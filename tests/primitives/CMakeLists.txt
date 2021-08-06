include(${TWODE_BIN}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Primitives Primitives.cpp)

link_directories(${TWODE_LIB})
include_directories(${TWODE_SOURCE} ${CONAN_INCLUDE_DIRS})

target_link_libraries(Primitives PRIVATE TwoDE ${CONAN_LIBS})
target_include_directories(Primitives PRIVATE ${TWODE_SOURCE} ${CONAN_INCLUDE_DIRS})

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