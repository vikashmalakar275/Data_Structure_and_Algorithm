/*
Balanced parenthesis problem
Today in this article we will learn how to solve Balanced Parenthesis problem.

Lets understand this with the help of an example:- 

Input: str = “[{}]” 
Output: balanced

Algorithm
Initialize a character stack st
Now traverse the string s
If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack st.
If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then check if the st is empty or not and also check if the top of the stack is the same opening brackets if it’s true then pop from stack otherwise put ans = false and break.
At last check if stack is empty or not if its not empty return false
At the end of the function return ans.
In the main function inside if function check the string and print if the string is balanced or not 
*/

#include <iostream>

using namespace std;

int main()
{
    return 0;
}