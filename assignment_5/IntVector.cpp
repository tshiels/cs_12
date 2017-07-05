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
#include "IntVector.h"
#include <cstdlib>

using namespace std;

IntVector::IntVector()
{
    sz = 0;
    cap = 0;
    data = NULL;
}

IntVector::IntVector(unsigned size)
{
    sz = size;
    cap = size;
    data = new int[size];
}

IntVector::IntVector(unsigned size, int value)
{
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}
IntVector::~IntVector()
{
    delete [] data;
}

unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    if (sz == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

const int & IntVector::at(unsigned index) const
{
    if (index > sz)
    {
        exit(1);
    }
    else
    {
        return data[index];
    }
}

int & IntVector::at(unsigned index)
{
    if (index > sz)
    {
        exit(1);
    }
    else
    {
        return data[index];
    }
}

const int & IntVector::front() const
{
    return data[0];
}

int & IntVector::front()
{
    return data[0];
}

const int & IntVector::back() const
{
    return data[sz - 1];
}

int & IntVector::back()
{
    return data[sz - 1];
}

void IntVector::expand()
{
    if ((cap == 0) && (sz == 0))
    {
        cap += 1;
        sz += 1;
    }
    
    int *new_data = new int[cap * 2];
    cap = cap * 2;
    
    for (unsigned i = 0; i < sz; ++i)
    {
        new_data[i] = data[i];
    }
    
    delete [] data;
    data = new_data;
}

void IntVector::expand(unsigned amount)
{
    if ((cap == 0) && (sz == 0))
    {
        cap += 1;
        sz += 1;
    }
    
    int *new_data = new int[cap + amount];
    cap += amount;
    
    for (unsigned i = 0; i < sz; ++i)
    {
        new_data[i] = data[i];
    }
    
    delete [] data;
    data = new_data;
}

void IntVector::insert(unsigned index, int value)
{
    sz += 1;
    
    if (sz > cap)
    {
        expand();
    }
    
    if (index > sz)
    {
        exit(1);
    }
    
    for (unsigned i = sz; i > index; --i)
    {
        data[i] = data[i - 1];
    }
    
    data[index] = value;
}

void IntVector::erase(unsigned index)
{
    if (index > sz)
    {
        exit(1);
    }
    
    for (unsigned i = index; i < sz; ++i)
    {
        data[i] = data[i + 1];
    }
    
    sz = sz - 1;
}

void IntVector::push_back(int value)
{
    if ((sz == 0) && (cap == 0))
    {
        sz = 1;
        cap = 1;
        data = new int[1];
    }
    else
    {
        ++sz;
    }
    
    if (sz > cap)
    {
        expand();
    }
    back() = value;
}

void IntVector::pop_back()
{
    if (sz == 0)
    {
        exit(1);
    }
    else
    {
        sz = sz - 1;
    }
}

void IntVector::clear()
{
    sz = 0;
}

void IntVector::resize(unsigned size)
{
    if (size <= sz)
    {
        sz = size;
    }
    else if (size > sz)
    {
        if (size > cap)
        {
            if ((size - cap) >= (cap * 2))
            {
                expand(size - cap);
            }
            else
            {
                expand();
            }
        }
        for (unsigned i = sz; i < size; ++i)
        {
            data[i] = 0;
        }
        sz = size;
    }
}

void IntVector::resize(unsigned size, int value)
{
    if (size > sz)
    {
        if (size > cap)
        {
            if (cap * 2 <= (size - cap))
            {
                expand(size - cap);
            }
            else
            {
                expand();
            }
        }
        for (int i = sz; i < size; ++i)
        {
            data[i] = 0;
        }
    }
    else if (size <= sz)
    {
        sz = size;
    }
    // else
    // {
    //     for (unsigned i = 0; i < size; ++i)
    //     {
    //         push_back(value);
    //     }
    // }
}

void IntVector::reserve(unsigned n)
{
    if (n > cap)
    {
        expand(n - cap);
    }
}

void IntVector::assign(unsigned n, int value)
{
    if (n > cap)
    {
        expand();
    }
    resize(n);
    sz = n;
    cap = n;
    for (unsigned i = 0; i < sz; ++i)
    {
        data[i] = value;
    }
}

