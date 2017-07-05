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
#include "IntVector.h"

using namespace std;

int main()
{
    IntVector v1(50);
    
    // cout << "v1 size: " << v1.size() << endl;
    // cout << "is empty: " << v1.empty() << endl;
    // cout << "v1 cap: " << v1.capacity() << endl;
    // cout << "v1 at index 0: " << v1.at(0) << endl;
    
    v1.push_back(10);
    cout << "push back.." << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "at index 0:" << v1.at(0) << endl;
    
    v1.resize(40);
    cout << "size now: " << v1.size() << endl;
    
    return 0;
}