/**
 * Name: Kelly Lwin
 * Course: Numerical Methods (CS3010)
 * Date: March 13th, 2025
 * Assignment: Programming Project 1
 * Program: Gaussian elimination with scaled partial pivoting method
 * to solve systems of linear equation
 */

#ifndef KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_HELPER_H
#define KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_HELPER_H

#include <fstream>

#include "LinearEquation.h"

class Helper {
public:
    static void getManualInput(std::vector<LinearEquation>& equations);
    static void getFileInput(std::vector<LinearEquation>& equations);
};

#endif //KELLYLWIN_CS3010_PROGRAMMINGPROJECT1_HELPER_H
