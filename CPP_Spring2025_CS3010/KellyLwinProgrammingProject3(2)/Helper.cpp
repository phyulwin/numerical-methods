/**
* Name: Kelly Lwin
* Course: Numerical Methods (CS3010)
* Date: March 30th, 2025
* Assignment: Programming Project 3
* Program: The program implements and compares five numerical root-finding methods
* to locate the roots of two functions while generating iteration error data.
*/

#include "Helper.h"

// Function (a): f(x) = 2x^3 – 11.7x^2 + 17.7x – 5
double Helper::f1(double x) {
    return (2*std::pow(x, 3)) - (11.7*std::pow(x, 2)) + (17.7*x) - 5;
}

// Derivative of Function (a): 6x^2 - 23.4x + 17.7
double Helper::df1(double x) {
    return (6*std::pow(x, 2)) - (23.4*x) + 17.7;
}

// Function (b): f(x) = x + 10 - x*cosh(50/x)
double Helper::f2(double x) {
    return x + 10 - x * std::cosh(50.0/x);
}

// Derivative of Function (b): 1 - cosh(50/x) + (50/x)*sinh(50/x)
double Helper::df2(double x) {
    return 1 - std::cosh(50.0/x) + (50.0/x)*std::sinh(50.0/x);
}

void Helper::solveFunctionA() {
    const double TOLERANCE = 0.1;
    const int MAX_ITER = 100;

    std::cout << "(a): f(x) = 2x^3 - 11.7x^2 + 17.7x - 5" << std::endl;

    // First Root (Interval [0,1])
    std::cout << "\nRoot in the interval [0,1]\n" << std::endl;
    std::vector<double> errors_bis1, errors_new1, errors_sec1, errors_fp1, errors_modsec1;
    double root1_bis   = BracketingMethod::bisection(f1, 0.0, 1.0, TOLERANCE, MAX_ITER, errors_bis1);
    double root1_new   = NewtonRaphsonMethod::newtonRaphson(f1, df1, 0.5, TOLERANCE, MAX_ITER, errors_new1);
    double root1_sec   = SecantMethod::secant(f1, 0.0, 1.0, TOLERANCE, MAX_ITER, errors_sec1);
    double root1_fp    = BracketingMethod::falsePosition(f1, 0.0, 1.0, TOLERANCE, MAX_ITER, errors_fp1);
    double root1_modsec = SecantMethod::modifiedSecant(f1, 0.5, 0.01, TOLERANCE, MAX_ITER, errors_modsec1);

    // Second Root (Interval [1,2])
    std::cout << "\nRoot in the interval [1,2]\n" << std::endl;
    std::vector<double> errors_bis2, errors_new2, errors_sec2, errors_fp2, errors_modsec2;
    double root2_bis   = BracketingMethod::bisection(f1, 1.0, 2.0, TOLERANCE, MAX_ITER, errors_bis2);
    double root2_new   = NewtonRaphsonMethod::newtonRaphson(f1, df1, 1.5, TOLERANCE, MAX_ITER, errors_new2);
    double root2_sec   = SecantMethod::secant(f1, 1.0, 2.0, TOLERANCE, MAX_ITER, errors_sec2);
    double root2_fp    = BracketingMethod::falsePosition(f1, 1.0, 2.0, TOLERANCE, MAX_ITER, errors_fp2);
    double root2_modsec = SecantMethod::modifiedSecant(f1, 1.5, 0.01, TOLERANCE, MAX_ITER, errors_modsec2);;

    // Third Root (Interval [3,4])
    std::cout << "\nRoot in the interval [3,4]\n" << std::endl;
    std::vector<double> errors_bis3, errors_new3, errors_sec3, errors_fp3, errors_modsec3;
    double root3_bis   = BracketingMethod::bisection(f1, 3.0, 4.0, TOLERANCE, MAX_ITER, errors_bis3);
    double root3_new   = NewtonRaphsonMethod::newtonRaphson(f1, df1, 3.5, TOLERANCE, MAX_ITER, errors_new3);
    double root3_sec   = SecantMethod::secant(f1, 3.0, 4.0, TOLERANCE, MAX_ITER, errors_sec3);
    double root3_fp    = BracketingMethod::falsePosition(f1, 3.0, 4.0, TOLERANCE, MAX_ITER, errors_fp3);
    double root3_modsec = SecantMethod::modifiedSecant(f1, 3.5, 0.01, TOLERANCE, MAX_ITER, errors_modsec3);
}

void Helper::solveFunctionB() {
    const double TOLERANCE = 0.1;
    const int MAX_ITER = 100;

    std::cout << "(b): f(x) = x + 10 - x*cosh(50/x)" << std::endl;

    // create vector of errors for the root
    std::vector<double> errors_bis, errors_new, errors_sec, errors_fp, errors_modsec;

    // Root in the Interval [120,130]
    std::cout << "\nRoot in the interval [120,130]\n" << std::endl;
    double root_bis    = BracketingMethod::bisection(f2, 120, 130, TOLERANCE, MAX_ITER, errors_bis);
    double root_new    = NewtonRaphsonMethod::newtonRaphson(f2, df2, 125, TOLERANCE, MAX_ITER, errors_new);
    double root_sec    = SecantMethod::secant(f2, 120, 130, TOLERANCE, MAX_ITER, errors_sec);
    double root_fp     = BracketingMethod::falsePosition(f2, 120, 130, TOLERANCE, MAX_ITER, errors_fp);
    double root_modsec = SecantMethod::modifiedSecant(f2, 125, 0.01, TOLERANCE, MAX_ITER, errors_modsec);
}