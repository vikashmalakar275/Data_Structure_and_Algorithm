/*
Problem Statement: Given an integer N, write a program to count the number of digits in N.

Examples
Example 1:
Input: N = 12345
Output: 5
Explanation: N has 5 digits

Example 2:
Input: N = 8394
Output: 4
Explanation: N has 4 digits
*/

#include <iostream>
using namespace std;

int count_digit_1(int n)
{
    int count=0;
    while(n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int count_digit_2(int n)
{
    string str = to_string(n);
    return str.size();
}

int count_digit_3(int n)
{
    int count=floor(log10(n)+1);
    return count;
}

int main()
{
    int number;
    cout<<"Enter the Number :"<<endl;
    cin>>number;
    cout<<number<<" has "<<count_digit_1(number)<<" digits."<<endl;
    cout<<number<<" has "<<count_digit_2(number)<<" digits."<<endl;
    cout<<number<<" has "<<count_digit_3(number)<<" digits."<<endl;
}