/*
Program to Replace all 0’s with 1 in a given integer
Here we will discuss how to replace all the 0’s with 1 in a given integer using C++ programming language.

The concept is simple, find the digits of the integer. Compare each digit with 0 if the digit is equal to 0 then replace it with 1. Construct the new integer with the replaced digits.

Replace all 0’s with 1 in C++
While loop in C
The program for Implement a C Program to replace all 0’s with 1 in a given integer as an input, all the 0’s in the number has to be replaced with 1.

Question can come like Way 1
Write a code to change all zero's as one's (0s as 1s) in a given number? ex: 120014 needs to be printed as 121114
Question can come like Way 2
implement a c program to replace all 0's with 1 in a given integer as an input, all the 0's in the number has to be replaced with 1.
Algorithm
Take Input in num and initialize a variable num with with value 0
If num is equals to zero then update the value of num2 to 1
Iterate using a while loop until num is greater then 0
For each iteration initialize a variable rem and store unit digit of num
If rem equals to 0 then set rem to 1
Set num to num divide by 10 & num2 equals to num2*10+rem
Reverse and print num2
*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    string result = "";
    string str = to_string(num);
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '0')
        {
            result += "1";
        }
        else
        {
            result += str[i];
        }
    }
    cout<<num<<" after replace all 0;s with 1's is "<<result<<endl;
    return 0;
}