/*
LCM of Two Numbers using Recursion in C++
 

Here, in this page we will discuss the program to find the LCM of Two numbers using Recursion in C++ Programming Language. We are given with two integers and need to find the LCM of the given numbers.  The LCM of two integers num1 and num2 is the smallest positive integer that is perfectly divisible by both num1 and num2(without a remainder). 

Example :

Input : num1 = 3 num2 = 21
Output : LCM of 3 and 21 is 21.
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
    int LCM = (a*b)/ HCF(a,b);
    cout<<"LCM of two number "<<a<<" & "<<b<<" is "<<LCM<<endl;
    return 0;
}