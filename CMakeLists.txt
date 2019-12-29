cmake_minimum_required(VERSION 3.15)
project(LearnHazel)
set(CMAKE_CXX_STANDARD 14)

set(HAZEL_VERSION_MAJOR 1)
set(HAZEL_VERSION_MINOR 0)

configure_file(
"${PROJECT_SOURCE_DIR}/config.h.in"
"${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_SOURCE_DIR}/Hazel/src")
add_subdirectory(Hazel)

add_executable(LearnHazel Sandbox/src/SandboxApp.cpp)

target_link_libraries(LearnHazel Hazel)
