# Library

A Library Management System built with C++20, featuring a modular Core/App architecture for managing library members, book checkouts, and library operations.

## Project Structure

The project follows a two-tier architecture:

- **Library-Core**: Static library containing core functionality (Person, Library classes)
- **Library-App**: Executable application that links against the Core library

## Requirements

- **C++ Compiler**: GCC 10+ or Clang 12+ (C++20 support required)
- **CMake**: Version 3.20 or higher
- **Build System**: Ninja (recommended) or GNU Make
- **Operating System**: Linux (primary), macOS (with adjustments)

## Building the Project

### Quick Start

The easiest way to build and run the project:

```bash
# Build and run in one command
./Scripts/build.sh --run

# Or build separately
./Scripts/build.sh
./Scripts/run.sh
```

### Build Options

The build script supports several options:

```bash
# Debug build (default)
./Scripts/build.sh

# Release build with optimizations
./Scripts/build.sh --release

# Use GNU Make instead of Ninja
./Scripts/build.sh --make

# Clean previous build artifacts
./Scripts/build.sh --clean

# Build and immediately run
./Scripts/build.sh --run

# Combine options
./Scripts/build.sh --release --clean --run
```

### Manual CMake Build

If you prefer manual control:

```bash
# Configure
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++

# Build
cmake --build build -j

# Run
./build/Library-App/LibraryApp
```

## Development

### IDE Support

The project automatically generates `compile_commands.json` for clangd and other language servers, providing:

- Code completion
- Syntax checking
- Jump to definition
- Refactoring support

The compile commands database is automatically symlinked to the project root for easy IDE integration.

### Project Configuration

All build configurations are managed through CMake:

- **Root CMakeLists.txt**: Project-wide settings, C++20 standard
- **Library-Core/CMakeLists.txt**: Core library target and public headers
- **Library-App/CMakeLists.txt**: Application target and linkage

### Adding New Files

**To add files to Core:**

Edit `Library-Core/CMakeLists.txt`:

```cmake
add_library(LibraryCore STATIC
    Source/Core/Core.cpp
    Source/Core/Person.cpp
    Source/Core/Library.cpp
    Source/Core/NewFile.cpp  # Add your new file
)
```

**To add files to App:**

Edit `Library-App/CMakeLists.txt`:

```cmake
add_executable(LibraryApp
    Source/App.cpp
    Source/NewApp.cpp  # Add your new file
)
```

## Build Artifacts

Build outputs are organized by configuration:

## Alternative Build Systems

While CMake is the primary build system, the project also includes Premake/Makefile support for compatibility:

- Premake-generated makefiles are available
- Use `make config=debug` or `make config=release`
- Makefile supports debug, release, and dist configurations

## Architecture Benefits

The Core/App split provides several advantages:

- **Modularity**: Core functionality can be reused across multiple applications
- **Testing**: Core library can be tested independently
- **Clean Separation**: Business logic (Core) separated from application logic (App)
- **Scalability**: Easy to create additional applications using the same Core

## Common Tasks

### Clean Build

```bash
./Scripts/build.sh --clean
```

### Quick Test Run

```bash
./Scripts/run.sh
```

### Build Both Debug and Release

```bash
./Scripts/build.sh
./Scripts/build.sh --release
```

### Debugging

Since debug symbols are enabled by default in Debug builds:

```bash
./Scripts/build.sh
gdb ./build/Library-App/LibraryApp
```

## Contributing

This project uses C++20 features. When contributing:

1. Maintain the Core/App architecture separation
2. Follow C++20 best practices
3. Ensure code compiles with both GCC and Clang
4. Update CMakeLists.txt when adding new source files
5. Test both Debug and Release builds

## License

This project is released into the public domain under the UNLICENSE. See [UNLICENSE.txt](UNLICENSE.txt) for full details.

You are free to copy, modify, publish, use, compile, sell, or distribute this software for any purpose, commercial or non-commercial, and by any means.

## Troubleshooting

### Build Script Not Executable

```bash
chmod +x Scripts/build.sh Scripts/run.sh
```

### CMake Version Too Old

Update CMake to version 3.20 or higher:

```bash
# Ubuntu/Debian
sudo apt update && sudo apt install cmake

# Or download from cmake.org
```

### Missing Ninja

Install Ninja or use GNU Make:

```bash
# Install Ninja
sudo apt install ninja-build

# Or use Make
./Scripts/build.sh --make
```

### Compiler Not Found

Ensure GCC or Clang is installed:

```bash
# GCC
sudo apt install g++

# Clang
sudo apt install clang
```

## Features

The Library Management System currently supports:

- **Member Management**: Users can become library members
- **Book Checkout**: Members can check out multiple books
- **Checkout Tracking**: View currently checked out books
- **Interactive Menu**: Simple command-line interface for library operations

## Future Development

Potential extensions to the library system include:

- Book return functionality
- Due date tracking
- Book inventory management
- Member database persistence
- Search functionality for books
- Late fee calculation
- Multiple library branches support
- Book reservation system

