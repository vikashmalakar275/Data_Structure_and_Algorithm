/*
HCF of Two Numbers using Recursion in C++
 

Here, in this page we will discuss the program to find the HCF of Two numbers using recursion in C++. We are given with two numbers and need to find the HCF of the given two numbers.The HCF or the Highest Common Factor of two numbers is the largest common factor of two or more values.

Example :

Input : a = 96, b = 56
Output : HCF of 96 and 56 is 8.
*/

#include <iostream>

using namespace std;

int HCF(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    if(b== 0)
    {
        return a;
    }
    if(a==b)
    {
        return a;
    }
    if(a>b)
    {
        return HCF(a-b,b);
    }
    return HCF(a,b-a);
}

int main()
{
    int a,b;
    cout<<"Enter the first number :"<<endl;
    cin>>a;
    cout<<"Enter the second number :"<<endl;
    cin>>b;
    cout<<"HCF of two number is "<<a<<" & "<<b<<" is "<<HCF(a,b)<<endl;
    return 0;
}