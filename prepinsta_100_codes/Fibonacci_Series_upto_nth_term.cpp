/*
Program to print Fibonacci series up to N  numbers
Here we will discuss how to find the Fibonacci Series upto n numbers using C++ Programming language. We will look at different ways of coding Fibonacci Series in C++

fibannoci series upto n terms in c++
What is Fibonacci Series
Definition
It is a series in which any number in the series is the direct sum of previous two numbers in the series.

Following is Fibonacci Series -
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
More Mathematical terms
F(n) = F(n-1) + F(n-2)
Always, F(0) = 0, F(1) = 1
Method Discussed
Method 1: Simple iterative
Method 2: Recursive with a static variable
Method 3: Recursive without static variable
Method 4: Using Dynamic Programming
Objective: Write a program to print fibonacci series in C++
*/
#include <iostream>
using namespace std;

//Method 1: Simple iterative
void fibonacci_1(int n)
{
    cout<<"Using Simle iterative."<<endl;
    n--;
    int First = 0;
    cout<<First<<" , ";
    n--;
    int second = 1;
    cout<<second<<" , ";
    int sum = 0;
    while(n-->0)
    {
        sum = First + second;
        cout<<sum<<" , ";
        First = second;
        second = sum;
    }
    cout<<endl;
    
}

//Method 2: Recursive with a static variable
void fibonacii_2(int n)
{
    static int first=0,second=1,sum;
    if(n>0)
    {
        sum = first + second;
        cout<<sum<<" , ";
        first = second;
        second = sum;
        fibonacii_2(n-1);
    }
}

//Method 3: Recursive without static variable
int fibonacci_3(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fibonacci_3(n-1) + fibonacci_3(n-2);

}

//Method 4: Using Dynamic Programming
void fibonacci_4(int n)
{
    cout<<"Using Dynamic Programming"<<endl;
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    cout<<f[0]<<" , "<<f[1]<<" , ";
    for(int i=2;i<n;i++)
    {
        f[i] = f[i-1]+f[i-2];
        cout<<f[i]<<" , ";
    }
    cout<<endl;
}

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    fibonacci_1(num);
    cout<<"Using Recursive with a static variable"<<endl;
    cout<<"0 , 1 , ";
    fibonacii_2(num-2);
    cout<<endl;
    cout<<"Using Recursive without static variable"<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<fibonacci_3(i)<<" , ";
    }
    cout<<endl;
    fibonacci_4(num);
    return 0;
}