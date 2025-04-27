/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: April 26th, 2025
 * Assignment: Programming Project 4
 * Program: Reads points from a text file and outputs the interpolating polynomial in newton and lagrange forms
 */

#ifndef INTERPOLATINGPOLYNOMIAL_H
#define INTERPOLATINGPOLYNOMIAL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cmath>

#include "PolynomialHelper.h"

class InterpolatingPolynomial {
private:
    // reads x- and y-values from a text file into two separate vectors
    static void  readData(const char *file, std::vector<double>& x, std::vector<double>& y);
    // constructs and returns the newton divided-difference table from the x and y vectors
    static std::vector<std::vector<double>> dividedDiff(const std::vector<double>& x, const std::vector<double>& y);

    // outputs the divided-difference table with columns
    static void printTable(const std::vector<double>& x, const std::vector<std::vector<double>>& f);

    // prints the interpolating polynomial in newton’s nested form
    static void printNewtonPoly(const std::vector<double>& x, const std::vector<std::vector<double>>& f);
    // prints the interpolating polynomial in lagrange form
    static void printLagrangePoly(const std::vector<double>& x, const std::vector<double>& y);
    // prints the fully expanded polynomial with combined like terms
    static void printSimplified(const std::vector<double>& coefficient);
public:
    // loads data, builds table, and prints different polynomial forms
    static void solve(const char *dataFile);
};

#endif