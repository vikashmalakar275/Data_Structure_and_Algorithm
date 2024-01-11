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

string longestCommonPrefix(vector<string>& S) 
{
    if (S.size() == 0) return "";
    std::string prefix = S[0];
    for(int i = 1; i < S.size(); ++i)
    {
        std::string s = S[i];
        if (s.size() == 0 || prefix == "") return "";
        prefix = prefix.substr(0, std::min(prefix.size(), s.size()) );    
        for(int k = 0; k < s.size() && k < prefix.size(); ++k)
        {
            if (s[k] != prefix[k])
            {
                prefix = prefix.substr(0, k);
                break;
            }
        }
    }
    return prefix;
}

int main()
{
    vector<string> s = {"flow", "flower", "flight"};
    cout << longestCommonPrefix(s) << endl;
    return 0;
}