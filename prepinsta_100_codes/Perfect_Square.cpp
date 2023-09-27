/*
Check for Perfect Square in C++
Today in this article we will discuss the program to check for perfect square in C++ programming language. 
We are given with an integer number and need to print “True” if it is, otherwise “False”.
*/

#include <iostream>

using namespace std;

bool isPerfect(int n)
{
    int temp = n;
    int sum = 0;
    while(n>0)
    {
        int rem = n%10;
        sum += rem;
        n /= 10;
    }
    return (sum*sum) == temp;
}

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    if(isPerfect(num))
    {
        cout<<num<<" is a perfect square number."<<endl;
    }
    else
    {
        cout<<num<<" is not a perfect square number."<<endl;
    }
    return 0;
}