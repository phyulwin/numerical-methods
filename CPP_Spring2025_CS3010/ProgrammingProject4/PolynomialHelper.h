/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: April 26th, 2025
 * Assignment: Programming Project 4
 * Program: Reads points from a text file and outputs the interpolating polynomial in newton and lagrange forms
 */

#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <cmath>

class PolynomialHelper {
public:
      // converts a double into an integer, fraction, or decimal string
      static std::string convertDouble(double input);
      // multiplies a polynomial by the linear factor (x − root)
      static std::vector<double> polyTimesLinear(const std::vector<double>& oldPoly, double root);
      // builds and returns the expanded polynomial coefficients from the divided-difference table
      static std::vector<double> buildSimplified(const std::vector<double>& x, const std::vector<std::vector<double>>& f);
};

#endif //MATHHELPER_H
