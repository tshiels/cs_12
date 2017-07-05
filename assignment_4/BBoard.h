//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp 
/// @brief Assignment/Lab <#, e.g. 1,2,3..10> for CS 12 <quarter & year>
///
/// @author Thomas Shiels [tshie001@ucr.edu]
/// @date <Current date>
///
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

#ifndef BBOARD_H
#define BBOARD_H

#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "Reply.h"
#include "Message.h"
using namespace std;

class BBoard
{
    private:
        string title;
        vector<User> user_list;
        const User *current_user;
        vector<Message *> message_list;
    
    public: 
        BBoard();
        BBoard(const string &ttl);
        ~BBoard();
        bool load_users(const string &userfile);
        bool load_messages(const string &datafile);
        bool save_messages(const string& datafile);
        void login();
        void run();
    
    private:
        void add_message();
        void add_user(const string &name, const string &pass);
        void display() const;
        void add_topic();
        void add_reply();
};
#endif