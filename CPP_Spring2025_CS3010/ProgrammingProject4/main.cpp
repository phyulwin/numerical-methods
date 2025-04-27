/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: April 26th, 2025
 * Assignment: Programming Project 4
 * Program: Reads points from a text file and outputs the interpolating polynomial in newton and lagrange forms
 */

#include "InterpolatingPolynomial.h"

int main() {
    try {
        // test with sample input file from Canvas
        InterpolatingPolynomial::solve("input.txt");

        // test with input2.txt
        InterpolatingPolynomial::solve("input2.txt");

        // test with input3.txt
        InterpolatingPolynomial::solve("input3.txt");
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}