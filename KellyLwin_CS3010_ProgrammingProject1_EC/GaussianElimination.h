/**
 * Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#ifndef KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_GAUSSIANELIMINATION_H
#define KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_GAUSSIANELIMINATION_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "LinearEquation.h"

class GaussianElimination {
private:
    // Instance Variables
    int n;  // Number of equations
    std::vector<std::vector<double>> A;  // Augmented matrix
    std::vector<double> scaleFactors;  // Scaling factors for pivoting
    std::vector<double> solution;  // Final solution vector

    void initializeMatrix(std::vector<LinearEquation>& equations);
    void performGaussianElimination();

    void swapRows(int pivotRow, int k);
    void forwardElimination(int k);
    void intermediateMatrix(int k);
    void backSubstitution();
    void printFinalSolution();

public:
    GaussianElimination(); // Constructor
    void solveLinearEquations(std::vector<LinearEquation>& equations);
};

#endif //KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_GAUSSIANELIMINATION_H