/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 30th, 2025
 * Assignment: Programming Project 3
 * Program: The program implements and compares five numerical root-finding methods
 * to locate the roots of two functions while generating iteration error data.
 */

// includes the helper header for root finding solutions
#include "Helper.h"

int main() {
    // calls solveFunctionA to handle the first function
    std::cout << "(a): f(x) = 2x^3 - 11.7x^2 + 17.7x - 5\n";
    Helper::solveFunctionA();

    // calls solveFunctionB to handle the second function
    std::cout << "\n(b): f(x) = x + 10 - x*cosh(50/x)\n";
    Helper::solveFunctionB();

    return 0;
}