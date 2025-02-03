# C Shell

## Overview

C Shell is a lightweight, custom-built shell program implemented in C. It provides a simple command-line interface with built-in and custom commands, designed to be a learning project demonstrating shell implementation techniques.

## Features

- Custom command execution
- Built-in commands:
  - `cd`: Change directory
  - `exit` (aliases: `q`, `quit`): Exit the shell
- Custom commands:
  - `help`: Display available commands
  - `clear`: Clear the terminal screen
  - `toggledir`: Toggle directory display in prompt
  - `setclr`: Set terminal foreground color
  - `greet`: Display a welcome message

## Color Customization

The shell supports color customization with the `setclr` command:
- Available colors:
  - 0/default
  - 1/green
  - 2/blue
  - 3/yellow
  - 4/white
  - 5/grey

## Prerequisites

- CMake (version 3.10 or higher)
- C compiler with C99 support
- POSIX-compatible system (Linux, macOS) or MinGW for Windows

## Build Instructions

### Linux/macOS

```bash
mkdir build && cd build
cmake ..
make
```

### Windows (MinGW)

```bash
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

## Project Structure

```
sea_shell/
├── include/
│   ├── builtin_cmd.h     - Built-in command definitions
│   ├── custom_cmd.h      - Custom command definitions
│   ├── shl_execute.h     - Command execution logic
│   ├── shl_init.h        - Shell initialization
│   ├── shl_io.h          - Input/output handling
│   ├── shl_launch.h      - Process launching
│   ├── shl_loop.h        - Main shell loop
│   ├── shl_utils.h       - Utility functions
│   └── shl_init.h        - Shell settings management
├── src/
│   ├── main.c            - Program entry point
│   ├── builtin_cmd.c     - Built-in command implementations
│   ├── custom_cmd.c      - Custom command implementations
│   ├── shl_execute.c     - Command execution implementation
│   ├── shl_init.c        - Shell initialization logic
│   ├── shl_io.c          - Input/output implementation
│   ├── shl_launch.c      - Process launching implementation
│   ├── shl_loop.c        - Shell loop implementation
│   └── shl_utils.c       - Utility function implementations
└── CMakeLists.txt        - CMake build configuration
```

## Usage

After building, run the shell:

```bash
./sea_shell
```

### Example Commands

- Change directory: `cd /path/to/directory`
- Get help: `help`
- Change color: `setclr blue` or `setclr 2`
- Greet: `greet`
- Exit: `exit` or `quit`

## Known Issues

- Some potential memory management issues
- Limited error handling
- Platform-specific behavior between POSIX and Windows

## Future Improvements

- Enhanced error handling
- More robust memory management
- Additional built-in commands
- Improved cross-platform support

## Contributing

Contributions are welcome! Please submit pull requests or open issues on the project repository.
