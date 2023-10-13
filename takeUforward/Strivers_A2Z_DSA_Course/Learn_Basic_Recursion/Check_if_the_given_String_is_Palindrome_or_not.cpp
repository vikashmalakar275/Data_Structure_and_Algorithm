/*
Problem Statement: “Given a string, check if the string is palindrome or not.”  A string is said to be palindrome if the reverse of the string is the same as the string.

Examples:

Example 1:
Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.

Example 2:
Input: Str = “TAKE U FORWARD”
Output: Not Palindrome
Explanation: String when reversed is not the same as string.
*/

#include <iostream>
using namespace std;

bool check_palindrome(string str)
{
    string temp = str;
    reverse(str.begin(),str.end());
    return temp==str;
}

int main()
{
    string str;
    cout<<"Enter thr string :"<<endl;
    getline(cin,str);
    if(check_palindrome(str))
    {
        cout<<"Palindrome"<<endl;
    }
    else
    {
        cout<<"Not Palindrome."<<endl;
    }
}