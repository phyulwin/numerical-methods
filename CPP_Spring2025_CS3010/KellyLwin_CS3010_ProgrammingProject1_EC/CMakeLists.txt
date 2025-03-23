cmake_minimum_required(VERSION 3.23)
project(KellyLwin_CS3010_ProgrammingProject1)

set(CMAKE_CXX_STANDARD 14)

add_executable(KellyLwin_CS3010_ProgrammingProject1 main.cpp LinearEquation.cpp LinearEquation.h GaussianElimination.cpp GaussianElimination.h Helper.cpp Helper.h
        TestLargeSystem.cpp
        TestLargeSystem.h)
