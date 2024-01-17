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

int main()
{
  string str1;
  cout<<"Enter the first string :"<<endl;
  getline(cin,str1);
  string str2;
  cout<<"Enter the second string :"<<endl;
  getline(cin,str2);
}