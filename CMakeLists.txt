cmake_minimum_required(VERSION 3.19)
project(EscapeVulkan)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/main.cpp)

add_executable(EscapeVulkan ${SOURCE_FILES})
include_directories(EscapeVulkan PUBLIC "${PROJECT_SOURCE_DIR}/include")

find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)
find_package(spdlog REQUIRED)

target_link_libraries(EscapeVulkan SDL2::SDL2main SDL2::SDL2 spdlog::spdlog)
