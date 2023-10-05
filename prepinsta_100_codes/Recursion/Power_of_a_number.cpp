/*
Power of a Number using Recursion in C++
 

Here, in this page we will discuss the program to find power of a number using recursion in C++ programming language. We are given with two integers values base and power respectively. We need to print the value representing the base raise to its power. We will design the program using recursion and also discuss the approach using iteration as well.

Example :

Input : 5 3
Output : 125
Explanation : 53 = 125
*/

#include <iostream>

using namespace std;

int power(int b,int n)
{
    if(n==0)
    {
        return 1;
    }
    return b * power(b,n-1);
}

int main()
{
    int base,num;
    cout<<"Enter the base : "<<endl;
    cin>>base;
    cout<<"Enter the numner :"<<endl;
    cin>>num;

    int pow = power(base,num);
    cout<<base<<" power "<<num<<" is "<<pow<<endl;
    
    return 0;
}