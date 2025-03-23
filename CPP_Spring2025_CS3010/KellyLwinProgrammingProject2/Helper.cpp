/**
* Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 19th, 2025
 * Assignment: Programming Project 2
 * Program: Gaussian elimination with Jacobi Method and Gauss Seidel Method
 * to solve systems of linear equation
 */

#include "Helper.h"

LinearSystem Helper::convertMatrix(const std::vector<LinearEquation>& equations) {
    // get the number of equations
    int numEquations = equations.size();

    if (numEquations == 0) {
        std::cout << "no equations provided" << std::endl;
        exit(1);
    }

    // assume the system is square
    int numVars = equations[0].coefficients.size();

    // build matrix a and vector b from the equations
    std::vector<std::vector<double>> A;
    std::vector<double> b;
    for (int i = 0; i < numEquations; i++) {
        A.push_back(equations[i].coefficients); // add coefficients to matrix a
        b.push_back(equations[i].constant); // add constant to vector b
    }

    // ask for the desired stopping error
    double error;
    std::cout << "enter the desired stopping error: ";
    std::cin >> error;

    // ask for the initial guess
    std::vector<double> x0(numVars);
    std::cout << "enter the initial guess: ";
    for (int i = 0; i < numVars; i++) {
        std::cin >> x0[i];
    }

    // convert data into a linear system object
    LinearSystem data;
    data.A = A;
    data.b = b;
    data.error = error;
    data.x0 = x0;

    return data;
}

void Helper::getManualInput(std::vector<LinearEquation>& equations) {
    int n = 0;
    std::cout << "enter the number of equations: ";
    std::cin >> n;
    std::cin.ignore();

    // create each equation by asking the user for n coefficients
    for (int i = 0; i < n; ++i) {
        equations.push_back(LinearEquation::createEquation(n)); // add equation to list
    }
}

void Helper::getFileInput(std::vector<LinearEquation>& equations) {
    // ask user for filename
    std::string filename;
    std::cout << "enter file name: ";
    std::cin >> filename;

    // read file content
    std::ifstream file(filename);
    if (!file) {
        std::cout << "error opening file: " << filename << std::endl;
        return;
    }

    // number of coefficients per equation
    int numVars = 0;
    std::string line;
    bool firstLine = true;

    // read each line from the file
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // skip blank lines
        }

        std::istringstream iss(line);
        std::vector<double> numbers;
        double value;

        // read all numbers from the line
        while (iss >> value) {
            numbers.push_back(value);
        }

        // determine number of variables in the first equation
        if (firstLine) {
            numVars = numbers.size() - 1; // last number is constant
            firstLine = false;
        }

        // split the numbers into coefficients and constant
        std::vector<double> coefficients(numbers.begin(), numbers.begin() + numVars);
        double constant = numbers.back();

        equations.emplace_back(coefficients, constant); // add equation to list
    }
    file.close();
}