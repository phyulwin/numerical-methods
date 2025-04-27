cmake_minimum_required(VERSION 3.30)
project(ProgrammingProject4)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProgrammingProject4 main.cpp
        InterpolatingPolynomial.cpp
        InterpolatingPolynomial.h
        PolynomialHelper.cpp
        PolynomialHelper.h)
