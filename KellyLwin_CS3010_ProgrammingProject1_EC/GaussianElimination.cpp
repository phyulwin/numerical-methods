/**
 * Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#include "GaussianElimination.h"

GaussianElimination::GaussianElimination() : n(0) {}

void GaussianElimination::solveLinearEquations(std::vector<LinearEquation>& equations) {
    // set the number of equations
    n = equations.size();

    // check if any equations are provided
    if (n == 0) {
        std::cout << "No equations provided.\n";
        return;
    }

    // resize the augmented matrix to hold all equations
    A.assign(n, std::vector<double>(n + 1)); // augmented matrix (includes RHS)
    scaleFactors.assign(n, 0); // scaling factors for partial pivoting
    solution.assign(n, 0); // solution vector initialized to zero

    // initialize the matrix with the equations' coefficients
    initializeMatrix(equations);
    // perform the Gaussian elimination process
    performGaussianElimination();
    // solve the upper triangular matrix
    backSubstitution();
    // print the solutions to the system of equations
    printFinalSolution();
}

// set up the augmented matrix with equations
void GaussianElimination::initializeMatrix(std::vector<LinearEquation>& equations) {
    for (int i = 0; i < n; i++) {
        A[i][0] = equations[i].a; // set coefficient of x
        A[i][1] = equations[i].b; // set coefficient of y
        A[i][2] = equations[i].c; // set coefficient of z
        A[i][3] = equations[i].constant; // set constant term

        // compute scale factor using max absolute value in each row for pivoting
        scaleFactors[i] = std::max(std::abs(A[i][0]), std::max(std::abs(A[i][1]), std::abs(A[i][2])));
    }
}

// perform the full gaussian elimination process
void GaussianElimination::performGaussianElimination() {
    for (int k = 0; k < n - 1; k++) {
        // hold scaled ratios for pivot selection
        std::vector<double> ratios(n);
        // calculate scaled ratios for pivoting
        for (int i = k; i < n; i++) {
            ratios[i] = std::abs(A[i][k]) / scaleFactors[i];
        }

        // find pivot row with max ratio and swap if necessary
        int pivotRow = k;
        for (int i = k + 1; i < n; i++) {
            if (ratios[i] > ratios[pivotRow]) {
                pivotRow = i;
            }
        }
        // swap rows based on pivot found
        swapRows(pivotRow, k);

        // show step results and pivot choice
        std::cout << "Step " << (k + 1) << ":\nSelected Pivot Row: " << (pivotRow + 1) << "\n";
        std::cout << "Scaled Ratios: ";
        for (double r : ratios) {
            // four decimals places
            std::cout << std::fixed << std::setprecision(4) << r << " ";
        }
        std::cout << "\n";

        // proceed with elimination for this column
        forwardElimination(k);
        intermediateMatrix(k);
    }
}

// swap two rows
void GaussianElimination::swapRows(int pivotRow, int k) {
    if (pivotRow != k) {
        std::swap(A[k], A[pivotRow]); // swap entire rows in the matrix
        std::swap(scaleFactors[k], scaleFactors[pivotRow]); // swap scale factors
    }
}

// reduce matrix to upper triangular form
void GaussianElimination::forwardElimination(int k) {
    for (int i = k + 1; i < n; i++) {
        // get factor to multiply rows
        double factor = A[i][k] / A[k][k];
        for (int j = k; j <= n; j++) {
            // subtract to make lower elements zero
            A[i][j] -= factor * A[k][j];
        }
    }
}

// display the matrix after each elimination step
void GaussianElimination::intermediateMatrix(int k) {
    std::cout << "Matrix after Step " << k + 1 << ":\n";
    for (const auto& row : A) {
        for (double val : row) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(4) << val << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// solve the equations using back substitution from the last row to top row
void GaussianElimination::backSubstitution() {
    for (int i = n - 1; i >= 0; i--) {
        // start with the constant term
        double sum = A[i][n];
        for (int j = i + 1; j < n; j++) {
            // subtract known values
            sum -= A[i][j] * solution[j];
        }
        // divide by the coefficient of the variable
        solution[i] = sum / A[i][i];
    }
}

// print the variables with their solved values
void GaussianElimination::printFinalSolution() {
    std::cout << "Final Solution:\n";
    // start variable name with x
    char var = 'x';
    for (double sol : solution) {
        std::cout << var++ << " = " << std::fixed << std::setprecision(4) << sol << "\n";
    }
}