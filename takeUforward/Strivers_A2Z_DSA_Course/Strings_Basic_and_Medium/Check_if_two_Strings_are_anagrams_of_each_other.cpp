/*
Problem Statement: Given two strings, check if two strings are anagrams of each other or not.

Examples:

Example 1:
Input: CAT, ACT
Output: true
Explanation: Since the count of every letter of both strings are equal.

Example 2:
Input: RULES, LESRT 
Output: false
Explanation: Since the count of U and T  is not equal in both strings.
*/
// C++ program for the above approach
#include <iostream>
#include <algorithm>
using namespace std;

//Time Complexity: O(nlogn) since sorting function requires nlogn iterations.
//Space Complexity: O(1)
string check_anagrams_1(string str1, string str2)
{
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	if(str1 == str2)
	{
		return "it is anagram.";
	}
	return "it is not anagram.";
}

//Time Complexity: O(n) where n is the length of string
//Space Complexity: O(1) 
string check_anagrams_2(string str1, string str2)
{
  if (str1.length() != str2.length())
  {
	return "it is not anagram.";
  }
  int freq[26] = {0};
  for (int i = 0; i < str1.length(); i++)
  {
    freq[str1[i] - 'A']++;
  }
  for (int i = 0; i < str2.length(); i++)
  {
    freq[str2[i] - 'A']--;
  }
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] != 0)
	{
		return "it is not anagram.";
	}
  }
  return "it is anagram.";
}

int main()
{
	string str1;
	cout<<"Enter the first string :"<<endl;
	getline(cin,str1);
	string str2;
	cout<<"Enter the first string :"<<endl;
	getline(cin,str2);
	cout<<check_anagrams_1(str1,str2)<<endl;
	cout<<check_anagrams_2(str1,str2)<<endl;
}
