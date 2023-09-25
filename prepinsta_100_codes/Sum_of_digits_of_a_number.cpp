/*
Program to Find the Sum of Digits of a Number in C++
Here we will discuss how to find the sum of digits of a number in C++ programming language.

We will use loops along with two arithmetic operators:

1. Modulo Operator : '%'
2. Division Operator: '/'

Eg: number = 12345
Sum of digit of number = 1 + 2 + 3 + 4 + 5
Sum = 15
*/
#include <iostream>

using namespace std;

int main()
{
    int number;
    cout<<"Enter the number :"<<endl;
    cin>>number;
    int sum = 0;
    int num = number;
    while(number>0)
    {
        int temp = number%10;
        sum += temp;
        number = number/10;
    }
    cout<<"Sum of digit of number="<<num<<" is "<<sum<<endl;
    return 0;
}