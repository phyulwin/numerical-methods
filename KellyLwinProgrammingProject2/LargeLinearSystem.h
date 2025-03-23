/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 19th, 2025
 * Assignment: Programming Project 2
 * Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
 * to solve systems of linear
 * EXTRA CREDIT FILE
 */

#ifndef LARGELINEARSYSTEM_H
#define LARGELINEARSYSTEM_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <sstream> // for output suppression

#include "LinearEquationsSolver.h"

class LargeLinearSystem {
    public:
          // function to test large systems with random coefficients
          static void testLargeSystems();
};

#endif //LARGELINEARSYSTEM_H