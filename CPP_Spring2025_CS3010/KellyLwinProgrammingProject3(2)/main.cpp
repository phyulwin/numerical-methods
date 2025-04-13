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
    Helper::solveFunctionA();
    // calls solveFunctionB to handle the second function
    Helper::solveFunctionB();

    return 0;
}