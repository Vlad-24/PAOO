cmake_minimum_required(VERSION 3.10)
project(lucrare5)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    inc/lucrare5/vehicle.hpp
    inc/lucrare5/service_car.hpp
    src/main.cpp
    src/vehicle.cpp
    src/service_car.cpp
)
