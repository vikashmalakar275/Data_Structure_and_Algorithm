/*
Problem Statement:  Given a number check if it is a palindrome.

An integer is considered a palindrome when it reads the same backward as forward.

Examples:

Example 1:
Input: N = 123
Output: Not Palindrome Number
Explanation: 123 read backwards is 321.Since these are two different numbers 123 is not a palindrome.

Example 2:
Input: N =  121 
Output: Palindrome Number
Explanation: 121 read backwards as 121.Since these are two same numbers 121 is a palindrome.
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

bool check_palindrome(int n)
{
    int temp = n;
    int rev = 0;
    while(n != 0)
    {
        int rem = n%10;
        rev = rev*10 + rem;
        n /= 10;
    }
    return temp==rev;
}

int main()
{
    int number = 0;
    cout<<"Enter the Number :"<<endl;
    cin>>number;
    if(check_palindrome(number))
    {
        cout<<number<<" read backwards is "<<reverse_number(number)<<".Since these are two same numbers "<<number<<" is a palindrome. "<<endl;
    }
    else
    {
        cout<<number<<" read backwards is "<<reverse_number(number)<<".Since these are two different numbers "<<number<<" is not a palindrome. "<<endl;
    }
    return 0;
}