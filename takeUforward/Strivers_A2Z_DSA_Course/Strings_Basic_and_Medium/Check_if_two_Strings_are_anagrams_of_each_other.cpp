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
using namespace std;

bool checkString(string& s1, string& s2, int indexFound,
				int Size)
{
	for (int i = 0; i < Size; i++) {
		// check whether the character is equal or not
		if (s1[i] != s2[(indexFound + i) % Size])
			return false;
		// %Size keeps (indexFound+i) in bounds, since it
		// ensures it's value is always less than Size
	}

	return true;
}

int main()
{

	string s1 = "abcd";
	string s2 = "cdab";

	if (s1.length() != s2.length()) {
		cout << "s2 is not a rotation on s1" << endl;
	}
	else {
		// store occurrences of the first character of s1
		vector<int> indexes;

		int Size = s1.length();

		char firstChar = s1[0];

		for (int i = 0; i < Size; i++) {
			if (s2[i] == firstChar) {
				indexes.push_back(i);
			}
		}

		bool isRotation = false;

		// check if the strings are rotation of each other
		// for every occurrence of firstChar in s2
		for (int idx : indexes) {
			isRotation = checkString(s1, s2, idx, Size);

			if (isRotation)
				break;
		}

		if (isRotation)
			cout << "Strings are rotations of each other"
				<< endl;
		else
			cout
				<< "Strings are not rotations of each other"
				<< endl;
	}
	return 0;
}
