cmake_minimum_required(VERSION 3.0.0)

project(hazel)

# use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# create compile_command.json
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Enable warning
add_compile_options(-Wall -Wextra -Wpedantic)

# Default to a release build
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Define the hazel static library
file(GLOB_RECURSE hazel_sources RELATIVE ${PROJECT_SOURCE_DIR} Hazel/src/*.cpp)
add_library(hazel STATIC
    ${hazel_sources}
    Hazel/vendor/stb_image/stb_image.cpp
)

target_compile_definitions(hazel PRIVATE HZ_PLATFORM_MAC)

# set defines for build type
set(CMAKE_CXX_FLAGS_DEBUG -DHZ_DEBUG)
set(CMAKE_CXX_FLAGS_RELEASE -DHZ_RELEASE)
# set(CMAKE_CXX_FLAGS_DIST -DHZ_DIST)

# Include
target_include_directories(hazel PUBLIC
  "${PROJECT_SOURCE_DIR}/Hazel/src"
  "${PROJECT_SOURCE_DIR}/Hazel/vendor/Glad/include"
  "${PROJECT_SOURCE_DIR}/Hazel/vendor/glm"
  "${PROJECT_SOURCE_DIR}/Hazel/vendor/imgui"
  "${PROJECT_SOURCE_DIR}/Hazel/vendor/spdlog/include"
  "${PROJECT_SOURCE_DIR}/Hazel/vendor/stb_image"
)

# glfw
find_package(glfw3 3.3 REQUIRED)
target_link_directories(hazel PRIVATE glfw)
target_compile_options(hazel PRIVATE -DGLFW_INCLUDE_NONE)

# glad
add_subdirectory(Hazel/vendor/Glad)
target_link_libraries(hazel PRIVATE glad)

# imgui
add_subdirectory(Hazel/vendor/imgui)
target_link_libraries(hazel PRIVATE imgui)


# ----- sandox------
file(GLOB sandbox_sources Sandbox/src/SandboxApp.cpp)
add_executable(sandbox ${sandbox_sources})

target_include_directories(sandbox PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(sandbox PUBLIC hazel)
