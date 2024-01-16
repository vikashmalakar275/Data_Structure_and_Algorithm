/*
Given a string s1 and a string s2, write a function to check whether s2 is a rotation of s1. 

Examples: 

Input: S1 = ABCD, S2 = CDAB
Output: Strings are rotations of each other

Input: S1 = ABCD, S2 = ACBD
Output: Strings are not rotations of each other
*/

#include <iostream>
#include <algorithm>
using namespace std;
bool CheckAnagrams(string str1, string str2)
{
  // when both of the strings have different lengths
  if (str1.length() != str2.length())
    return false;
 
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
      return false;
  }
  return true;
}
int main()
{
  string Str1 = "INTEGER";
  string Str2 = "TEGERNI";
  if(CheckAnagrams(Str1, Str2))
  cout << "True" << endl;
  else
  cout<<"False"<<endl;
  return 0;
}