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
#include <cmath>

using namespace std;

const int M = 6;
const int N = 8;

void updategrid(double a[][N], const double t)
{
    double maxdiff = 0;
    double tol2 = 999;
    double prevAvg = 0;
    double temp = 0;
    
    do
    {
        maxdiff = 0;
        for (int i = 1; i < M - 1; ++i)
        {
            for (int j = 1; j < N - 1; ++j)
            {
                prevAvg = a[i][j];
                
                a[i][j] = (a[i - 1][j] + a[i + 1][j] + a[i][j - 1] 
                    + a[i][j + 1]) / 4; //updates grid
                
                temp = abs(prevAvg - a[i][j]); //finds difference
                
                if (temp > maxdiff)
                {
                    maxdiff = temp;
                }
            }
        }
        if (maxdiff < tol2)
        {
            tol2 = maxdiff;
        }
    }
    while (tol2 >= t);
}

int main()
{
    ifstream inFS;
    ofstream outFS;
    string inputFile;
    string outputFile;
    double input1 = 0; 
    double input2 = 0;
    double input3 = 0;
    double input4 = 0;
    double tolerance = 0;
    double arr[M][N] = {0};
    
    cout << "Enter name of input file: ";
    cin >> inputFile;
    inFS.open(inputFile.c_str());
    if (!inFS.is_open())
    {
        cout << "Error opening " << inputFile << endl;
        return 0;
    }
    
    cout << "Enter name of output file: ";
    cin >> outputFile;
    outFS.open(outputFile.c_str());
    if (!outFS.is_open())
    {
        cout << "Error opening " << outputFile << endl;
        return 0;
    }
    
    
    
    inFS >> input1;
    for (int i = 0; i < N; ++i) //initializes top row
    {
        arr[0][i] = input1;
    }
    
    inFS >> input2;            // initializes right column
    for (int i = 1; i < M - 1; ++i)
    {
        arr[i][N - 1] = input2;
    }
    
    inFS >> input3;          //initializes bottom row
    for (int i = 0; i < N; ++i)
    {
        arr[M - 1][i] = input3;
    }
    
    inFS >> input4;          //initializes left column
    for (int i = 1; i < M - 1; ++i)
    {
        arr[i][0] = input4;
    }
    
    inFS >> tolerance;   //reads tolerance
    
    
    //updates grid
    updategrid(arr, tolerance);
    
    
    for (int i = 1; i < M - 1; ++i)
    {
        for (int j = 1; j < N - 1; ++j)
        {
            outFS << arr[i][j] << ' ';
        }
        outFS << endl;
    }
    
    for (int i = 0; i < M; ++i) //prints array
    {
        for (int j = 0; j < N; ++j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    
    
    return 0;
}