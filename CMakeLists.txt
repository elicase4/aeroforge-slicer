# CMake & Project Info
cmake_minimum_required(VERSION 3.16)
project(AeroforgeSlicing LANGUAGES CXX)

# Compiler Settingd
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build Directories 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include src CMakeLists
add_subdirectory(src)

# Add test executable
add_executable(test_slicer.exe test/src/test_slicer.cpp)
target_include_directories(test_slicer.exe PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_slicer.exe PRIVATE slicing_lib)
