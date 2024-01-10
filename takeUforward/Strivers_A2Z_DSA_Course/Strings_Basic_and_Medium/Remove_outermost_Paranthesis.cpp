/*
Given a string S of valid parentheses “(“ and “)”, the task is to print the string obtained by removing the outermost parentheses of every primitive substring from S.

A valid parentheses substring S is primitive if it is non-empty, and cannot be split into two or more non-empty substrings which are also a valid parentheses.

Examples:

Input: S = “(()())(())()” 
Output: ()()() 
Explanation: The input string is “(()())(())()” can be decomposed into primitive substrings “(()())” + “(())”+”()”. After removing outermost parentheses of each primitive substrings, the string obtained is “()()” + “()” = “()()()”


Input: S = “((()())(())(()(())))” 
Output: (()())(())(()(()))
*/
#include <iostream>
using namespace std;

//Time Complexity: O(N) where n is number of elements in given string. As, we are using a loop to traverse N times so it will cost us O(N) time 
//Auxiliary Space: O(N), as we are using extra space for string.
string removed_outermost_paranthesis(string str)
{
    string result;
    int count = 0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '(' && count++ > 0)
        {
            result += str[i];
        }
        if(str[i] == ')' && count-- > 1)
        {
            result += str[i];
        }
    }
    return result;
}

//This approach has a time complexity of O(n), where n is the length of the input string s. It uses constant space, except for the output string, which is proportional to the number of valid parentheses pairs in s.
string removed_outermost_paranthesis_1(string str)
{
    string result;
    int openCount = 0, closeCount = 0, start = 0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '(')
        {
            openCount++;
        }
        else if(str[i] == ')')
        {
            closeCount++;
        }
        if(openCount == closeCount)
        {
            result += str.substr(start+1,i-start-1);
            start = i + 1;
        }
    }
    return result;
}

int main()
{
    string str;
    cout<<"Enter the string :"<<endl;
    getline(cin,str);
    cout<<"String after removing outermost paranthesis : "<<removed_outermost_paranthesis(str)<<endl;
    cout<<"String after removing outermost paranthesis : "<<removed_outermost_paranthesis_1(str)<<endl;
    return 0;
}