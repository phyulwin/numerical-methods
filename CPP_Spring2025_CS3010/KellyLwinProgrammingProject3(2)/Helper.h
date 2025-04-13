/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 30th, 2025
 * Assignment: Programming Project 3
 * Program: The program implements and compares five numerical root-finding methods
 * to locate the roots of two functions while generating iteration error data.
 */

#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

#include "BracketingMethod.h"
#include "SecantMethod.h"
#include "NewtonRaphsonMethod.h"

// static functions for function evaluation and their derivatives
class Helper {
private:
    // Function (a): f(x) = 2x^3 – 11.7x^2 + 17.7x – 5
    static double f1(double x);
    // Derivative of Function (a): 6x^2 - 23.4x + 17.7
    static double df1(double x);
    // Function (b): f(x) = x + 10 – x*cosh(50/x)
    static double f2(double x);
    // Derivative of Function (b): 1 - cosh(50/x) + (50/x)*sinh(50/x)
    static double df2(double x);
public:
    // solve function (a): f(x) = 2x^3 - 11.7x^2 + 17.7x - 5
    static void solveFunctionA();
    // solve function (b): f(x) = x + 10 - x*cosh(50/x)
    static void solveFunctionB();
};

#endif //HELPER_H