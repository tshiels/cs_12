//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp 
/// @brief Assignment/Lab <#, e.g. 1,2,3..10> for CS 12 <quarter & year>
///
/// @author Thomas Shiels [tshie001@ucr.edu]
/// @date <Current date>
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 21
/// @par
///     TA: Negin Entezari
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

    void test1()
    {   
        cout << "1. Default" << endl; 
        Date x = Date(); 
        cout << "numeric:\t" ; 
        x.printNumeric(); cout << endl; 
        cout << "alpha:\t"; 
        x.printAlpha(); 
        cout << endl; 
        cout << "­­­­­­­­­­­­­-------------" << endl; 
    }
    void test2()
    {
        cout << "2. Numeric Date: 7.3.1991" << endl; 
        Date x = Date(7,3,1991);
        cout << "numeric:\t" ; 
        x.printNumeric(); 
        cout << endl; 
        cout << "alpha:\t"; 
        x.printAlpha(); 
        cout << endl; 
        cout << "­­­­­­­­­­­­­-------------" << endl; 
    }
    void test3()
    {
        cout << "3. Alpha Date: July 3, 1991" << endl; 
        Date x = Date("July",3,1991); 
        cout << "numeric:\t" ; 
        x.printNumeric(); 
        cout << endl;
        cout << "alpha:\t"; 
        x.printAlpha(); 
        cout << endl; 
        cout << "-------------­­­­­­­­­­­­­" << endl; 
    }
    void test4()
    {
        cout << "4. Invalid Numeric Date: 0.3.1991 ­> 1.3.1991" << endl; 
        Date x = Date(0,3,1991); 
        cout << "numeric:\t" ; 
        x.printNumeric(); 
        cout << endl; 
        cout << "alpha:\t"; 
        x.printAlpha(); 
        cout << endl; 
        cout << "­­­­­­­­­­­­­-------------" << endl; 
    }
    void test5()
    {
        cout << "5. Invalid Alpha Date: 1.adf.1991 ­> 1.1.2000" << endl; 
        Date x = Date("adf",1, 1991); 
        cout << "numeric:\t" ; x.printNumeric(); 
        cout << endl; 
        cout << "alpha:\t"; 
        x.printAlpha(); 
        cout << endl; 
        cout << "­­­­­­­­­­­­­-------------" << endl;
    }
int main()
{
    // test1(); 
    // test2(); 
    // test3(); 
    // test4(); 
    // test5();
    Date x(2,29,1500);
    x.printAlpha();
    
    return 0;
}