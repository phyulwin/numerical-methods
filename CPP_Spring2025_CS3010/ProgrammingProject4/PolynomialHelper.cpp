/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: April 26th, 2025
 * Assignment: Programming Project 4
 * Program: Reads points from a text file and outputs the interpolating polynomial in newton and lagrange forms
 */

#include "PolynomialHelper.h"

// converts a double into an integer, fraction, or decimal string
std::string PolynomialHelper::convertDouble(double input) {
    // max denominator
    const int den_limit = 20;
    // string builder
    std::ostringstream out;
    // small tolerance for equality
    const double eps = 1e-10;
    // nearest integer to v
    long long integer = std::llround(input);

    // check if v is already an integer
    if (std::fabs(input - integer) < eps) {
        // store integer
        out << integer;
        return out.str();
    }

    // search for a simple fraction p / q
    for (int q = 1; q <= den_limit; ++q) {
        // numerator rounded
        long long p = std::llround(input * q);
        // verify p / q is close to v
        if (std::fabs(input - static_cast<double>(p) / q) < eps) {
            // reduce fraction
            long long g = std::gcd(p, static_cast<long long>(q));
            // store reduced fraction
            out << (p / g) << '/' << (q / g);
            return out.str();
        }
    }
    // fallback to decimal with four digits
    out << std::fixed << std::setprecision(4) << input;
    return out.str();
}

// multiplies a polynomial by the linear factor (x - root)
std::vector<double> PolynomialHelper::polyTimesLinear(const std::vector<double>& oldPoly, double root) {
    // result has one higher degree
    std::vector<double> newPoly(oldPoly.size() + 1);

    // copy the highest term
    newPoly.back() = oldPoly.back();

    // synthetic multiplication
    for (int k = static_cast<int>(oldPoly.size()) - 1; k >= 0; --k) {
        // scale term by -root
        newPoly[k] += (-root) * oldPoly[k];
        // add lower-order term
        if (k) newPoly[k] += oldPoly[k - 1];
    }
    return newPoly;
}

// builds the expanded polynomial coefficients from the divided difference table
std::vector<double> PolynomialHelper::buildSimplified(const std::vector<double>& x, const std::vector<std::vector<double>>& f) {
    // start with constant term
    std::vector<double> poly = {f[0][0]};

    // add each successive divided difference
    for (int k = 1; k < static_cast<int>(x.size()); ++k) {
        // multiply by (x - x_{k-1})
        poly = polyTimesLinear(poly, x[k - 1]);
        // add a_k to constant
        poly[0] += f[0][k];
    }
    return poly;
}