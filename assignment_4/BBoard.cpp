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
#include <fstream>
#include <vector>
#include "BBoard.h"
#include "User.h"
#include "Message.h"
#include <cstdlib>
#include <sstream>
#include "Topic.h"
#include "Reply.h"

using namespace std;

BBoard::BBoard()
{
    title = "";
    vector<User> user_list(0);
    current_user = 0;
    vector<Message *> message_list; 
    
}

BBoard::BBoard(const string &ttl)
{
    title = ttl;
    vector<User> user_list(0);
    current_user = 0;
    vector<Message *> message_list;
    
}

BBoard::~BBoard()
{
    for (unsigned i = 0; i < message_list.size(); ++i)
    {
        delete message_list.at(i);
    }
    message_list.clear();
}

bool BBoard::load_users(const string &userfile) //DONE
{
    ifstream fin;
    ifstream inFS;
    fin.open(userfile.c_str());
    inFS.open(userfile.c_str());
    if (!fin.is_open())
    {
        cout << "Error opening input file.";
        return false;
    }
    if (!inFS.is_open())
    {
        cout << "Error opening input file.";
        return false;
    }
    int count = 0;
    string temp;
    string uname;
    string pass;
    
    while (fin >> temp)
    {
        ++count;
    }
    
    count = (count - 1) / 2;
    user_list.resize(count);
    
    for (int i = 0; i < count; ++i)
    {
        inFS >> uname;
        inFS >> pass;
        User temp_user(uname, pass);
        user_list.at(i) = temp_user;
    }
    return true;
}

void BBoard::login() 
{
    string temp_uname;
    string temp_pass;
    
    cout << "Welcome to Tommy's Amazing Bulletin Board" << endl;
    do
    {
        cout << "Enter your username (\'Q' or \'q' to quit): ";
        cin >> temp_uname;
        
        if ((temp_uname == "Q") || (temp_uname == "q"))
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        
        cout << "Enter your password: ";
        cin >> temp_pass;
        
        for (unsigned i = 0; i < user_list.size(); ++i)
        {
            if (user_list.at(i).check(temp_uname, temp_pass))
            {
                cout << "Welcome back " << temp_uname << '!' << endl;
                current_user = &user_list.at(i);
            }
        }
        if (!current_user->check(temp_uname, temp_pass))
        {
            cout << "Invalid Username or Password!" << endl;
        }
    } while (!current_user->check(temp_uname, temp_pass));
    
    return;
}


bool BBoard::load_messages(const string &datafile)
{
    ifstream fin;
    fin.open(datafile.c_str());
    vector<string> temp_children;
    int num_messages = 0;
    if (!fin.is_open())
    {
        cout << "Error opening data file.";
        return false;
    }
    fin >> num_messages;
    //message_list.resize(num_messages);
    
    string discard;
    string temp_athr;
    string temp_sbjct;
    string temp_body;
    int temp_id;
    string child_id_string;
    ostringstream oss;
    for (unsigned i = 0; i < message_list.size(); ++i)
    //while (!fin.eof())
    {
        fin >> discard;
        if (discard == "<begin_topic>")
        {
            fin >> discard; //":id:"
            fin >> temp_id; //"1"
            fin >> discard; //":subject:"
            fin.ignore();
            getline(fin, temp_sbjct); 
            fin >> discard; //":from:"
            fin >> temp_athr;
            fin >> discard; //":children:"
            if (discard == ":children:")
            {
                getline(fin, child_id_string);
                temp_children.push_back(child_id_string);
                fin >> discard;
            }
            else
            {
                discard = "";
                temp_children.push_back(discard);
            }
            fin.ignore();
            getline(fin, discard);
            oss << discard;
            getline(fin, discard);
            while (discard != "<end>")
            {
                oss << "\n" << discard;
                getline(fin, discard);
            }
            temp_body = oss.str();
            Message *temp_message = new Topic(temp_athr, temp_sbjct, temp_body,
                temp_id);
            message_list.push_back(temp_message);
            
            
        }
        if (discard == "<begin_reply>")
        {
            fin >> discard; //":id:"
            fin >> temp_id; //"1"
            fin >> discard; //":subject:"
            fin.ignore();
            getline(fin, temp_sbjct); 
            fin >> discard; //":from:"
            fin >> temp_athr;
            fin >> discard; //":children:"
            if (discard == ":children:")
            {
                getline(fin, child_id_string);
                temp_children.push_back(child_id_string);
                fin >> discard;
            }
            else
            {
                discard = "";
                temp_children.push_back(discard);
            }
            fin.ignore();
            getline(fin, discard);
            oss << discard;
            getline(fin, discard);
            while (discard != "<end>")
            {
                oss << "\n" << discard;
                getline(fin, discard);
            }
            temp_body = oss.str();
            Message *temp_message = new Reply(temp_athr, temp_sbjct, temp_body,
                temp_id);
            message_list.push_back(temp_message);
        }
    }
    fin.close();
    for (unsigned i = 0; i < message_list.size(); ++i)
    {
        stringstream sstream(temp_children.at(i));
        while (sstream >> temp_id)
        {
            message_list.at(i)->add_child(message_list[temp_id - 1]);
        }
        //sstream.str("");
    }
    return true;
}


bool BBoard::save_messages(const string &datafile) //maybe done
{
    ofstream fout;
    fout.open(datafile.c_str());
    if (!fout.is_open())
    {
        cout << "Error opening " << datafile << endl;
        return false;
    }
    
    fout << message_list.size() << endl;
    for (unsigned i = 0; i < message_list.size(); ++i)
    {
      fout << message_list.at(i)->to_formatted_string();
    }
    fout.close();
    return true;
}

void BBoard::run()
{
    string action;
    
    do
    {
        cout << "Menu" << endl;
        cout << "  - Display Messages (\'D' or \'d')" << endl;
        cout << "  - Add New Message (\'N' or \'n')" << endl;
        cout << "  - Add Reply (\'R' or \'r')" << endl;
        cout << "  - Quit (\'Q' or \'q')" << endl;
        cout << "Choose an action: ";
        cin >> action;
        
        if ((action == "Q") || (action == "q"))
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        else if ((action == "D") || (action == "d"))
        {
            display();
        }
        else if ((action == "N") || (action == "n"))
        {
            add_topic();
        }
        else if ((action == "R") || (action == "r"))
        {
            add_reply();
        }
    } while ((action != "Q") || (action != "q"));
}

void BBoard::display() const
{
    string line = "-------------------------------------------------------------------------------";
    cout << line << endl;
    for (unsigned i = 0; i < message_list.size(); ++i)
    {
        if (!message_list.at(i)->is_reply())
        {
            message_list.at(i)->print(0);
            cout << line << endl;
        }
    }
    cout << endl;
}

void BBoard::add_reply()
{
    ostringstream oss;
    string subject;
    string body;
    unsigned id;
    int temp_id;

    cout << "enter Message ID (-1 for Menu): ";
    cin >> id;
    
    while ((message_list.size() <= id) || (id < 1))
    {
        temp_id = id;
        if (temp_id == -1)
        {
            return;
        }
        cout << "Invalid Message ID!" << endl;
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> id;
        cout << endl;
    }
    subject = "Re: " + message_list.at(id - 1)->get_subject();
    cout << "Enter body: ";
    while (body.empty()) //== 0
    {
        getline(cin, body);
    }
    while (!body.empty()) //size != 0
    {
        oss << body << "\n";
        getline(cin, body);
    }
    body = oss.str();
    
    Message *temp_message = new Reply(current_user->get_username(), 
        subject, body, message_list.size() + 1);
    
    message_list.push_back(temp_message);
    message_list.at(id - 1)->add_child(temp_message);
    
    
}

void BBoard::add_topic()
{
        string subject;
        string body;
        ostringstream oss;
        cin.ignore();
        cout << "Enter subject: ";
        getline(cin, subject);
        cout << "Enter body: ";
        while (body.size() == 0)
        {
            getline(cin, body);
        }
        while (!body.empty())
        {
            oss << body << "\n";
            getline(cin, body);
        }
        
        Message *temp_message = new Topic(current_user->get_username(),
            subject, body, message_list.size() + 1);
            
        message_list.push_back(temp_message);
        //cout << "Message Recorded!" << endl;
}
