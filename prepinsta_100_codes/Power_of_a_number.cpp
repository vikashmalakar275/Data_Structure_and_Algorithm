/*
Power of a number in C++
In this post we will see various methods to calculate Power of a Number in C++.

We need the following to calculate power of number -
Base : 5
Exponent : 3
Power = 53 = 125 
Power of Number
Methods
Method 1: Using Pow(base, exp) method in math.h library
Method 2: Using Iterative Loop.
Method 3: Recursive approach
*/

#include <iostream>

using namespace std;

//Method 2: Using Iterative Loop.
int power_1(int base,int exp)
{
    int result = 1;
    while(exp-->0)
    {
        result = result * base;
    }
    return result;
}

//Method 3: Recursive approach
int power_2(int base,int exp)
{
    if(exp>0)
    {
        return power_2(base,exp-1)*base;
    }
    return 1;
}

int main()
{
    int base;
    cout<<"Enter the base :"<<endl;
    cin>>base;
    int exp;
    cout<<"Enter the exponent :"<<endl;
    cin>>exp;
    //Using Pow(base, exp) method in math.h library
    cout<<"Using Pow(base, exp) method in math.h library"<<endl;
    cout<<pow(base,exp)<<endl;
    cout<<"Using Iterative Loop"<<endl;
    cout<<power_1(base,exp)<<endl;
    cout<<"Recursive approach"<<endl;
    cout<<power_2(base,exp)<<endl;
    return 0;
}