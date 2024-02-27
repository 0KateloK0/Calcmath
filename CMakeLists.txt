cmake_minimum_required(VERSION 3.20)

project(calcmath)

set(CMAKE_CXX_STANDARD 20)

# include_directories(DE)
include_directories(common)
add_subdirectory(DE)
add_executable(calcmath main.cpp)
target_link_libraries(calcmath PUBLIC DE)