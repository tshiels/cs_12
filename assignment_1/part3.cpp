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

int main()
{
    srand(333);
    double arr1[500] = {0};
    double arr2[500] = {0};
    double a1 = 0;
    double a2 = 0;
    double b1 = 0;
    double b2 = 0;
    double th_mean = 0;
    double pr_mean = 0;
    double pr_mean2 = 0;
    double th_var = 0;
    double pr_var = 0;
    double pr_var2 = 0;
    double temp = 0;
    double temp2 = 0;
    double stdev = 0;
    double stdev2 = 0;
    double th_mean2 = 0;
    
    a1 = -3;
    a2 = -7;
    b1 = 3;
    b2 = -1;
    
    for (int i = 0; i < 500; ++i)             //random double for first array
    {
        arr1[i] = randFloat(a1, b1);
    }
    
    for (int i = 0; i < 500; ++i)          //random double for second
    {
        arr2[i] = randFloat(a2, b2);
    }
    
    th_mean = (a1 + b1) / 2;   
    th_mean2 = (a2 + b2) / 2; //calculates theoretical mean
    
    th_var = (pow(b1 - a1, 2)) / 12; //calculates theoretical variance
    
    for (int i = 0; i < 500; ++i)
    {
        temp = temp + arr1[i];        //adds values in first array together
    }
    pr_mean = temp / 500;             // calculates practical mean first array
    
    for (int i = 0; i < 500; ++i)
    {
        stdev = stdev + pow((arr1[i] - pr_mean), 2);   //st. deviation 
    }
    pr_var = (stdev / 500);   // practical variance
    
    for (int i = 0; i < 500; ++i)
    {
        temp2 = temp2 + arr2[i];   //adds values of second array
    }
    pr_mean2 = temp2 / 500;  // calculates second practical mean
    
    for (int i = 0; i < 500; ++i)
    {
        stdev2 = stdev2 + pow((arr2[i] - pr_mean2), 2); //2nd st. deviation
    }
    pr_var2 = (stdev2 / 500); //second practical variance
    
    cout << th_mean << ' ' << pr_mean << ' ' << th_var << ' ' << pr_var;
    cout << endl;
    cout << th_mean2 << ' ' << pr_mean2 << ' ' << th_var << ' ' << pr_var2;
    cout << endl;
    
    return 0;
}