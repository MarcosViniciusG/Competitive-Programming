cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 23)

project("Competitive Programming")

add_executable(src src.cpp)

target_include_directories(src PRIVATE
    Algorithms/
)