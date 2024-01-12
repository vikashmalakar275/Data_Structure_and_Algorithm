/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
#include <algorithm>
#include <iostream>
using namespace std;

string longestCommonPrefix(vector<string>& str) 
{
    string ans;
    for(int i=0;i<str.size();i++)
    {
        char currentChar = str[0][i];
        for(int j=1;j<str.size();j++)
        {
            if(i>=str[j].size() || str[j][i] != currentChar)
            {
                return str[0].substr(0,i);
            }
        }
    }
    return str[0];
}

string longestCommonPrefix_1(vector<std::string>& strs)
{
    sort(strs.begin(), strs.end());
    string& first = strs.front();
    string& last = strs.back();
    int commonLen = 0;
    int minLen = min(first.length(), last.length());
    while (commonLen < minLen && first[commonLen] == last[commonLen]) 
    {
        ++commonLen;
    }

    return first.substr(0, commonLen);
}

int main()
{
    int n;
    cout<<"Enter the size of Array :"<<endl;
    cin>>n;
    vector<string> str;
    cout<<"Enter the element in array :"<<endl;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        str.push_back(s);
    }
    cout<<"Longest Common Prefix = "<<longestCommonPrefix(str)<<endl;
    cout<<"Longest Common Prefix = "<<longestCommonPrefix_1(str)<<endl;
}