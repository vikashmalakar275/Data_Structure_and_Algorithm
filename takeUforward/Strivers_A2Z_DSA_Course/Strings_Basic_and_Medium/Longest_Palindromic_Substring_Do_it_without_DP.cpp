/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
#include <iostream>
#include <string>
using namespace std;

string longest_palindromic_substring_1(string str)
{
    int maxLength = 1;
    int start = 0;
    for(int i=0;i<str.length();i++)
    {
        for(int j=i;j<str.length();j++)
        {
            int flag = 1;
            for(int k=0;k<(j-i+1)/2;k++)
            {
                if(str[i+k] != str[j-k])
                {
                    flag = 0;
                }
            }
            if(flag && (j-i+1)>maxLength)
            {
                start = i;
                maxLength = j-i+1;
            }
        }
    }
    string res = "";
    for(int l=start;l<=start+maxLength-1;l++)
    {
        res += str[l];
    }
    return res;
}

int main()
{
    string str;
    cout<<"Enter the String :"<<endl;
    getline(cin,str);
    cout<<"Total Number of String = "<<longest_palindromic_substring_1(str)<<endl;
    return 0;
}