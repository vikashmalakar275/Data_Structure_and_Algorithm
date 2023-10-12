/*
Problem Statement: Given a number, check if it is Armstrong Number or Not.

Examples:

Example 1:
Input:153 
Output: Yes, it is an Armstrong Number
Explanation: 1^3 + 5^3 + 3^3 = 153

Input:170 
Output: No, it is not an Armstrong Number
Explanation: 1^3 + 7^3 + 0^3 != 170
*/
#include <iostream>
using namespace std;

bool check_armstrong(int num)
{
    int n = to_string(num).size();
    int temp = num;
    int result = 0;
    while(num != 0)
    {
        int rem = num%10;
        result += pow(rem,n);
        num /= 10;
    }
    return temp==result;
}

int main()
{
    int number;
    cout<<"Enter the Number :"<<endl;
    cin>>number;
    if(check_armstrong(number))
    {
        cout<<"Yes, it is an Armstrong Number"<<endl;
    }
    else
    {
        cout<<"No, it is not an Armstrong Number"<<endl;
    }
    return 0;
}