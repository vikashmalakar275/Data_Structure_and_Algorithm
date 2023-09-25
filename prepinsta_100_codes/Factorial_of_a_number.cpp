/*
Factorial of a Number in C++
Here we will discuss how to find the factorial of a number in C++ programming language.

Factorial of any number is the product of it and all the positive numbers below it for example factorial of 5 is 120

Factorial of n (n!) = 1 * 2 * 3 * 4....n
5! = 1 x 2 x 3 x 4 x 5 = 120 7! = 1 x 2 x 3 x 4 x 5 x 6 x 7 = 5040

Factorial
Ways discussed:-
Iterative approach
Recursive approach

*/
#include <iostream>

using namespace std;

//Iterative approach
int factorial_1(int n)
{
    int mul = 1;
    for(int i=1;i<=n;i++)
    {
        mul *= i;
    }
    return mul;

}

//Recursive approach
int factorial_2(int n)
{
    
    if(n==0)
    {
        return 1;
    }
    return n * factorial_2(n-1);
}

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    cout<<"Using Iterative approach"<<endl;
    cout<<"Factorial of Number="<<num<<" is "<<factorial_1(num)<<endl;
    cout<<endl;
    cout<<"Using Recursive approach"<<endl;
    cout<<"Factorial of Number="<<num<<" is "<<factorial_2(num)<<endl;
}
