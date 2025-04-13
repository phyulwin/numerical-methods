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
    double tolerance, int maxIter, std::vector<double>& errors)
{
    // print the header
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "SECANT METHOD" << std::endl;
    std::cout << " i     x(i-1)      x(i)      x(i+1)     f(x(i+1))    error(%)" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    double prev = x0, current = x1;
    double x_new = 0.0;
    double approxError = 0.0;
    int finalIter = 0;

    for (int i = 0; i < maxIter; i++) {
        double f_curr = f(current);
        double f_prev = f(prev);

        // if denominator too small, return current approximation
        if (std::fabs(f_curr - f_prev) < 1e-10) {
            std::cout << "Denominator too small.\n";
            return current;
        }

        // update new approximation using the secant formula
        x_new = current - f_curr * (current - prev) / (f_curr - f_prev);

        // compute approximate error after first iteration
        if (i > 0) {
            approxError = std::fabs((x_new - current) / x_new) * 100;
            errors.push_back(approxError);
        }

        // print the iteration row
        std::cout << std::fixed << std::setw(2) << (i + 1)
                  << std::setw(12) << std::setprecision(5) << prev
                  << std::setw(11) << std::setprecision(5) << current
                  << std::setw(11) << std::setprecision(5) << x_new
                  << std::setw(12) << std::setprecision(5) << f(x_new)
                  << std::setw(10);

        if (i == 0) {std::cout << "   N/A" << "\n";}
        else {std::cout << std::setprecision(4) << approxError << "\n";}

        // check for convergence
        if (i > 0 && approxError < tolerance) {
            finalIter = i + 1;
            std::cout << "The root " << x_new << " has been found in " << finalIter
                      << " iteration(s)\n";
            return x_new;
        }

        // update for next iteration
        prev = current;
        current = x_new;
    }
    std::cout << "did not converge after maximum iterations\n";
    return x_new;
}

// modified secant method
double SecantMethod::modifiedSecant(double (*f)(double), double x0, double delta,
    double tolerance, int maxIter, std::vector<double>& errors)
{
    // print header
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "MODIFIED SECANT METHOD" << std::endl;
    std::cout << " i       x        f(x+delta*x)      f(x)      error(%)" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    double x = x0;
    double approxError = 0.0;
    int finalIter = 0;

    for (int i = 0; i < maxIter; i++) {
        double previous = x;
        double denominator = f(x + delta * x) - f(x);

        if (std::fabs(denominator) < 1e-10) {
            std::cout << "Denominator too small. Stopping iteration.\n";
            return x;
        }

        // update x using formula that contains delta
        x = x - (delta * x) * f(x) / denominator;

        // compute approximate error after the first iteration
        if (i > 0) {
            approxError = std::fabs((x - previous) / x) * 100;
            errors.push_back(approxError);
        }

        // print the iteration row
        std::cout << std::fixed << std::setw(2) << (i + 1)
                  << std::setw(10) << std::setprecision(5) << previous
                  << std::setw(12) << std::setprecision(5) << f(previous + delta * previous)
                  << std::setw(12) << std::setprecision(5) << f(previous)
                  << std::setw(10);

        if (i == 0) {std::cout << "   N/A" << "\n";}
        else {std::cout << std::setprecision(4) << approxError << "\n";}

        // check for convergence
        if (i > 0 && approxError < tolerance) {
            finalIter = i + 1;
            std::cout << "The root " << x << " has been found in " << finalIter << " iteration(s)\n";
            return x;
        }

        // check if the error is increasing
        if (i > 0 && errors[i] > 2 * errors[i - 1]) {
            std::cout << "appears to be diverging. Stopping iteration.\n";
            return x;
        }
    }
    std::cout << "did not converge after maximum iterations\n";
    return x;
}
