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
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double randFloat(double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

int main()
{
    srand(333);
    double small[1000];
    double large[100000];
    double limitA = 0;
    double limitB = 0;
    double th_mean = 0;
    double pr_mean = 0;
    double th_var = 0;
    double pr_var = 0;
    double sum = 0;
    double stdev = 0;
    double sum2 = 0;
    double pr_mean2 = 0;
    double stdev2 = 0;
    double pr_var2 = 0;
    
    cout << "Please enter first limit: ";
    cin >> limitA;
    cout << endl;
    cout << "Please enter second limit: ";
    cin >> limitB;
    cout << endl;
    
    th_mean = (limitA + limitB) / 2;         //calculates theoretical mean
    th_var = (pow(limitB - limitA, 2)) / 12;  //calculates theoretical variance
    
    for (int i = 0; i < 1000; ++i)
    {
        small[i] = randFloat(limitA, limitB);  //populates first array
        sum += small[i];        //sums values in first array
    }
    pr_mean = sum / 1000;           // calculates practical mean first array
    
    for (int i = 0; i < 1000; ++i)
    {
        stdev = stdev + pow((small[i] - pr_mean), 2); //1st variance 
    }
    pr_var = (stdev / 1000);   // practical variance
    
    for (int i = 0; i < 100000; ++i)
    {
        large[i] = randFloat(limitA, limitB);//populates second array
        sum2 += large[i];   //adds values of second array
    }
    pr_mean2 = sum2 / 100000;  // calculates second practical mean
    
    for (int i = 0; i < 100000; ++i)
    {
        stdev2 = stdev2 + pow((large[i] - pr_mean2), 2);//2nd variance
    }
    pr_var2 = (stdev2 / (100000)); //second practical variance
    
    cout << th_mean << ' ' << pr_mean << ' ' << th_var << ' ' << pr_var;
    cout << endl;
    cout << th_mean << ' ' << pr_mean2 << ' ' << th_var << ' ' << pr_var2;
    cout << endl;
    
    return 0;
    
}