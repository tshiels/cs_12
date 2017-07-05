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
#include "IntList.h"

using namespace std;

int main()
{
    IntList list1;
    list1.push_front(518);
    list1.push_front(992);
    list1.push_front(518);
    list1.push_front(934);
    list1.push_front(583);
    list1.push_front(582);
    list1.push_front(597);
    list1.push_front(934);
    list1.push_front(582);
    list1.push_front(992);
    // list1.display();
    // cout << endl;
    // list1.select_sort();
    // list1.display();
    // cout << endl;
    // list1.pop_front();
    // list1.display();
    // cout << endl;
    // list1.push_back(10);
    // list1.display();
    // cout << endl;
    // list1.insert_sorted(3);
    // list1.display();
    // cout << endl;
    // list1.insert_sorted(0);
    // list1.display();
    // cout << endl;
    // list1.insert_sorted(100);
    // list1.display();
    // cout << endl;
    // list1.insert_sorted(2);
    // list1.display();
    // cout << endl;
    list1.remove_duplicates();
    list1.display();
    cout << endl;
    // list1.insert_sorted(-1);
    // list1.display();
    // cout << endl;
    // list1.insert_sorted(440);
    // list1.display();
    // cout << endl;
    
    return 0;
}