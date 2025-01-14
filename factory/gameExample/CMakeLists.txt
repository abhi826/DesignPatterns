cmake_minimum_required(VERSION 3.12)
project(FactoryMethodDemo)

# Use C++17 (or later if desired)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect sources into an executable
add_executable(FactoryMethodDemo
    main.cpp
    M16.cpp
    attachments.cpp
)

target_include_directories(FactoryMethodDemo PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
