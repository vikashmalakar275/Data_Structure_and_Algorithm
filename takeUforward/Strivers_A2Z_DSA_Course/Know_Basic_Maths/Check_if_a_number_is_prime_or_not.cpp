/*
Problem Statement: Given a number, check whether it is prime or not. A prime number is a natural number that is only divisible by 1 and by itself.

Examples 1 2 3 5 7 11 13 17 19 …

Examples
Example 1:
Input: N = 3
Output: Prime
Explanation: 3 is a prime number

Example 2:
Input: N = 26
Output: Non-Prime
Explanation: 26 is not prime
*/

#include <iostream>
using namespace std;

//Brute Force Approach
//TC = O(n)
//SC = O(1)
bool isPrime_1(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

//Optimal Solution
//TC = O(n/2)
//SC = O(1)
bool isPrime_2(int n)
{
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int number;
    cout<<"Enter the Number :"<<endl;
    cin>>number;
    if(isPrime_1(number) && isPrime_2(number))
    {
        cout<<number<<" is prime number."<<endl;
    }
    else
    {
        cout<<number<<" is not prime."<<endl;
    }
    return 0;
}