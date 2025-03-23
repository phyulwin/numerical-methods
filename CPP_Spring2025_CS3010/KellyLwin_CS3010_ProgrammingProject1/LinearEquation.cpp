/**
 * Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#include "LinearEquation.h"

// default constructor initialize coefficients to zero
LinearEquation::LinearEquation() :
        LinearEquation(0, 0, 0, 0){}

// constructor set coefficients and constant term
LinearEquation::LinearEquation(const double &a, const double &b, const double &c, const double &constant) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->constant = constant;
}

// method to create a linear equation by prompting user for coefficients
LinearEquation LinearEquation::createEquation() {
    double a = promptAndParse("Enter coefficient for x: ");
    double b = promptAndParse("Enter coefficient for y: ");
    double c = promptAndParse("Enter coefficient for z: ");
    double constantTerm = promptAndParse("Enter the constant term: ");

    // display the input equation
    std::cout << "The equation you have entered is: " << a << "x + " << b
              << "y + " << c << "z = " << constantTerm << std::endl;

    // return a new linear equation instance
    return LinearEquation(a, b, c, constantTerm);
}

// method to prompt user and parse input
double LinearEquation::promptAndParse(const std::string& prompt) {
    std::string input;
    double value = 0;
    bool validInput = false;

    // loop until a valid input is received
    while (!validInput) {
        std::cout << prompt;
        // read the entire line of input
        std::getline(std::cin, input);
        std::istringstream iss(input);

        double numerator = 0;
        char op;
        double denominator = 1;

        // find '/' character to check for fraction input
        if (input.find('/') != std::string::npos) {
            // parse input as a fraction
            if (iss >> numerator >> op >> denominator && op == '/' && denominator != 0) {
                value = numerator / denominator; // calculate fractional value
                validInput = true;
            } else {
                // handle errors in fraction format
                if (denominator == 0) {
                    std::cout << "Invalid input: division by zero.";
                } else {
                    std::cout << "Invalid fraction.";
                }
            }
        } else {
            // process standard numeric input
            if (iss >> value) {
                validInput = true;
            } else {
                std::cout << "Invalid input.";
            }
        }
    }
    return value;
}