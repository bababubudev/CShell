cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_C_COMPILER)
    if(WIN32)
        find_program(CMAKE_C_COMPILER NAMES gcc gcc.exe)
    elseif(APPLE)
        find_program(CMAKE_C_COMPILER NAMES clang gcc)
    elseif(UNIX)
        find_program(CMAKE_C_COMPILER NAMES gcc clang)
    endif()

    if(NOT CMAKE_C_COMPILER)
        message(FATAL_ERROR "No C compiler found! Please install GCC or Clang.")
    endif()
endif()

project(sea_shell C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.c")

add_executable(sea_shell ${SOURCES})

if(WIN32)
    target_link_libraries(sea_shell PRIVATE ws2_32)
elseif(UNIX)
    target_link_libraries(sea_shell PRIVATE m)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
