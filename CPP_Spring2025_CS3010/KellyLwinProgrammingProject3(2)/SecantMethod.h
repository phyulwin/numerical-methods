/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 30th, 2025
 * Assignment: Programming Project 3
 * Program: The program implements and compares five numerical root-finding methods
 * to locate the roots of two functions while generating iteration error data.
 */

#ifndef SECANTMETHOD_H
#define SECANTMETHOD_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

class SecantMethod {
public:
 // secant method
 static double secant(double (*f)(double), double x0, double x1, double tolerance, int maxIter, std::vector<double>& errors);
 // modified secant method
 static double modifiedSecant(double (*f)(double), double x0, double delta, double tolerance, int maxIter, std::vector<double>& errors);
};

#endif //SECANTMETHOD_H