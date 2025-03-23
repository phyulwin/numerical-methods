/**
 * Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#ifndef KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_LINEAREQUATION_H
#define KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_LINEAREQUATION_H

#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include <string>

class LinearEquation {
private:
    static double promptAndParse(const std::string& prompt);
public:
    double a, b, c; // coefficients of x, y, z
    double constant;

    LinearEquation();
    LinearEquation(const double &a, const double &b, const double &c, const double &constant);
    static LinearEquation createEquation();
};

#endif //KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_LINEAREQUATION_H