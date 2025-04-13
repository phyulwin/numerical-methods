/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 30th, 2025
 * Assignment: Programming Project 3
 * Program: The program implements and compares five numerical root-finding methods
 * to locate the roots of two functions while generating iteration error data.
 */

#include "SecantMethod.h"

// secant method
double SecantMethod::secant(double (*f)(double), double x0, double x1,
 double tolerance, int maxIter, std::vector<double>& errors) {
    // initialize previous value to x0 and current value to x1
    double prev = x0, curr = x1, x_new = 0;

    // compute the function values for the current and previous approximations
    for (int i = 0; i < maxIter; i++) {
       double f_curr = f(curr), f_prev = f(prev);

       // check if difference between these function values is very small
       // if the denominator is too small, return current approximation
       if(std::fabs(f_curr - f_prev) < 1e-10) {
        std::cout << "Denominator too small. Stopping iteration.\n";
        return curr;
       }

       // update new approximation using the secant formula
       x_new = curr - f_curr * (curr - prev) / (f_curr - f_prev);

       // calculate approximate relative error as the percentage change between iterations
       double approxError = std::fabs((x_new - curr) / x_new) * 100;
       errors.push_back(approxError);

       // if ea is below the tolerance, return the new approximation
       if(approxError < tolerance) {
        std::cout << "converged in " << (i+1) << " iterations\n";
        return x_new;
       }
       // update the previous and current values for the next iteration
       prev = curr;
       curr = x_new;
    }
    std::cout << "did not converge after maximum iterations\n";
    return x_new;
}

// modified secant method
double SecantMethod::modifiedSecant(double (*f)(double), double x0, double delta,
 double tolerance, int maxIter, std::vector<double>& errors) {
    // initialize x with the initial guess x0
    double x = x0;

    for (int i = 0; i < maxIter; i++) {
        // store the current x as previous for comparison
        double prev = x;

        // calculate the denominator
        double denominator = f(x + delta * x) - f(x);

        // if denominator is too small, return current value to prevent division by zero
        if(std::fabs(denominator) < 1e-10) {
         std::cout << "Denominator too small. Stopping iteration.\n";
         return x;
        }

        // update x using formula that contains delta
        x = x - delta * x * f(x) / denominator;
        // compute approximate relative error as the percentage change between new x and previous x
        double approxError = std::fabs((x - prev) / x) * 100;
        errors.push_back(approxError);

        // if error is below tolerance, return the new value
        if(approxError < tolerance) {
         std::cout << "converged in " << (i+1) << " iterations\n";
         return x;
        }

        // check if the error is increasing significantly compared to the previous iteration
        // if diverging, return the current approximation
        if(i > 0 && errors[i] > 2 * errors[i-1]) {
         std::cout << "appears to be diverging. Stopping iteration.\n";
         return x;
        }
    }
    std::cout << "did not converge after maximum iterations\n";
    return x;
}