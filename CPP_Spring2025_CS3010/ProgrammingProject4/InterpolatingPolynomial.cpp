/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: April 26th, 2025
 * Assignment: Programming Project 4
 * Program: Reads points from a text file and outputs the interpolating polynomial in newton and lagrange forms
 */

#include "InterpolatingPolynomial.h"

// reads x and y-values from a text file into two separate vectors
void InterpolatingPolynomial::readData(const char* fileName, std::vector<double>& xValues, std::vector<double>& yValues) {
    // open the text file
    std::ifstream file(fileName);
    // stop if the file cannot be opened
    if (!file) {
        throw std::runtime_error("cannot open file");
    }
    // hold every number we read
    std::vector<double> allValues;
    double value;
    // read numbers until the end of the file
    while (file >> value) {
        allValues.push_back(value);
    }
    // there must be an even count of numbers (x and y pairs)
    if (allValues.size() % 2 != 0) {
        throw std::runtime_error("file contains an uneven number of values");
    }
    // find the halfway point in the vector
    std::size_t half = allValues.size() / 2;
    // copy the first half into xValues
    xValues.assign(allValues.begin(), allValues.begin() + half);
    // copy the second half into yValues
    yValues.assign(allValues.begin() + half, allValues.end());
}

// constructs the newton divided-difference table from the x and y vectors
std::vector<std::vector<double>> InterpolatingPolynomial::dividedDiff(const std::vector<double>& x, const std::vector<double>& y) {
    // number of data points
    int n = static_cast<int>(x.size());
    // 2-d table of size n × n filled with zeros
    std::vector<std::vector<double>> f(n, std::vector<double>(n));
    // first column is the original y values
    for (int i = 0; i < n; ++i) {f[i][0] = y[i];}
    // fill the table using the divided difference formula
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i)
            {f[i][j] = (f[i + 1][j - 1] - f[i][j - 1]) / (x[i + j] - x[i]);}
    }
    // return the completed table
    return f;
}

// outputs the divided-difference table with columns
void InterpolatingPolynomial::printTable(const std::vector<double>& x, const std::vector<std::vector<double>>& f) {
    const int width = 14;
    std::cout << '\n' << std::setw(width) << "x";
    // build and print header labels
    for (size_t col = 0; col < x.size(); ++col) {
        std::string label;
        if (col == 0) {
            label = "f[]";
        }
        else {
            label = "f[";
            label.append(col, ',');
            label += ']';
        }
        std::cout << std::setw(width) << label;
    } std::cout << '\n';
    // data rows
    for (size_t row = 0; row < x.size(); ++row)
    {
        // print the x value for this row
        std::cout << std::setw(width) << PolynomialHelper::convertDouble(x[row]);
        // print the remaining divided differences on the same diagonal
        for (size_t col = 0; col < x.size() - row; ++col) {
            std::cout << std::setw(width) << PolynomialHelper::convertDouble(f[row][col]);
        } std::cout << '\n';
    }
}

// prints the interpolating polynomial in newton’s nested form
void InterpolatingPolynomial::printNewtonPoly(const std::vector<double>& x, const std::vector<std::vector<double>>& f) {
    // print the constant term a0
    std::cout << PolynomialHelper::convertDouble(f[0][0]);
    // loop over each remaining coefficient ak
    for (int k = 1; k < static_cast<int>(x.size()); ++k) {
        // choose plus or minus sign for ak and print absolute value of ak
        std::cout << (f[0][k] >= 0 ? " + " : " - ") << PolynomialHelper::convertDouble(std::fabs(f[0][k]));
        // loop over roots already processed and print each (x - xj) factor
        for (int j = 0; j < k; ++j) {
            std::cout << "(x " << (x[j] >= 0 ? "- " : "+ ") << PolynomialHelper::convertDouble(std::fabs(x[j])) << ')';
        }
    }
}

// prints the interpolating polynomial in lagrange form
void InterpolatingPolynomial::printLagrangePoly(const std::vector<double>& x, const std::vector<double>& y) {
    // number of data points
    const int n = static_cast<int>(x.size());
    // loop over each term li
    for (int i = 0; i < n; ++i) {
        // add plus sign after the first term
        if (i) {std::cout << " + ";}
        // start bracket for li
        std::cout << "[ ";
        // numerator factors (x − xj) for j not i
        for (int j = 0; j < n; ++j) {
            if (j != i) {std::cout << "(x - " << PolynomialHelper::convertDouble(x[j]) << ')';}
        }
        // slash separating numerator and denominator
        std::cout << " / ";
        // denominator factors (xi − xj) for j not i
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                std::cout << '(' << PolynomialHelper::convertDouble(x[i]) << " - " << PolynomialHelper::convertDouble(x[j]) << ')';
            }
        }
        // close bracket and multiply by yi value
        std::cout << " ] * " << PolynomialHelper::convertDouble(y[i]);
    }
}

// prints the fully expanded polynomial with combined like terms
void InterpolatingPolynomial::printSimplified(const std::vector<double>& coefficients) {
    // flag for first term
    bool first = true;
    // loop through coefficients high to low
    for (int k = static_cast<int>(coefficients.size())-1; k >= 0; --k) {
        // skip coefficients that are zero or too small
        if (std::fabs(coefficients[k]) < 1e-12) continue;
        // print sign before every term except the first
        if (!first) std::cout << (coefficients[k] >= 0 ? " + " : " - ");
        // print the absolute coefficient as a tidy string
        std::cout << PolynomialHelper::convertDouble(std::fabs(coefficients[k]));
        // print x if power is at least 1
        if (k >= 1) {std::cout << "x";}
        // print exponent if power is greater than 1
        if (k > 1) std::cout << '^' << k;
        // mark that the first term is done
        first = false;
    }
    std::cout << '\n';
}

// loads data, builds table, and prints different polynomial forms
void InterpolatingPolynomial::solve(const char* dataFile) {
    // read x and y values from the file
    std::vector<double> xValues, yValues;
    readData(dataFile, xValues, yValues);

    // build the divided difference table
    std::vector<std::vector<double>> diffTable = dividedDiff(xValues, yValues);

    // print the table of divided differences
    printTable(xValues, diffTable);

    // print the polynomial in newton form
    std::cout << "\nInterpolating polynomial (Newton form):\n";
    printNewtonPoly(xValues, diffTable); std::cout << "\n";

    // print the polynomial in lagrange form
    std::cout << "\nInterpolating polynomial (Lagrange form):\n";
    printLagrangePoly(xValues, yValues); std::cout << "\n";

    // build the simplified polynomial coefficients
    std::vector<double> simplifiedCoeffs = PolynomialHelper::buildSimplified(xValues, diffTable);
    // print the simplified polynomial
    std::cout << "\nSimplified polynomial:\n";
    printSimplified(simplifiedCoeffs); std::cout << "\n";
}