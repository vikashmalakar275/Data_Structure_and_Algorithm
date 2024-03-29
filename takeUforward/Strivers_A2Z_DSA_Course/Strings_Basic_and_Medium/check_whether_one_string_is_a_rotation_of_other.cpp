/*
Given a string s1 and a string s2, write a function to check whether s2 is a rotation of s1. 

Examples: 

Input: S1 = ABCD, S2 = CDAB
Output: Strings are rotations of each other

Input: S1 = ABCD, S2 = ACBD
Output: Strings are not rotations of each other
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//Approach-1
//Time Complexity: O(n*n) in the worst case, where n is the length of the string.
//Auxiliary Space: O(n)
bool checkString(string& s1,string& s2,int indexFound,int Size)
{
  for(int i = 0;i<Size;i++)
  {
		if (s1[i] != s2[(indexFound + i) % Size])
    {
      return false;
    }
	}
	return true;
}

string check_whether_string_rotation_of_other(string s1,string s2)
{
  if(s1.length() != s2.length())
  {
		return "s2 is not a rotation on s1";
	}
	else
  {
    vector<int> indexes;
		int Size = s1.length();
		char firstChar = s1[0];
		for(int i=0; i<Size; i++)
    {
      if(s2[i] == firstChar)
      {
        indexes.push_back(i);
			}
		}
		bool isRotation = false;
		for (int idx : indexes)
    {
      isRotation = checkString(s1, s2, idx, Size);
			if (isRotation)
      {
				break;
      }
		}
		if(isRotation)
    {
      return "Strings are rotations of each other";
    }
	}
  return "Strings are not rotations of each other";
}

//Approach-2
//Time Complexity: O(N1 * N2), where N1 and N2 are the lengths of the strings.
//Auxiliary Space: O(N)
string check_rotation(string s, string goal)
{
    if(s.size() != goal.size())
    {
      return "Strings are not rotations of each other";
    }
    queue<char> q1;
    for(int i=0; i<s.size(); i++)
    {
      q1.push(s[i]);
    }
    queue<char> q2;
    for (int i=0; i<goal.size(); i++)
    {
      q2.push(goal[i]);
    }
    int k = goal.size();
    while (k--)
    {
      char ch = q2.front();
      q2.pop();
      q2.push(ch);
      if (q2 == q1)
      {
        return "Strings are rotations of each other";
      }
    }
    return "Strings are not rotations of each other";
}

int main()
{
  string str1;
  cout<<"Enter the first string :"<<endl;
  getline(cin,str1);
  string str2;
  cout<<"Enter the second string :"<<endl;
  getline(cin,str2);
  cout<<check_whether_string_rotation_of_other(str1,str2)<<endl;
  cout<<check_rotation(str1,str2)<<endl;
}