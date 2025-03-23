/**
 * Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#include "Helper.h"

void Helper::getManualInput(std::vector<LinearEquation>& equations) {
    int n = 0;
    std::cout << "Enter the number of linear equations to solve: ";

    // read until a valid number is entered
    while (!(std::cin >> n)) {
        std::cout << "Invalid input. Please enter a numeric value: ";
        std::cin.clear();  // clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard invalid input
    }

    // remove any leftover newline after reading the number
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // create linear equations based on input
    for (int i = 0; i < n; ++i) {
        equations.push_back(LinearEquation::createEquation());
    }
}

void Helper::getFileInput(std::vector<LinearEquation>& equations) {
    std::string filename;
    std::cout << "Enter file name: ";
    // expected input file name: linear_equations.txt
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    // reset file stream to the beginning to parse the equations
    file.clear();
    file.seekg(0, std::ios::beg);  // move to the beginning of the file

    double a, b, c, constant;
    // read equations from the file
    while (file >> a >> b >> c >> constant) {
        equations.emplace_back(a, b, c, constant);
    }

    file.close();
}