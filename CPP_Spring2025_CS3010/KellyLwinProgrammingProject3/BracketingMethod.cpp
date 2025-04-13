/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 30th, 2025
 * Assignment: Programming Project 3
 * Program: The program implements and compares five numerical root-finding methods
 * to locate the roots of two functions while generating iteration error data.
 */

#include "BracketingMethod.h"

// bisection method - computes a root by halving the interval
double BracketingMethod::bisection(double (*f)(double), double a, double b,
 double tolerance, int maxIter, std::vector<double>& errors) {
     // check if function values have opposite signs
     if(f(a)*f(b) >= 0) {
      std::cout << "error: f(a) and f(b) must have opposite signs.\n";
      exit(1);
     }

     // initialize the midpoint c to the lower bound a
     double c = a;

     for (int i = 0; i < maxIter; i++) {
      // store the previous midpoint for error calculation
      double previous = c;

      // update c - average of the current interval endpoints
      c = (a + b) / 2.0;

      // if not the first iteration compute the approximate relative error as the absolute value
      // of the difference between c and previous divided by c times one hundred
      if(i > 0) {
       double approxError = std::fabs((c - previous) / c) * 100;
       errors.push_back(approxError);

       // if error is below tolerance return c
       if(approxError < tolerance) {
        std::cout << "converged in " << i+1 << " iterations\n";
        return c;
       }
      }

      // update interval based on sign change
      if(f(a) * f(c) < 0)
       b = c;
      else
       a = c;
     }
     std::cout << "did not converge after maximum iterations\n";
     return c;
}

// false-position method - computes a root using a linear interpolation approach
double BracketingMethod::falsePosition(double (*f)(double), double a, double b,
 double tolerance, int maxIter, std::vector<double>& errors) {
     // check if endpoints bracket a root: f(a) and f(b) have opposite signs
     if(f(a)*f(b) >= 0) {
       std::cout << "error: f(a) and f(b) must have opposite signs.\n";
       exit(1);
     }

     // initialize the midpoint c to the lower bound a
     double c = a;

     for (int i = 0; i < maxIter; i++) {
      // store the previous estimate for error calculation
      double previous = c;

      // compute new approximation c
      c = b - f(b) * (a - b) / (f(a) - f(b));

      // if not the first iteration
      // compute the approximate relative error
      if(i > 0) {
          double ea = std::fabs((c - previous) / c) * 100;
          errors.push_back(ea);

          // if error falls below tolerance, return c
          if(ea < tolerance) {
           std::cout << "converged in " << i+1 << " iterations\n";
           return c;
          }
      }
      // update the interval based on the sign change between f(a) and f(c)
      if(f(a) * f(c) < 0) {b = c;}
      else {a = c;}
     }
     std::cout << "did not converge after maximum iterations\n";
     return c;
}