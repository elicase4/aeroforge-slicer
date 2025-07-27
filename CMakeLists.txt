# CMake & Project Info
cmake_minimum_required(VERSION 3.16)
project(AeroforgeSlicer LANGUAGES CXX)

# Compiler Settingd
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build Directories 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add test executable
add_executable(test_stl_parser.exe test/src/test_stl_parser.cpp)
target_link_libraries(test_stl_parser.exe PRIVATE aeroforge_slicer)

# External Library Example
find_package(Boost REQUIRED)

# Include src CMakeLists
add_subdirectory(src)
