# CShell

## Overview

Sea Shell is a basic shell program that provides a command-line interface for executing commands. It is built using C and uses CMake as its build system.

## Building

### Prerequisites

- CMake (version 3.10 or higher)
- C compiler
- C standard library

### Build Instructions

1. Create a build directory:
```bash
mkdir build && cd build
```

2. Generate build files:
```bash
cmake ..
```

3. Build the project:
```bash
make
```

The executable `sea_shell` will be created in the build directory.

## Project Structure

```
sea_shell/
├── include/
│   ├── shl_io.h      - Input/output operations
│   ├── shl_loop.h    - Main shell loop
│   └── shl_utils.h   - Utility definitions
├── src/
│   ├── main.c        - Entry point
│   ├── shl_io.c      - Input handling implementation
│   └── shl_loop.c    - Shell loop implementation
└── CMakeLists.txt    - CMake build configuration
```

## Usage

After building, run the shell:

```bash
./sea_shell
```

The shell will present a prompt (`>`) where you can enter commands. Currently supported commands:
- `exit, quit, q`: Exits the shell
