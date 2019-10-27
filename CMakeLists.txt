cmake_minimum_required(VERSION 3.15)
project(leethal++)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(contests)

add_executable(leethal main.cpp)
add_executable(defangIPaddr src/defangIPaddr.cpp)
add_executable(maxIncreaseKeepingSkyline src/maxIncreaseKeepingSkyline.cpp)
add_executable(hammingDistance src/hammingDistance.cpp)
