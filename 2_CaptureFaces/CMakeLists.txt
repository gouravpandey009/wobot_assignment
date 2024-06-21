cmake_minimum_required(VERSION 3.29)

# Project name and version
project(CaptureFaces VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Add the executable
add_executable(CaptureFaces main.cpp)

# Link OpenCV libraries
target_link_libraries(CaptureFaces ${OpenCV_LIBS})

# Set the startup project for Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CaptureFaces)

# Set command arguments for the debugger in Visual Studio
set_target_properties(CaptureFaces PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "../1_stream_to_frames/out_1_2/")
