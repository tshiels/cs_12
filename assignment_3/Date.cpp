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
#include "Date.h"

using namespace std;

Date::Date()
{
    monthName = "January";
    month = 1;
    day = 1;
    year = 2000;
    
    return;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
    month = m;
    day = d;
    year = y;
    
    if (d > daysPerMonth(m, y))
    {
        cout << "Invalid date values: Date corrected to ";
        cout << month << '/' << daysPerMonth(m, y) << '/' << y << endl;
        day = daysPerMonth(m, y);
    }
    else if (d < 1)
    {
        day = 1;
    }
    
    monthName = name(m);
    
    return;
}

Date::Date(const string &mn, unsigned d, unsigned y)
{
    if ((mn == "January") || (mn == "February") || (mn == "March") || 
        (mn == "April") || (mn == "May") || (mn == "June") || (mn == "July")
        || (mn == "August") || (mn == "September") || (mn == "October") || 
        (mn == "November") || (mn == "December"))
            {
                monthName = mn;
                day = d;
                year = y;
                month = number(mn);

            }
    else if (mn == "january")
    {
        monthName = "January";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "february")
    {
        monthName = "February";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "march")
    {
        monthName = "March";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "april")
    {
        monthName = "April";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "may")
    {
        monthName = "May";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "june")
    {
        monthName == "June";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "july")
    {
        monthName = "July";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "august")
    {
        monthName = "August";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "september")
    {
        monthName = "September";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "october")
    {
        monthName = "October";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "november")
    {
        monthName = "November";
        day = d;
        year = y;
        month = number(mn);
    }
    else if (mn == "december")
    {
        monthName = "December";
        day = d;
        year = y;
        month = number(monthName);
    }
    else
    {
        cout << "Invalid month name: The date was set to 1/1/2000." << endl;
        monthName = "January";
        month = 1;
        day = 1;
        year = 2000;
    }
    
    return;
}

void Date::printNumeric() const
{
    cout << month << '/' << day << '/' << year;
    
    return;
}

void Date::printAlpha() const
{
    cout << monthName << ' ' << day << ", " << year;
    
    return;
}

bool Date::isLeap(unsigned y) const
{
    bool isLeap = false;
    if (y % 4 == 0)
    {
        isLeap = true;
    }
    if (y % 100 == 0)
    {
        isLeap = false;
    }
    if (y % 400 == 0)
    {
        isLeap = true;
    }
    return isLeap;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    if (m > 12)
    {
        m = 12;
    }
    else if (m < 0)
    {
        m = 1;
    }
    if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || 
        (m ==10) || (m == 12))
    {
        return 31;
    }
    else if (m == 2)
    {
        if (isLeap(y))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else
    {
        return 30;
    }
}

string Date::name(unsigned m) const
{
    if (m == 1)
    {
        return "January";
    }
    else if (m == 2)
    {
        return "February";
    }
    else if (m == 3)
    {
        return "March";
    }
    else if (m == 4)
    {
        return "April";
    }
    else if (m == 5)
    {
        return "May";
    }
    else if (m == 6)
    {
        return "June";
    }
    else if (m == 7)
    {
        return "July";
    }
    else if (m == 8)
    {
        return "August";
    }
    else if (m == 9)
    {
        return "September";
    }
    else if (m == 10)
    {
        return "October";
    }
    else if (m == 11)
    {
        return "November";
    }
    else
    {
        return "December";
    }
}

unsigned Date::number(const string &mn) const
{
    if ((mn == "January") || (mn == "january"))
    {
        return 1;
    }
    else if ((mn == "February") || (mn == "february"))
    {
        return 2;
    }
    else if ((mn == "March") || (mn == "march"))
    {
       return 3;
    }
    else if ((mn == "April")|| (mn == "april"))
    {
        return 4;
    }
    else if ((mn == "May") || (mn == "may"))
    {
        return 5;
    }
    else if ((mn == "June") || (mn == "june"))
    {
        return 6;
    }
    else if ((mn == "July") || (mn == "july"))
    {
        return 7;
    }
    else if ((mn == "August") || (mn == "august"))
    {
        return 8;
    }
    else if ((mn == "September") || (mn == "september"))
    {
        return 9;
    }
    else if ((mn == "October") || (mn == "october"))
    {
        return 10;
    }
    else if ((mn == "November") || (mn == "november"))
    {
        return 11;
    }
    else if ((mn == "December") || (mn == "december"))
    {
        return 12;
    }
    else 
    {
        return 0;
    }
}




