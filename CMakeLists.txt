cmake_minimum_required(VERSION 3.11)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

file(GLOB SOURCES "src/*.cpp" "src/*.hpp" "main.cpp")

add_executable(GameOfLife ${SOURCES})

target_link_libraries(GameOfLife raylib)