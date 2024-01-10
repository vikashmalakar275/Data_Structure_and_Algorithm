/*
Problem Statement: Given a string s, reverse the words of the string.

Examples:

Example 1:
Input: s=”this is an amazing program”
Output: “program amazing an is this”

Example 2:
Input: s=”This is decent”
Output: “decent is This”
*/
#include <iostream>
#include <stack>
using namespace std;

//Time Complexity: O(N), Traversing the entire string
//Space Complexity: O(N), Stack and ans variable
string reverse_word_1(string str)
{
    str += " ";
    stack<string> st;
    string result;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] != ' ')
        {
            result += str[i];
        }
        else
        {
            st.push(result);
            result = "";
        }
    }
    string ans;
    while(st.size() != 1)
    {
        ans += st.top() + " ";
        st.pop();
    }
    ans += st.top();
    return ans;
}

//Time Complexity: O(N), N~length of string
//Space Complexity: O(1), Constant Space
string reverse_word_2(string str)
{
    int left = 0;
    int right = str.length()-1;
    string temp="";
    string ans="";
    while (left <= right)
    {
        char ch= str[left];
        if (ch != ' ')
        {
            temp += ch;
        } 
        else if (ch == ' ')
        {
            if (ans!="")
            {
                ans = temp + " " + ans;
            }
            else 
            {
                ans = temp;
            }
            temp = "";
        }
        left++;
    }
    if(temp!="")
    {
        if (ans!="") 
        {
            ans = temp + " " + ans;
        }
        else 
        {
            ans = temp;
        }
    }
    return ans;  
}

int main()
{
    string str;
    cout<<"Enter the string :"<<endl;
    getline(cin,str);
    cout<<"Reverse Word : "<<reverse_word_1(str)<<endl;
    cout<<"Reverse Word : "<<reverse_word_2(str)<<endl;
    return 0;
}