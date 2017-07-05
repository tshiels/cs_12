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
#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;
 
  class User
  {
    private:
      string username;
      string password;
 
    public:
      //creates a user with empty name and password.
      User();

      // creates a user with given username and password.
      User(const string& uname, const string& pass);

      //returns the username
      string get_username() const;
 
      // returns true if the stored username/password matches with the
      // parameters. Otherwise returns false.
      // Note that, even though a User with empty name and password is 
      // actually a valid User object (it is the default User), this 
      // function must still return false if given a empty uname string.
      bool check(const string &uname, const string &pass) const;
 
      // sets a new password.
      // This function should only set the new password if the current
      // (old) password is passed in. Also, a default User cannot have its 
      // password changed. 
      // Returns true if password changed, false if not.

      bool set_password(const string &oldpass, const string &newpass);
  };
#endif