/**
* Name: Kelly Lwin
* Course: Numerical Methods (CS3010)
* Date: March 19th, 2025
* Assignment: Programming Project 2
* Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
* to solve systems of linear
* EXTRA CREDIT FILE
*/

#include "LargeLinearSystem.h"

void LargeLinearSystem::testLargeSystems() {
    std::vector<int> sizes = {20, 50, 100};

    double error = 1e-6;
    int maxIterations = 100;

    // seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // temporarily suppress std::cout output
    std::streambuf* originalCoutBuffer = std::cout.rdbuf();
    std::ostringstream dummyStream;

    for (int n : sizes) {
        std::vector<std::vector<double>> A(n, std::vector<double>(n));
        std::vector<double> b(n);
        std::vector<double> x0(n, 0.0); // initial guess = all zeros

        // generate diagonally dominant matrix A and vector b
        for (int i = 0; i < n; i++) {
            double rowSum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    // random number between -10 and 10
                    A[i][j] = (std::rand() % 2001 - 1000) / 100.0;
                    rowSum += std::abs(A[i][j]);
                }
            }
            // check diagonal dominance
            A[i][i] = rowSum + (std::rand() % 1001) / 100.0 + 10.0;
            b[i] = (std::rand() % 2001 - 1000) / 100.0;
        }

        std::cout.rdbuf(dummyStream.rdbuf()); // suppress output

        auto startJacobi = std::chrono::high_resolution_clock::now();
        LinearEquationsSolver::jacobiMethod(A, b, x0, error, maxIterations);
        auto endJacobi = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationJacobi = endJacobi - startJacobi;

        auto startGS = std::chrono::high_resolution_clock::now();
        LinearEquationsSolver::gaussSeidelMethod(A, b, x0, error, maxIterations);
        auto endGS = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationGS = endGS - startGS;

        std::cout.rdbuf(originalCoutBuffer); // restore output

        // show timing results only
        std::cout << "\nn = " << n << ":\n";
        std::cout << "jacobi time: " << durationJacobi.count() << " seconds\n";
        std::cout << "gauss-seidel time: " << durationGS.count() << " seconds\n";
    }
}

/*
 * reference used for suppressing output streams temporarily:
 * https://cplusplus.com/forum/general/283883/
 */