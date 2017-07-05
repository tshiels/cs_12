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
#include "Topic.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Message.h"

using namespace std;
Topic::Topic()
{
    author = "";
    subject = "";
    body = "";
    id = 0;
    vector<Message *> child_list(0);
}

Topic::Topic(const string &athr, const string &sbjct, const string &body, 
    unsigned id) //CHECK
{
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
}

bool Topic::is_reply() const
{
    return false;
}

string Topic::to_formatted_string() const
{
    ostringstream oss;
    
    oss << "<begin_topic>" << endl;
    oss << ":id: " << id << endl;
    oss << ":subject: " << subject << endl;
    oss << ":from: " << author << endl;
    if (!child_list.empty())
    {
        oss << ":children: ";
        for (unsigned i = 0; i < child_list.size(); ++i)
        {
            oss << child_list.at(i)->get_id() << ' ';
        }
        oss << endl;
    }
    oss << ":body: " << body << endl;
    oss << "<end>" << endl;
    
    string out = oss.str();
    return out;
}
