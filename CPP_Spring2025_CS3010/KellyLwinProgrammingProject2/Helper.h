/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 19th, 2025
 * Assignment: Programming Project 2
 * Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
 * to solve systems of linear equation
 */

#ifndef KELLYLWINPROGRAMMINGPROJECT2_HELPER_H
#define KELLYLWINPROGRAMMINGPROJECT2_HELPER_H

#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include <string>

#include "LinearEquation.h"

// struct to hold input data for the system
struct LinearSystem {
    std::vector<std::vector<double>> A; // coefficient matrix
    std::vector<double> b; // right-hand side vector
    double error; // stopping error
    std::vector<double> x0; // initial guess
};

class Helper {
public:
    static void getManualInput(std::vector<LinearEquation>& equations); // get input from user
    static void getFileInput(std::vector<LinearEquation>& equations); // get input from file

    // convert equations into matrix A and vector b
    static LinearSystem convertMatrix(const std::vector<LinearEquation>& equations); // this prepares data for solving
};

#endif //KELLYLWINPROGRAMMINGPROJECT2_HELPER_H
