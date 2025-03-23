/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 19th, 2025
 * Assignment: Programming Project 2
 * Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
 * to solve systems of linear equation
 */

#include "Helper.h"
#include "LinearEquationsSolver.h"
#include "LargeLinearSystem.h"

int main() {
    std::vector<LinearEquation> equations;
    char choice = 0;

    // Prompt the user for the input method
    while (choice != '1' && choice != '2') {
        std::cout << "Enter 1 to enter equations manually or 2 to enter a file name: ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
    }
    std::cin.ignore();  // clear newline

    // Get equation data based on the user's choice
    if (choice == '1') {
        Helper::getManualInput(equations);
    } else {
        Helper::getFileInput(equations);
    }

    // Use the new helper function to convert equations to matrix A, vector b,
    // and to get the stopping error and initial guess
    LinearSystem linearSystem = Helper::convertMatrix(equations);

    // Run the iterative methods
    LinearEquationsSolver::jacobiMethod(linearSystem.A, linearSystem.b, linearSystem.x0, linearSystem.error);
    LinearEquationsSolver::gaussSeidelMethod(linearSystem.A, linearSystem.b, linearSystem.x0, linearSystem.error);

    // Uncomment the following code to test program with large values of n
    // LargeLinearSystem::testLargeSystems();

    return 0;
}