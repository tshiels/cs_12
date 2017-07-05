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
#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList()
{
    head = 0;
    tail = 0;
}

IntList::~IntList()
{
    IntNode *curr = head;
    for (curr = head; curr != 0; curr = curr->next)
    {
        head = head->next;
        delete curr;
    }
}

void IntList::display() const
{
    IntNode *curr = head;
    for (curr = head; curr != 0; curr = curr->next)
    {
        cout << curr->data;
        if (curr->next != 0)
        {
            cout << " ";
        }
    }
}

void IntList::push_front(int value)
{
    if (head == 0)
    {
        head = new IntNode(value);
        tail = head;
    }
    else
    {
        IntNode *temp = head;
        head = new IntNode(value);
        head->next = temp;
    }
}

void IntList::pop_front()
{
    if ((head != 0) && (head->next != 0))
    {
        IntNode *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        delete head;
        head = 0;
        tail = 0;
    }
}

void IntList::select_sort()
{
    for (IntNode *i = head; i != 0; i = i->next)
    {
        IntNode *min = i;
        for (IntNode *j = i->next; j != 0; j = j->next)
        {
            if (j->data < min->data)
            {
                min = j;
            }
        }
        
        int temp = i->data;
        i->data = min->data;
        min->data = temp;
       
    }
}

void IntList::insert_sorted(int value)
{
    if (head == 0)
    {
        push_front(value);
        return;
    }
    for (IntNode *i = head; i != 0; i = i->next)
    {
        if (value < i->data)
        {
            push_front(value);
            return;
        }
        else if (i->next != 0)
        {
            IntNode *j = i->next;
            if ((value >= i->data) && (value <= j->data))
            {
                IntNode *new_node = new IntNode(value);
                i->next = new_node;
                new_node->next = j;
                return;
            }
        }
        else if (i->next == 0)
        {
            push_back(value);
            return;
        }
    }
}

void IntList::push_back(int value)
{
    if (head == 0)
    {
        push_front(value);
    }
    else
    {
        tail->next = new IntNode(value);
        tail = tail->next;
        tail->next = 0;
    }
}

void IntList::remove_duplicates()
{
    for (IntNode *i = head; i != 0; i = i->next)
    {
        IntNode *prev = i;
        for (IntNode *j = i->next; j != 0; j = j->next)
        {
            if (j->data == i->data)
            {
                IntNode *temp = j;
                prev->next = j->next;
                delete temp;
            }
            else
            {
                prev = prev->next;
            }
        }
    }
    for (IntNode *i = head; i != 0; i = i->next)
    {
        if (i->next == 0)
        {
            tail = i;
        }
    }
}

