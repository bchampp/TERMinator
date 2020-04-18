cmake_minimum_required(VERSION 3.15)
project(equationSolverV2)

set(CMAKE_CXX_STANDARD 14)

add_executable(equationSolverV2 testEquationSolver.cpp Equation.cpp Equation.h Fraction.cpp Fraction.h Polynominal.h Polynominal.cpp)