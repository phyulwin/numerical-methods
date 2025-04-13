/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 30th, 2025
 * Assignment: Programming Project 3
 * Program: The program implements and compares five numerical root-finding methods
 * to locate the roots of two functions while generating iteration error data.
 */

#ifndef NEWTONRAPHSONMETHOD_H
#define NEWTONRAPHSONMETHOD_H

#include <iostream>
#include <cmath>
#include <vector>

class NewtonRaphsonMethod {
public:
    // iteratively update function's root estimate until approximate relative error is below tolerance
    static double newtonRaphson(double (*f)(double), double (*df)(double), double x0,
        double tolerance, int maxIter, std::vector<double>& errors);
};

#endif //NEWTONRAPHSONMETHOD_H