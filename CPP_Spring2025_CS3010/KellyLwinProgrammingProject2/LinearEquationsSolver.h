/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 19th, 2025
 * Assignment: Programming Project 2
 * Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
 * to solve systems of linear equation
 */

#ifndef KELLYLWINPROGRAMMINGPROJECT2_LINEAREQUATIONSSOLVER_H
#define KELLYLWINPROGRAMMINGPROJECT2_LINEAREQUATIONSSOLVER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class LinearEquationsSolver {
private:
    // function to compute the l2 norm of a vector
    static double computeL2Norm(const std::vector<double>& x);

    // function to compute the l2 norm of the difference between two vectors
    static double computeL2NormDiff(const std::vector<double>& x_new, const std::vector<double>& xOldValue);

    // function to print the vector in the desired format
    static void printIteration(const std::vector<double>& x, int iter, double relativeError);

public:
    // jacobi iterative method function
   static std::vector<double> jacobiMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b,
                                const std::vector<double>& x0, double tol, int maxIteration = 50);
    // gauss-seidel iterative method function
    static std::vector<double> gaussSeidelMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b,
                                     const std::vector<double>& x0, double tol, int maxIteration = 50);
};

#endif //KELLYLWINPROGRAMMINGPROJECT2_LINEAREQUATIONSSOLVER_H