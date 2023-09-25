/*
What is a Fibonacci Series and Find the Nth Term of the Fibonacci Series?
The Fibonacci numbers, commonly denoted F(N) form a sequence, called the Fibonacci series, such that each number is the sum of the two preceding ones, starting from 0 and 1.

That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given N, calculate F(N).

Example 1:
Input:n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1
Finding the Nth term of the Fibonacci Series
Finding the Nth Term of the Fibonacci Series
In mathematics, the Fibonacci numbers, commonly denoted Fₙ form a sequence, the Fibonacci sequence, in which each number is the sum of the two preceding ones. The sequence commonly starts from 0 and 1, although some authors omit the initial terms and start the sequence from 1 and 1 or from 1 and 2.

The Series has two seed values F0 = 0 and F1 = 1. Starting with the seed values we keep adding and changing the “a” and “b” values which initially are a = F0 and b = F1.

The General formula for the Fibonacci series is

Fn = Fn-1 + Fn-2
Where Fn is the Output.
*/

#include <iostream>

using namespace std;

//Using Recursion
int nth_term_of_fibonacci(int n)
{
    if(n<=1)
    {
        return n;
    }
    return nth_term_of_fibonacci(n-1) + nth_term_of_fibonacci(n-2);
}

int main()
{
    int num;
    cout<<"Enther the number :"<<endl;
    cin>>num;
    cout<<num<<"th term of fibonacci series is "<<nth_term_of_fibonacci(num)<<endl;
    return 0;
}