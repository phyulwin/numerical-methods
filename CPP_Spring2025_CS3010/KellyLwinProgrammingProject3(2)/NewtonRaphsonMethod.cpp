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
    double tolerance, int maxIter, std::vector<double>& errors)
{
    // print header
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "NEWTON-RAPHSON METHOD" << std::endl;
    std::cout << " i       x          f(x)        f'(x)     error(%)" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    double x = x0;
    double approxError = 0.0;
    int finalIter = 0;

    for (int i = 0; i < maxIter; i++) {
        double previous = x;
        double fx = f(x);
        double dfx = df(x);

        // updates x by subtracting the ratio of f(x) to dfx
        x = x - fx / dfx;

        // compute approximate error after first iteration
        if (i > 0) {
            approxError = std::fabs((x - previous) / x) * 100;
            errors.push_back(approxError);
        }

        // print the iteration row
        std::cout << std::fixed << std::setw(2) << (i + 1)
                  << std::setw(10) << std::setprecision(5) << previous
                  << std::setw(12) << std::setprecision(5) << fx
                  << std::setw(12) << std::setprecision(5) << dfx
                  << std::setw(10);

        if (i == 0) {std::cout << "   N/A" << "\n";}
        else {std::cout << std::setprecision(4) << approxError << "\n";}

        // check for convergence
        if (i > 0 && approxError < tolerance) {
            finalIter = i + 1;
            std::cout << "The root " << x << " has been found in " << finalIter << " iteration(s)\n";
            return x;
        }

        // check for divergence
        if (i > 0 && errors[i] > 2 * errors[i - 1]) {
            std::cout << "appears to be diverging. Stopping iteration.\n";
            return x;
        }
    }
    std::cout << "did not converge after maximum iterations\n";
    return x;
}