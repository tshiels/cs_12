//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp 
/// @brief Assignment/Lab <#, e.g. 1,2,3..10> for CS 12 <quarter & year>
///
/// @author <Thomas Shiels> [tshie001@ucr.edu]
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
#include <string>

using namespace std;

class Date
{
    private: 
        unsigned day;
        unsigned month;
        string monthName;
        unsigned year;
        
        bool isLeap(unsigned) const;
        unsigned daysPerMonth(unsigned, unsigned) const;
        string name(unsigned) const;
        unsigned number(const string &) const;
    public:
        Date();
        Date(unsigned, unsigned, unsigned);
        Date(const string &, unsigned, unsigned);
        void printNumeric() const;
        void printAlpha() const;
};

