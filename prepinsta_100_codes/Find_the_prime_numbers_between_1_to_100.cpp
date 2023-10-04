/*
C++ Program to Find Prime number between 1 to 100
Prime number between 1 to 100 in C++
Prime number between 1 to 100 in C++
We will discuss the program for Prime number between 1 to 100 in C++. A prime number is an positive integer that has no integer factors except one and itself or can only be exactly divided by the integers 1 and itself without leaving a remainder.
For example 73 is prime, because it can only be divided by 1 and 73.So prime number has two factor one is 1 another is number itself is called prime number.

The number 1 is neither prime nor composite.
*/

#include <iostream>

using namespace std;

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

int main()
{
    int start,end;
    cout<<"Enter the start number :"<<endl;
    cin>>start;
    cout<<"Enter the end number :"<<endl;
    cin>>end;
    for(int i=start;i<=end;i++)
    {
        if(isPrime(i))
        {
            cout<<i<<" , ";
        }
    }
    cout<<" is are prime number between "<<start<<" and "<<end<<endl;
}