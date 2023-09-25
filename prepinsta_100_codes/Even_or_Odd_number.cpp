/*
Given an integer input num, the objective is to write a code to Check Whether a Number is Even or Odd in C++. 
To do so we check if the number is divisible by 2 or not, it’s Even if it’s divisible otherwise Odd.

Example 
Input : num = 12
Output : Even 
*/

#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the number : \n";
    int number;
    cin>>number;
    if(number%2 == 0)
    {
        cout<<number<<" is a Even number.";
    }
    else
    {
        cout<<number<<" is a Odd number.";
    }
    return 0;
}