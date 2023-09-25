/*
Given two integers as input, the objective is to check both numbers 
for the greatest and write a code to find the greatest of the two numbers in C++.
*/

#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cout<<"Enter First Number :"<<endl;
    cin>>num1;
    cout<<"Enter Second Number :"<<endl;
    cin>>num2;
    if(num1 == num2)
    {
        cout<<"Both the numbers are equal."<<endl;
    }
    else if (num1>num2)
    {
        cout<<num1<<" is greater than "<<num2<<endl;
    }
    else 
    {
        cout<<num2<<" is greater than "<<num1<<endl;
    }
    return 0;
}