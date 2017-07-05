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
#ifndef REPLY_H
#define REPLY_H

#include <iostream>
#include "Message.h"

class Reply : public Message
{
    // no new member variables
    
    public:
        //default constructor
        Reply();
    
        /* Parameterized constructor - similar to Message's constructor except:
        * The subject should be initialized to "Re: <sbjct>" not <sbjct>.
        */
        Reply(const string &athr, 
            const string &sbjct, 
            const string &body, 
            unsigned id);
     
        virtual bool is_reply() const; // Returns true
     
        /* to_formatted_string writes the contents of the Reply to a string in the 
        * following format:
            
        <begin_reply>
        :id: 4
        :subject: single line
        :from: author
        :children: 5 6 [this line should not be printed if there are no children.]
        :body: multiple lines
        2nd line
        <end>
        
        * the line starting with :children: has the list of id's of all children 
        * (See file specs. for details)
        * This function should not assume the last character in body is a newline.
        * In other words, this function must manually add a newline after the last 
        * line of the body (line 3 in this example).
        * Also, the last character in the string must be a newline.
        */
        virtual string to_formatted_string() const; // New !!
   
};
#endif