cmake_minimum_required(VERSION 3.15)
project(leethal++)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/contests)
add_subdirectory(src/leetcode)
add_subdirectory(src/utils)

add_executable(leethal main.cpp)
