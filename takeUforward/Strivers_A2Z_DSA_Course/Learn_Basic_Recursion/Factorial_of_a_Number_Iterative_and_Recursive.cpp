/*
Problem Statement: Given a number X,  print its factorial.

To obtain the factorial of a number, it has to be multiplied by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.

Note: X  is always a positive number. 

Examples:

Example 1:
Input: X = 5
Output: 120
Explanation: 5! = 5*4*3*2*1

Example 2:
Input: X = 3
Output: 6
Explanation: 3!=3*2*1
*/

#include <iostream>
using namespace std;

//Iterative
//TC = O(1)
//SC = O(1)
int fact_1(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n*fact_1(n-1);
}

int fact_2(int n)
{
    int fact = 1;
    for(int i=1;i<=n;i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    cout<<"Factorial of number "<<n<<" is "<<fact_1(n)<<endl;
    cout<<"Factorial of number "<<n<<" is "<<fact_2(n)<<endl;
    return 0;
}