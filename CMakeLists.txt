cmake_minimum_required(VERSION 3.10)
project(sea_shell)

if(NOT DEFINED CMAKE_C_COMPILER)
endif()

if(NOT DEFINED CMAKE_CXX_COMPILER)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.c")

add_executable(sea_shell ${SOURCES})