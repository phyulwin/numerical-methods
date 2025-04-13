/**
* Name: Kelly Lwin
* Course: Numerical Methods (CS3010)
* Date: March 30th, 2025
* Assignment: Programming Project 3
* Program: The program implements and compares five numerical root-finding methods
* to locate the roots of two functions while generating iteration error data.
*/

#include "BracketingMethod.h"

// bisection method - computes a root by halving the interval
double BracketingMethod::bisection(double (*f)(double), double a, double b,
    double tolerance, int maxIter, std::vector<double>& errors)
{
    // check if function values have opposite signs
    if (f(a) * f(b) >= 0) {
        std::cout << "error: f(a) and f(b) must have opposite signs.\n";
        exit(1);
    }

    // print header
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "BISECTION METHOD" << std::endl;
    std::cout << " i     a         b         c       f(a)       f(c)    error(%)" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    // initialize the midpoint c to the lower bound a
    double c = a;
    double approxError = 0.0;
    int finalIter = 0;  // hold the iteration at convergence

    for (int i = 0; i < maxIter; i++) {
        double previous = c;
        c = (a + b) / 2.0;

        // compute approximate error after the first iteration
        if (i > 0) {
            approxError = std::fabs((c - previous) / c) * 100;
            errors.push_back(approxError);
        }

        // print the iteration row
        std::cout << std::fixed << std::setw(2) << (i + 1)
                  << std::setw(9) << std::setprecision(4) << a
                  << std::setw(9) << std::setprecision(4) << b
                  << std::setw(9) << std::setprecision(4) << c
                  << std::setw(11) << std::setprecision(4) << f(a)
                  << std::setw(11) << std::setprecision(4) << f(c)
                  << std::setw(10);
        if (i == 0)
            std::cout << "   N/A" << "\n";
        else
            std::cout << std::setprecision(4) << approxError << "\n";

        // check for convergence
        if (i > 0 && approxError < tolerance) {
            finalIter = i + 1;
            std::cout << "The root " << c << " has been found in " << finalIter << " iteration(s)\n";
            return c;
        }

        // update the interval based on sign change
        if (f(a) * f(c) < 0) {b = c;}
        else {a = c;}
    }
    std::cout << "did not converge after maximum iterations\n";
    return c;
}

// false-position method - computes a root using a linear interpolation approach
double BracketingMethod::falsePosition(double (*f)(double), double a, double b,
    double tolerance, int maxIter, std::vector<double>& errors)
{
    // check if endpoints bracket a root: f(a) and f(b) have opposite signs
    if (f(a) * f(b) >= 0) {
        std::cout << "error: f(a) and f(b) must have opposite signs.\n";
        exit(1);
    }

    // print header
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "FALSE-POSITION METHOD" << std::endl;
    std::cout << " i     a         b         c       f(a)       f(c)    error(%)" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    // initialize c
    double c = a;
    double approxError = 0.0;
    int finalIter = 0;

    for (int i = 0; i < maxIter; i++) {
        double previous = c;

        // false-position formula
        c = b - f(b) * (a - b) / (f(a) - f(b));

        // compute approximate error after the first iteration
        if (i > 0) {
            approxError = std::fabs((c - previous) / c) * 100;
            errors.push_back(approxError);
        }

        // print the iteration row
        std::cout << std::fixed << std::setw(2) << (i + 1)
                  << std::setw(9) << std::setprecision(4) << a
                  << std::setw(9) << std::setprecision(4) << b
                  << std::setw(9) << std::setprecision(4) << c
                  << std::setw(11) << std::setprecision(4) << f(a)
                  << std::setw(11) << std::setprecision(4) << f(c)
                  << std::setw(10);
        if (i == 0)
            std::cout << "   N/A" << "\n";
        else
            std::cout << std::setprecision(4) << approxError << "\n";

        // check convergence
        if (i > 0 && approxError < tolerance) {
            finalIter = i + 1;
            std::cout << "The root " << c << " has been found in " << finalIter << " iteration(s)\n";
            return c;
        }
        // update interval based on sign change
        if (f(a) * f(c) < 0) {b = c;}
        else {a = c;}
    }
    std::cout << "did not converge after maximum iterations\n";
    return c;
}