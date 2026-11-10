cmake_minimum_required(VERSION 3.10)
project(lucrare4)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    inc/lucrare4/engine.hpp
    inc/lucrare4/car.hpp
    inc/lucrare4/dealership.hpp
    inc/lucrare4/identity.hpp
    src/main.cpp
    src/engine.cpp
    src/car.cpp
    src/dealership.cpp
    src/catalog.cpp
    src/identity.cpp
)
