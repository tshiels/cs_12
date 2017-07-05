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
#include "Message.h"
#include <fstream>
#include <vector>

using namespace std;

// Message::Message()
// {
//     author = "";
//     subject = "";
//     body = "";
//     id = 0;
//     vector<Message *> child_list(0);
// }

// Message::Message(const string &athr, const string & sbjct, const string &body,
//     unsigned id)
// {
//     author = athr;
//     subject = sbjct;
//     this->body = body;
//     this->id = id;
// }

// Message::~Message()
// {
    
// }


// const string & Message::get_subject() const
// {
//     return subject;
// }

// unsigned Message::get_id() const
// {
//     return id;
// }

// void Message::add_child(Message *child)
// {
//     child_list.push_back(child);
// }

// void Message::print(unsigned indentation) const 
// {
//     string b = body;
//     string indent(indentation * 2, ' ');

//     unsigned t = b.find("\n");
//     while (t < (b.size() - 1))
//     {
//         ++t;
//         b.insert(t, indent);
//         t = b.find("\n", t);
//     }
//     cout << indent << "Message #" << id << ": " << subject << endl;
//     cout << indent << "from " << author << ": " << b << endl;
//     for (unsigned i = 0; i < child_list.size(); ++i)
//     {
//         cout << endl;
//         child_list.at(i)->print(indentation + 1);
//     }
// }
Message::Message() {
    author = "";
    subject = "";
    body = "";
    vector<Message*> child_list;
    id = 0;
}

Message::Message(const string &athr, const string &sbjct, 
                 const string &body, unsigned id) {
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
}
Message::~Message() {
    for (unsigned i = 0; i < child_list.size(); ++i) {
        delete child_list.at(i);
    }
    child_list.clear();
}
const string & Message::get_subject() const {
    return subject;
}
unsigned Message::get_id() const {
    return id;
}
void Message::print(unsigned indentation) const {
    string temp (indentation * 2, ' ');
    string temp2 = body;
    unsigned tmp = temp2.find("\n");
    while (tmp < temp2.length() - 1) {
        tmp++;
        temp2.insert(tmp, temp);
        tmp = temp2.find("\n", tmp);
    }
    cout << temp << "Message #" << id << ": " << subject << endl
    << temp << "from " << author << ": " << temp2;
    unsigned i = 0;
    cout << endl;
    while (i < child_list.size()) {
        cout << endl;
        child_list.at(i)->print(indentation + 1);
        ++i;
    }
}

void Message::add_child(Message* child) {
    child_list.push_back(child);
}

