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

// Function (b): f(x) = x + 10 – x*cosh(50/x)
double Helper::f2(double x) {
    return x + 10 - x * std::cosh(50.0/x);
}

// Derivative of Function (b): 1 - cosh(50/x) + (50/x)*sinh(50/x)
double Helper::df2(double x) {
    return 1 - std::cosh(50.0/x) + (50.0/x)*std::sinh(50.0/x);
}

// print and remove items in the vector
void Helper::print(std::vector<double> &errors) {
    std::cout << "Error at each iteration: ";
    for(const double error : errors) {
        std::cout << error << " ";
    }
    std::cout << "\n";
    // remove elements in the vector
    errors.clear();
}

// solve function (a): f(x) = 2x^3 - 11.7x^2 + 17.7x - 5
void Helper::solveFunctionA() {
    const double TOLERANCE = 0.1;
    const int MAX_ITER = 100;

    std::vector<double> errors;

    // Bisection Method
    std::cout << "Bisection Method\n";
    double root1_bis = BracketingMethod::bisection(f1, 0.0, 1.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root in [0,1]: " << root1_bis << "\n";
    print(errors);

    double root2_bis = BracketingMethod::bisection(f1, 1.0, 2.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root in [1,2]: " << root2_bis << "\n";
    print(errors);

    double root3_bis = BracketingMethod::bisection(f1, 3.0, 4.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root in [3,4]: " << root3_bis << "\n";
    print(errors);

    // Newton-Raphson Method
    std::cout << "\nNewton-Raphson Method\n";
    double root1_new = NewtonRaphsonMethod::newtonRaphson(f1, df1, 0.5, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guess 0.5): " << root1_new << "\n";
    print(errors);

    double root2_new = NewtonRaphsonMethod::newtonRaphson(f1, df1, 1.5, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guess 1.5): " << root2_new << "\n";
    print(errors);

    double root3_new = NewtonRaphsonMethod::newtonRaphson(f1, df1, 3.5, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guess 3.5): " << root3_new << "\n";
    print(errors);

    // Secant Method
    std::cout << "\nSecant Method\n";
    double root1_sec = SecantMethod::secant(f1, 0.0, 1.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guesses 0 and 1): " << root1_sec << "\n";
    print(errors);

    double root2_sec = SecantMethod::secant(f1, 1.0, 2.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guesses 1 and 2): " << root2_sec << "\n";
    print(errors);

    double root3_sec = SecantMethod::secant(f1, 3.0, 4.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guesses 3 and 4): " << root3_sec << "\n";
    print(errors);

    // False-Position Method
    std::cout << "\nFalse Position Method\n";
    double root1_fp = BracketingMethod::falsePosition(f1, 0.0, 1.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root in [0,1]: " << root1_fp << "\n";
    print(errors);

    double root2_fp = BracketingMethod::falsePosition(f1, 1.0, 2.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root in [1,2]: " << root2_fp << "\n";
    print(errors);

    double root3_fp = BracketingMethod::falsePosition(f1, 3.0, 4.0, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root in [3,4]: " << root3_fp << "\n";
    print(errors);

    // Modified Secant Method for f1 (δ = 0.01)
    std::cout << "\nModified Secant Method\n";
    double root1_modsec = SecantMethod::modifiedSecant(f1, 0.5, 0.01, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guess 0.5): " << root1_modsec << "\n";
    print(errors);

    double root2_modsec = SecantMethod::modifiedSecant(f1, 1.5, 0.01, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guess 1.5): " << root2_modsec << "\n";
    print(errors);

    double root3_modsec = SecantMethod::modifiedSecant(f1, 3.5, 0.01, TOLERANCE, MAX_ITER, errors);
    std::cout << "(initial guess 3.5): " << root3_modsec << "\n";
    print(errors);
}

// solve function (b): f(x) = x + 10 - x*cosh(50/x)
void Helper::solveFunctionB() {
    const double TOLERANCE = 0.1;
    const int MAX_ITER = 100;

    std::vector<double> errors;

    // The root for f2 lies in the interval [120,130]
    // Bisection Method
    std::cout << "Bisection Method\n";
    double root_bis_f2 = BracketingMethod::bisection(f2, 120, 130, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root: " << root_bis_f2 << "\n";
    print(errors);

    // Newton-Raphson Method (initial guess 125)
    std::cout << "\nNewton-Raphson Method\n";
    double root_new_f2 = NewtonRaphsonMethod::newtonRaphson(f2, df2, 125, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root: " << root_new_f2 << "\n";
    print(errors);

    // Secant Method (initial guesses 120 and 130)
    std::cout << "\nSecant Method\n";
    double root_sec_f2 = SecantMethod::secant(f2, 120, 130, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root: " << root_sec_f2 << "\n";
    print(errors);

    // False-Position Method
    std::cout << "\nFalse-Position Method\n";
    double root_fp_f2 = BracketingMethod::falsePosition(f2, 120, 130, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root: " << root_fp_f2 << "\n";
    print(errors);

    // Modified Secant Method (δ = 0.01, initial guess 125)
    std::cout << "\nModified Secant Method\n";
    double root_modsec_f2 = SecantMethod::modifiedSecant(f2, 125, 0.01, TOLERANCE, MAX_ITER, errors);
    std::cout << "Root: " << root_modsec_f2 << "\n";
    print(errors);
}