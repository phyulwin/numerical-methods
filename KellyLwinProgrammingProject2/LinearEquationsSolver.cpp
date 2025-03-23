/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 19th, 2025
 * Assignment: Programming Project 2
 * Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
 * to solve systems of linear equation
 */

#include "LinearEquationsSolver.h"

// function to compute the l2 norm of the difference between two vectors
double LinearEquationsSolver::computeL2NormDiff(const std::vector<double>& x_new, const std::vector<double>& xOldValue) {
    double sum = 0.0;
    for (size_t i = 0; i < x_new.size(); i++) {
        // find the difference between each value
        double diff = x_new[i] - xOldValue[i];
        // square the difference and add to sum
        sum += diff * diff;
    }
    // returns the square root of the sum of squared differences
    return std::sqrt(sum);
}

// function to compute the l2 norm of a vector
double LinearEquationsSolver::computeL2Norm(const std::vector<double>& x) {
    double sum = 0.0;
    for (size_t i = 0; i < x.size(); i++) {
        // square each value and add to sum
        sum += x[i] * x[i];
    }
    // returns the length of the vector
    return std::sqrt(sum);
}

// function to print the vector in the desired format
void LinearEquationsSolver::printIteration(const std::vector<double>& x, int iter, double relativeError) {
    std::cout << "Iteration " << iter << ": ";
    std::cout << "[";

    for (size_t i = 0; i < x.size(); i++) {
        // print value with 4 decimal places
        std::cout << std::fixed << std::setprecision(4) << x[i];
        if (i != x.size() - 1)
            std::cout << " ";
    }
    // print relative error
    std::cout << "]T: " << relativeError << std::endl;
}

// jacobi iterative method function
std::vector<double> LinearEquationsSolver::jacobiMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b,
                            const std::vector<double>& x0, double tol, int maxIteration) {
    int n = b.size();

    // x_old is the previous guess, x_new is the updated guess
    std::vector<double> xOldValue = x0, xNewValue(n, 0.0);

    std::cout << "\n---Jacobi Iterative Method---" << std::endl;

    for (int iter = 1; iter <= maxIteration; iter++) {
        for (int i = 0; i < n; i++) {
            double sum = 0.0;

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    // use previous values only
                    sum += A[i][j] * xOldValue[j];
                }
            }
            // stop if diagonal element is zero
            if (A[i][i] == 0) {
                std::exit(1);
            }
            // update new value
            xNewValue[i] = (b[i] - sum) / A[i][i];
        }

        // difference between new and old
        double diff_norm = computeL2NormDiff(xNewValue, xOldValue);
        // size of new vector
        double x_new_norm = computeL2Norm(xNewValue);
        // calculate relative error
        double relativeError = (x_new_norm != 0) ? diff_norm / x_new_norm : diff_norm;

        // show current guess and error
        printIteration(xNewValue, iter, relativeError);

        if (relativeError < tol) {
            std::cout << "Desired error reached after " << iter << " iterations." << std::endl;
            // return result if error is small enough
            return xNewValue;
        }

        // update old for next iteration
        xOldValue = xNewValue;
    }
    std::cout << "Maximum iterations reached without achieving desired error." << std::endl;
    // return last result if max iteration reached
    return xOldValue;
}

// gauss-seidel iterative method function
std::vector<double> LinearEquationsSolver::gaussSeidelMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b,
                                 const std::vector<double>& x0, double tol, int maxIteration) {
    int n = b.size();

    // start with initial guess
    std::vector<double> x_old = x0, x_new = x0;

    std::cout << "\n---Gauss-Seidel Iterative Method---" << std::endl;
    for (int iter = 1; iter <= maxIteration; iter++) {
        for (int i = 0; i < n; i++) {
            double sum1 = 0.0, sum2 = 0.0;

            for (int j = 0; j < i; j++) {
                // use already updated values
                sum1 += A[i][j] * x_new[j];
            }
            for (int j = i + 1; j < n; j++) {
                // use old values
                sum2 += A[i][j] * x_old[j];
            }
            if (A[i][i] == 0) {
                std::cerr << "Error: Zero diagonal element encountered in row " << i << "." << std::endl;
                // stop if diagonal element is zero
                std::exit(EXIT_FAILURE);
            }

            // update value using both parts
            x_new[i] = (b[i] - sum1 - sum2) / A[i][i];
        }

        // calculate how much it changed
        double diff_norm = computeL2NormDiff(x_new, x_old);
        double x_new_norm = computeL2Norm(x_new);
        double rel_err = (x_new_norm != 0) ? diff_norm / x_new_norm : diff_norm;

        printIteration(x_new, iter, rel_err);
        // return result if good enough
        if (rel_err < tol) {
            std::cout << "Desired error reached after " << iter << " iterations." << std::endl;
            return x_new;
        }
        // prepare for next iteration
        x_old = x_new;
    }
    std::cout << "Maximum iterations reached without achieving desired error." << std::endl;
    return x_old;
}