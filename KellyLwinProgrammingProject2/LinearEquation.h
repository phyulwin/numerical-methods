/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 19th, 2025
 * Assignment: Programming Project 2
 * Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
 * to solve systems of linear equation
 */

#ifndef LINEAREQUATION_H
#define LINEAREQUATION_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

class LinearEquation {
private:
    // helper function to ask the user and get a number from input
    static double promptAndParse(const std::string& prompt);
public:
    std::vector<double> coefficients; // stores the coefficients of the equation
    double constant; // stores the constant term

    // default constructor
    LinearEquation();
    // constructor that takes coefficients and a constant
    LinearEquation(const std::vector<double>& coefficients, double constant);

    // creates an equation by asking the user to input values
    // numVars is how many variables the equation has
    static LinearEquation createEquation(int numVars);
};

#endif //LINEAREQUATION_H