/*
Program Reverse a Number in C++
Here we will discuss how to find the reverse of a given number using C++ programming language.
We will use loop and arithmetic operators

1. Modulo Operator : '%'
2. Division Operator : '/'

Example:
Number: 5678
Reverse: 8765
*/

#include <iostream>

using namespace std;

int main()
{
    int number;
    cout<<"Enter the number :"<<endl;
    cin>>number;
    int num = number;
    int reverse = 0;
    while(number>0)
    {
        int rem = number%10;
        reverse = reverse*10 + rem;
        number = number/10;
    }
    cout<<"Reverse of the number="<<num<<" is "<<reverse<<endl;
    return 0;
}