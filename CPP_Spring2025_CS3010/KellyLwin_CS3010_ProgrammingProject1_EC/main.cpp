/**
 * Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#include "Helper.h"
#include "GaussianElimination.h"
#include "TestLargeSystem.h"

int main() {
    std::vector<LinearEquation> equations;
    char choice = 0;

    // prompt user for input method
    while (choice != '1' && choice != '2') {
        std::cout << "Enter 1 to enter equations manually or 2 to enter a file name: ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }

    // handle user based on user's choice
    if (choice == '1') {
        Helper::getManualInput(equations);
    } else {
        Helper::getFileInput(equations);
    }

    // solve equations
    GaussianElimination solver;
    solver.solveLinearEquations(equations);

    // // Extra Credit: Programming Assignment 2
    // TestLargeSystem::testLargeSystem();

    return 0;
}