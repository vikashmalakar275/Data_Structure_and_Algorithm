/*
Program to find Prime Numbers in a given range in C++
Here we will discuss how to find prime numbers in the range specified by the user using C++ programming language.

Prime numbers are the numbers which have 2 divisors only 
i.e. can be divided by 1 & itself

Example: 2, 3, 5, 7, 11, 13 .... etc
In this program, the user will specify a range and we will check for every number in the range for being prime
*/
#include <iostream>

using namespace std;
bool isPrime(int);


int main()
{
    int num1,num2;
    cout<<"Enter the first number :"<<endl;
    cin>>num1;
    cout<<"Enter the second number :"<<endl;
    cin>>num2;
    for(int i=num1;i<=num2;i++)
    {
        string input = isPrime(i) ? " is a Prime Number." : " is not a Prime Number.";
        cout<<i<<input<<endl;
    }
    return 0;
}

bool isPrime(int num)
{
    bool flag = true;
    if(num <2)
    {
        return false;
    }
    for(int i=2;i<num;i++)
    {
        if(num%i == 0)
        {
            flag = false;
        }
    }
    return flag;
}