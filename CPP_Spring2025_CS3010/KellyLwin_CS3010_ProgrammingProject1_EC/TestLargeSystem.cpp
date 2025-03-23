/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#include "TestLargeSystem.h"

// Generates a random augmented matrix of size n x (n+1)
std::vector<LinearEquation> TestLargeSystem::generateRandomEquations(int n) {
    std::vector<LinearEquation> equations;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0);

    for (int i = 0; i < n; ++i) {
     // Generate n coefficients and 1 constant term
     std::vector<double> coeffs;
     for (int j = 0; j < n; ++j) {
      coeffs.push_back(dis(gen));
     }
     double constant = dis(gen);

     // This part is a workaround to use existing LinearEquation class
     // Note: For n > 3, your class structure would need to be generalized
     LinearEquation eq;
     eq.a = coeffs[0];
     eq.b = (n > 1) ? coeffs[1] : 0;
     eq.c = (n > 2) ? coeffs[2] : 0;
     eq.constant = constant;

     equations.push_back(eq);
    }

    return equations;
}

// Function to run test for varying sizes
void TestLargeSystem::testLargeSystem() {
 std::vector<int> testSizes = {20, 50, 100};

 for (int n : testSizes) {
  std::cout << "\nn = " << n << ":\n";
  auto equations = generateRandomEquations(n);
  GaussianElimination solver;

  // Suppress std::cout
  std::streambuf* originalCout = std::cout.rdbuf();
  std::ostringstream dummyBuffer;
  std::cout.rdbuf(dummyBuffer.rdbuf());

  auto start = std::chrono::high_resolution_clock::now();
  solver.solveLinearEquations(equations);
  auto end = std::chrono::high_resolution_clock::now();

  // Restore std::cout
  std::cout.rdbuf(originalCout);

  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Gaussian Elimination with Scaled partial pivoting method time: " << n << ": " << elapsed.count() << " seconds\n";
 }
}