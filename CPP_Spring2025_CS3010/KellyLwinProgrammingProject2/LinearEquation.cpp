/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 19th, 2025
 * Assignment: Programming Project 2
 * Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
 * to solve systems of linear equation
 */

#include "LinearEquation.h"

// default constructor sets constant to 0 and leaves coefficients empty
LinearEquation::LinearEquation() : constant(0.0) { }

// constructor that sets coefficients and constant from input
LinearEquation::LinearEquation(const std::vector<double>& coeffs, double constant)
    : coefficients(coeffs), constant(constant) { }

// asks the user to enter values for coefficients and constant
LinearEquation LinearEquation::createEquation(int numVars) {
    std::vector<double> coefficients;
    // ask for each coefficient based on number of variables
    for (int i = 0; i < numVars; i++) {
        std::string prompt = "Enter coefficient for x" + std::to_string(i+1) + ": ";
        double value = promptAndParse(prompt); // get the number from user
        coefficients.push_back(value);
    }
    double constantTerm = promptAndParse("Enter the constant term: ");

    // show the full equation back to the user
    std::cout << "The equation you have entered is: ";
    for (int i = 0; i < numVars; i++) {
        std::cout << coefficients[i] << "x" << (i+1);
        if (i < numVars - 1) {
            std::cout << " + ";
        }
    }
    std::cout << " = " << constantTerm << std::endl;

    return LinearEquation(coefficients, constantTerm);
}

// asks the user for input and tries to read a number or fraction
double LinearEquation::promptAndParse(const std::string& prompt) {
    std::string input;
    double value = 0;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::istringstream iss(input);

        double numerator = 0;
        char slashOperator;
        double denominator = 1;

        // check if the input is a fraction
        if (input.find('/') != std::string::npos) {
            if (iss >> numerator >> slashOperator >> denominator && slashOperator == '/' && denominator != 0) {
                value = numerator / denominator; // convert fraction to decimal
                validInput = true;
            } else {
                std::cout << "invalid fraction" << std::endl;
            }
        } else {
            // if not a fraction, try to read a normal number
            if (iss >> value) {
                validInput = true;
            } else {
                std::cout << "invalid input" << std::endl;
            }
        }
    }
    return value;
}