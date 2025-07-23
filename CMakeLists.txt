cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CardGame)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(CardGame src/main.cpp src/deck.cpp src/hand.cpp)

# Include directories
include_directories(src)