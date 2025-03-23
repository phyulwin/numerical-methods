cmake_minimum_required(VERSION 3.23)
project(KellyLwinProgrammingProject2)

set(CMAKE_CXX_STANDARD 14)

add_executable(KellyLwinProgrammingProject2 main.cpp Helper.cpp Helper.h LinearEquationsSolver.cpp LinearEquationsSolver.h
        LinearEquation.cpp
        LinearEquation.h
        LargeLinearSystem.cpp
        LargeLinearSystem.cpp
        LargeLinearSystem.h
)
