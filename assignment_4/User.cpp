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
#include "User.h"

using namespace std;

User::User()
{
    username = "";
    password = "";
}

User::User(const string &uname, const string & pass)
{
    username = uname;
    password = pass;
}

string User::get_username() const
{
    return username;
}

bool User::check(const string &uname, const string &pass) const
{
    if (uname == "")
    {
        return false;
    }
    
    if ((uname == username) && (pass == password))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool User::set_password(const string &oldpass, const string &newpass)
{
    if (oldpass == "")
    {
        return false;
    }
    
    if (oldpass == password)
    {
        password = newpass;
        return true;
    }
    else
    {
        return false;
    }
}