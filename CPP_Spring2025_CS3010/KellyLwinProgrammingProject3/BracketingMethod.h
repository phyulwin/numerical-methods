/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 30th, 2025
 * Assignment: Programming Project 3
 * Program: The program implements and compares five numerical root-finding methods
 * to locate the roots of two functions while generating iteration error data.
 */

#ifndef BRACKETINGMETHOD_H
#define BRACKETINGMETHOD_H

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

class BracketingMethod {
public:
    // bisection method - computes a root by halving the interval
    static double bisection(double (*f)(double), double a, double b, double tolerance, int maxIter, std::vector<double>& errors);
    // false-position method - computes a root using a linear interpolation approach
    static double falsePosition(double (*f)(double), double a, double b, double tolerance, int maxIter, std::vector<double>& errors);
};

#endif //BRACKETINGMETHOD_H