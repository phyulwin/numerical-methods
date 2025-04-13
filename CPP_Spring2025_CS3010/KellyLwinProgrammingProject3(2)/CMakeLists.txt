cmake_minimum_required(VERSION 3.30)
project(KellyLwinProgrammingProject3)

set(CMAKE_CXX_STANDARD 20)

add_executable(KellyLwinProgrammingProject3 main.cpp
        Helper.cpp
        Helper.h
        BracketingMethod.cpp
        BracketingMethod.h
        SecantMethod.cpp
        SecantMethod.h
        NewtonRaphsonMethod.cpp
        NewtonRaphsonMethod.h
)
