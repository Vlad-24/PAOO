cmake_minimum_required(VERSION 3.10)
project(lucrare6)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
    inc/lucrare6/diagnostic.hpp
    inc/lucrare6/lift_lock.hpp
    src/main.cpp
    src/diagnostic.cpp
    src/lift_lock.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
