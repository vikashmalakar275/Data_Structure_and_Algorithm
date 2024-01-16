/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/
#include <iostream>
#define MAX_CHARS 256
using namespace std;

//Time Complexity: O(N), Traversing over the string of size N
//Auxiliary Space: O(1)
bool isIsomorphic(string str1,string str2)
{
    if(str1.length() != str2.length())
    {
        return false;
    }

    bool marked[MAX_CHARS] = {false};
    int map[MAX_CHARS];
    memset(map,-1,sizeof(map));
    for(int i=0;i<str1.length();i++)
    {
        if(map[str1[i]] == -1)
        {
            if(marked[str2[i]] == true)
            {
                return false;
            }
            marked[str2[i]] = true;
            map[str2[i]] = str1[i];
        }
        else if(map[str1[i]] != str2[i])
        {
            return false;
        }
    }
    return true;
}

//Time Complexity: O(N), Traversing over the string of size N
//Auxiliary Space: O(1)
bool isIsomorphic_1(string str1, string str2)
{
    unordered_map<char, char> charCount;
    for (int i = 0; i < str1.length(); i++) 
    {
        if (charCount.count(str1[i]))
        {
            if (charCount[str1[i]] != str2[i])
            {
                return false;
            }
        }
        else
        {
            vector<char> values;
            for(auto it : charCount)
            {
                values.push_back(it.second);
            }
            if (find(values.begin(), values.end(), str2[i]) != values.end())
            {
                return false;
            }
            else
            {
                charCount[str1[i]] = str2[i];
            }
        }
    }
    return true;
}

int main()
{
    string str1;
    string str2;
    cout<<"Enter the First String :"<<endl;
    getline(cin,str1);
    cout<<"Enter the Second String :"<<endl;
    getline(cin,str2);
    string result = isIsomorphic(str1,str2) ? "True" : "False";
    cout<<"Is Isomorphic = "<<result<<endl;
    string result1 = isIsomorphic_1(str1,str2) ? "True" : "False";
    cout<<"Is Isomorphic = "<<result<<endl;
}