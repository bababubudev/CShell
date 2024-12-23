cmake_minimum_required(VERSION 3.10)
project(sea_shell)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.c")

add_executable(sea_shell ${SOURCES})