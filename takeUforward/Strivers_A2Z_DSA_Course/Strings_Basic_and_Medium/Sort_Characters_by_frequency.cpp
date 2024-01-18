/*
Given a string str, the task is to sort the string according to the frequency of each character, in ascending order. If two elements have the same frequency, then they are sorted in lexicographical order.
Examples: 

Input: str = “geeksforgeeks” 
Output: forggkksseeee 
Explanation: 
Frequency of characters: g2 e4 k2 s2 f1 o1 r1 
Sorted characters according to frequency: f1 o1 r1 g2 k2 s2 e4 
f, o, r occurs one time so they are ordered lexicographically and so are g, k and s. 
Hence the final output is forggkksseeee.
Input: str = “abc” 
Output: abc 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countFrequency(string str,char ch)
{
    int count = 0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == ch)
        {
            count++;
        }
    }
    return count;
}

//Time Complexity: O(n2)
//Auxiliary Space: O(n)
string sort_string_by_frequency(string str)
{
    int n = str.length();
    string ans = "";

    vector<pair<int,char> > vp;

    for(int i=0;i<n;i++)
    {
        vp.push_back(make_pair(countFrequency(str,str[i]),str[i]));
    }

    sort(vp.begin(),vp.end());
    for(int i=0;i<vp.size();i++)
    {
        ans += vp[i].second;
    }
    return ans;
}

int main()
{
    string str;
    cout<<"Enter the string :"<<endl;
    getline(cin,str);
    cout<<"String After sorted by frequency :"<<sort_string_by_frequency(str)<<endl;
}