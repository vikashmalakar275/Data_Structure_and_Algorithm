/*
Strong Number in C++
Strong Numbers is a number in which the sum of the factorial of individual digits of the numbers is equal to the number itself.

For Example: 145 
145 = 1! x 4! x 5! =  145
Strong Number
Methods:-
Iterative
Recursive
*/
#include <iostream>

using namespace std;

//Calculate Factorial of a Number
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}

bool strongNumber(int num)
{
    int temp = num;
    int sum = 0;
    while(num>0)
    {
        int rem = num%10;
        sum = sum + fact(rem);
        num = num/10;
    }
    return sum == temp;
}

int main()
{
    int num;
    cout<<"Enter the Number :"<<endl;
    cin>>num;
    if(strongNumber(num))
    {
        cout<<num<<" is Strong Number."<<endl;
    }
    else
    {
        cout<<num<<" is not Strong Number."<<endl;
    }
    return 0;
}