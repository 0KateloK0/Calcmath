project(ODE)

set(CMAKE_CXX_STANDARD 20)

# add_executable(ODE runge-kutt.cpp common.cpp)
add_executable(ODE iteration.cpp common.cpp)