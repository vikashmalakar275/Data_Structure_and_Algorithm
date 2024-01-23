/*
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that has exactly k distinct characters. 

Examples: 

Input: abc, k = 2
Output: 2
Possible substrings are {“ab”, “bc”}

Input: aba, k = 2
Output: 3
Possible substrings are {“ab”, “ba”, “aba”}

Input: aa, k = 1
Output: 3
Possible substrings are {“a”, “a”, “aa”}
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//Time Complexity: O(n*n)
//Auxiliary Space: O(1), Only 26 size array is used, which can be considered constant space.
int count_number_of_substring_1(string str,int k)
{
    int n = str.length();
    int res = 0;
    int cnt[26];
    for(int i=0;i<n;i++)
    {
        int dist_count = 0;
        memset(cnt,0,sizeof(cnt));
        for(int j=i;j<n;j++)
        {
            if(cnt[str[j]-'a'] == 0)
            {
                dist_count++;
            }
            cnt[str[j] - 'a']++;
            if(dist_count == k)
            {
                res++;
            }
            if(dist_count > k)
            {
                break;
            }
        }
    }
    return res;
}

//Time Complexity: O(n)
//Auxiliary Space: O(1)
int most_k_char(string str,int k)
{
    if(str.length() == 0)
    {
        return 0;
    }
    unordered_map<char,int> map;
    int num = 0, left = 0;
    for (int i=0;i<str.length();i++)
    {
        map[str[i]]++;
        while (map.size()>k)
        {
            map[str[left]]--;
            if (map[str[left]] == 0)
            {
                map.erase(str[left]);
            }
            left++;
        }
        num += i-left+1;
    }
    return num;
}
int count_number_of_substring_2(string str,int k)
{
    return most_k_char(str,k) - most_k_char(str,k-1);
}

int main()
{
    string str;
    cout<<"Enter the String :"<<endl;
    getline(cin,str);
    int k;
    cout<<"Enter the value of K :"<<endl;
    cin>>k;
    cout<<"Total Number of String = "<<count_number_of_substring_1(str,k)<<endl;
    cout<<"Total Number of String = "<<count_number_of_substring_2(str,k)<<endl;
    return 0;
}