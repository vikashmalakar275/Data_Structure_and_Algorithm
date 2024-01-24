/*
Given string str, we need to print the reverse of individual words.

Examples:

Input : Hello World

Output : olleH dlroW
*/

#include <iostream>
#include <stack>
using namespace std;

string reverseWord(string str)
{
    string rev = "";
    for(int i=str.length()-1;i>=0;i--)
    {
        rev += str[i];
    }
    return rev;
}

//Time Complexity = O(n*n)
//Spcae Complexity = O(n)
string reverse_every_word_1(string str)
{
    string word = "";
    string result = "";
    for(int i=0;i<str.length();i++)
    {
        if(str[i] != ' ')
        {
            word += str[i];
        }
        else
        {
            //cout<<"Word = "<<word<<endl;
            result += reverseWord(word)+" ";
            word = "";
        }
    }
    result += reverseWord(word);
    return result;
}

//Time Complexity: O(n), where n is the length of the string
//Auxiliary Space: O(n), where n is the length of the string
string reverse_every_word_2(string str)
{
    string result = "";
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] != ' ')
        {
            st.push(str[i]);
        }
        else
        {
            while (st.empty() == false)
            {
                result += st.top();
                st.pop();
            }
            result += " ";
        }
    }
    while (st.empty() == false)
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string str;
    cout<<"Enter the string :"<<endl;
    getline(cin,str);
    cout<<"String after reveresed every words :"<<reverse_every_word_1(str)<<endl;
    cout<<"String after reveresed every words :"<<reverse_every_word_2(str)<<endl;
    return 0;
}