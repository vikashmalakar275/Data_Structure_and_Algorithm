/*
Program for Decimal to binary Conversion in C++
In this post, we will learn how to write a code for Decimal to Binary Conversion in C++. We will look at different ways for coding Decimal to Binary in C++.

Decimal to Binary in C++
While loop in C
Various Methods discussed
Method 1: Binary Bits stored in Array
Method 2: Using mathematical operations to generate binary equivalent.
*/

#include <iostream>

using namespace std;

//Method 1: Binary Bits stored in Array
int decimalToBinary(int n)
{
    string binary = "";
    while(n>0)
    {
        if(n%2 == 0)
        {
            binary += "0";
        }
        else
        {
            binary += "1";
        }
        n = n/2;
    }
    return stoi(binary);
}

int main()
{
    int num;
    cout<<"Enter the Decimal Number :"<<endl;
    cin>>num;
    cout<<"Decimal : "<<num<<"\nBinary : "<<decimalToBinary(num)<<endl;
    return 0;
}