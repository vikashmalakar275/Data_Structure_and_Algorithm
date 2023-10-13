/*
Problem statement: Given a number ‘N’, find out the sum of the first N natural numbers.

Examples:

Example 1:
Input: N=5
Output: 15
Explanation: 1+2+3+4+5=15

Example 2:
Input: N=6
Output: 21
Explanation: 1+2+3+4+5+6=15
*/

#include <iostream>
using namespace std;

//TC = O(1)
//SC = O(1)
int sumNatural(int n)
{
    if(n<1)
    {
        return 0;
    }
    return n + sumNatural(n-1);
}

int main()
{
    int n;
    cout<<"Enter the Number :"<<endl;
    cin>>n;
    cout<<"Sum of "<<n<<" natural number is "<<sumNatural(n)<<endl;
    return 0;
}