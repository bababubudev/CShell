cmake_minimum_required(VERSION 3.10)
project(sea_shell)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

add_executable(sea_shell src/main.c)