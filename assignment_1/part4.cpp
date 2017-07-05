//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/part1.cpp 
/// @brief Assignment 1 for CS 12 Fall 2015<quarter & year>
///
/// @author Thomas Shiels tshie001@ucr.edu [fake@email.com]
/// @date <Current date>
///
/// @par Enrollment Notes 
///     Lecture Section: <e.g. 001>
/// @par
///     Lab Section: <e.g. 021>
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

double randFloat(double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

double rand_mv(double mean, double var)
{
    double limitA = 0;
    double limitB = 0;
    
    limitA = ((mean * 2) - sqrt((12 * var))) / 2;
    limitB = ((mean * 2) + sqrt((12 * var))) / 2;
    
    cout << limitA << ' ' << limitB << endl;
    
    return randFloat(limitA, limitB);
}

int main()
{
    srand(333);
    double mean = 0;
    double variance = 0;
    
    cout << "Enter mean: ";
    cin >> mean;
    cout << endl;
    cout << "Enter variance: ";
    cin >> variance;
    
    cout << rand_mv(mean, variance) << endl;
    
    return 0;
}