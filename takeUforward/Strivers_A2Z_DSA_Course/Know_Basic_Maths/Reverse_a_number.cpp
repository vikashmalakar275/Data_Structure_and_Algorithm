/*
Problem Statement: Given a number N reverse the number and print it.

Examples:

Example 1:
Input: N = 123
Output: 321
Explanation: The reverse of 123 is 321

Example 2:
Input: N = 234
Output: 432
Explanation: The reverse of 234 is 432
*/

#include <iostream>
using namespace std;

int reverse_number(int n)
{
    int rev = 0;
    while(n != 0)
    {
        int rem = n%10;
        rev = rev*10 + rem;
        n /= 10;
    }
    return rev;
}

int main()
{
    int number = 0;
    cout<<"Enter the Number :"<<endl;
    cin>>number;
    cout<<"The reverse of "<<number<<" is "<<reverse_number(number)<<endl;
    return 0;
}