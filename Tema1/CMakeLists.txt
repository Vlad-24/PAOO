cmake_minimum_required(VERSION 3.10)
project(tema1)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    inc/tema1/garage.hpp
    inc/tema1/naive_garage.hpp
    src/main.cpp
    src/garage.cpp
    src/naive_garage.cpp
)
