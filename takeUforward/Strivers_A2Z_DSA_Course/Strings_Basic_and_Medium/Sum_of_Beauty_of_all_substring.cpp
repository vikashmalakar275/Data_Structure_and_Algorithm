/*
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/
#include <iostream>
#include <string>
using namespace std;

int getMax(vector<int> freq)
{
    int maxi = INT_MIN;
    for(int i=0;i<sizeof(freq);i++)
    {
        if(freq[i] != 0)
        {
            maxi = max(maxi,freq[i]);
        }
    }
    return maxi;
}
int getMin(vector<int> freq)
{
    int mini = INT_MAX;
    for(int i=0;i<sizeof(freq);i++)
    {
        if(freq[i] != 0)
        {
            mini = min(mini,freq[i]);
        }
    }
    return mini;
}

int sum_of_beauty_of_all_substring(string str)
{
    int ans = 0;
    for(int i=0;i<str.length();i++)
    {
        vector<int> freq(26,0);
        for(int j=i;j<str.length();j++)
        {
            freq[str[j]-'a']++;
            int min = getMin(freq);
            int max = getMax(freq);
            int beauty = max - min;
            ans += beauty;
        }
    }
    return ans;
}

int main()
{
    string str;
    cout<<"Enter the String :"<<endl;
    getline(cin,str);
    cout<<"Sum of Beauty of All Substring = "<<sum_of_beauty_of_all_substring(str)<<endl;
    return 0;
}