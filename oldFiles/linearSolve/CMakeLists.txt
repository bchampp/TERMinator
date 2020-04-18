cmake_minimum_required( VERSION 3.10)

project(linearSolve)

set(src
linearSolve.cpp 
fraction_16law13.cpp
)

add_executable( linearSolve ${src})



