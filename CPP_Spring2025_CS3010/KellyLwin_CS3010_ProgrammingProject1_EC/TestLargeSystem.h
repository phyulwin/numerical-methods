/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#ifndef TESTLARGESYSTEM_H
#define TESTLARGESYSTEM_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "GaussianElimination.h"

class TestLargeSystem {
      private:
          // Generates a random augmented matrix of size n x (n+1)
          static std::vector<LinearEquation> generateRandomEquations(int n);
      public:
          // Function to run test for varying sizes
          static void testLargeSystem();
};

#endif //TESTLARGESYSTEM_H