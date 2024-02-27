cmake_minimum_required(VERSION 3.20)

project(DE)
add_library(DE OBJECT RungeKuttSolver.cpp)
target_include_directories(DE PUBLIC includes)