/*
Problem Statement: Find the gcd of two numbers.

Examples
Example 1:
Input: num1 = 4, num2 = 8
Output: 4
Explanation: Since 4 is the greatest number which divides both num1 and num2.

Example 2:
Input: num1 = 3, num2 = 6
Output: 3
Explanation: Since 3 is the greatest number which divides both num1 and num2.
*/

#include <iostream>
using namespace std;

//Brute Force Approach
//TC = O(N)
//SC = O(1)
int gcd_or_hcf_1(int a,int b)
{
    int gcd = 0;
    for(int i=0;i<=min(a,b);i++)
    {
        if(a%i==0 && b%i==0)
        {
            gcd = i;
        }
    }
    return gcd;
}

//Optimal Solution
//TC = O(logɸmin(a,b)), where ɸ is 1.61.
//SC = O(1)
int gcd_or_hcf_2(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd_or_hcf_2(b,a%b);
}

int main()
{
    int a,b;
    cout<<"Enter the First Number :"<<endl;
    cin>>a;
    cout<<"Enter the Second Number"<<endl;
    cin>>b;
    cout<<"Since "<<gcd_or_hcf_1(a,b)<<" is the greatest number which divides both "<<a<<" and "<<b<<". "<<endl;
    cout<<"Since "<<gcd_or_hcf_2(a,b)<<" is the greatest number which divides both "<<a<<" and "<<b<<". "<<endl;
    return 0;
}