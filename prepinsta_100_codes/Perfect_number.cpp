/*
Perfect Number in C++
In this post, we will learn different ways of coding Perfect Number in C++.

A perfect number is a number in which the sum of the proper positive divisors of the number is equal to the number itself.

For Example: 28
Divisors : 1 + 2 + 4 + 7 + 14 = 28
*/
#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    int sum = 0;
    for(int i=1;i<num;i++)
    {
        if(num%i == 0)
        {
            sum += i;
        }
    }
    if(num==sum)
    {
        cout<<num<<" is a perfect number.";
    }
    else
    {
        cout<<num<<" is not a perfect number.";
    }
    return 0;
}