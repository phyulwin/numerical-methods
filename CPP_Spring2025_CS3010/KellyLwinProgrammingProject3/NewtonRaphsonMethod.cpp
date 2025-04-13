/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 30th, 2025
 * Assignment: Programming Project 3
 * Program: The program implements and compares five numerical root-finding methods
 * to locate the roots of two functions while generating iteration error data.
 */

#include "NewtonRaphsonMethod.h"

// iteratively update function's root estimate until approximate relative error is below tolerance
double NewtonRaphsonMethod::newtonRaphson(double (*f)(double), double (*df)(double), double x0,
 double tolerance, int maxIter, std::vector<double>& errors) {
    double x = x0;

    // saves the current x in prev and computes the derivative dfx by calling df
    for (int i = 0; i < maxIter; i++) {
     double previous = x;
     double dfx = df(x);

     // updates x by subtracting the ratio of f(x) to dfx
     x = x - f(x) / dfx;

     // computes the approximate relative error and adds it to the errors vector
     double approxError = std::fabs((x - previous) / x) * 100;
     errors.push_back(approxError);

     // if the error is below tol, it prints a message and returns x to indicate convergence
     if(approxError < tolerance) {
      std::cout << "converged in " << (i+1) << " iterations\n";
      return x;
     }

     // checks for divergence by comparing the current error to the previous one
     if(i > 0 && errors[i] > 2 * errors[i-1]) {
      std::cout << "appears to be diverging. Stopping iteration.\n";
      return x;
     }
    }

    // prints a message indicating no convergence and returns the last computed x
    std::cout << "did not converge after maximum iterations\n";
    return x;
}