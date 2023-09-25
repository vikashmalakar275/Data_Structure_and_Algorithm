/*
Given an integer input for a year, the objective is to write a Program to Check Whether a Year is a Leap Year or Not in C++ Language.

Example
Input : 2020
Output : 2020 is a Leap Year
*/

#include <iostream>

using namespace std;

int main()
{
    int year;
    cout<<"Enter the year : "<<endl;
    cin>>year;
    if(year%400 == 0)
    {
        cout<<year<<" is Leap Year."<<endl;
    }
    else if(year%4 == 0 && year%100 != 0)
    {
        cout<<year<<" is Leap Year."<<endl;
    }
    else
    {
        cout<<year<<" is not a Leap Year."<<endl;
    }
    return 0;
}