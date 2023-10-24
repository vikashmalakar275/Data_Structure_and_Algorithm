/*
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.

Examples
Example 1:
Input:
n = 5,m = 5.
arr1[] = {1,2,3,4,5}  
arr2[] = {2,3,4,4,5}
Output:
 {1,2,3,4,5}

Explanation: 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5} 

Example 2:
Input:
n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 
*/
#include <iostream>
#include <map>
#include <set>
using namespace std;

vector < int > Union_1(vector<int> arr1, vector<int> arr2, int n, int m) {
  map < int, int > freq;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    freq[arr1[i]]++;
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;
  for (auto & it: freq)
    Union.push_back(it.first);
  return Union;
}

vector < int > Union_2(vector<int> arr1, vector<int> arr2, int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto & it: s)
    Union.push_back(it);
  return Union;
}

vector < int > Union_3(vector<int> arr1, vector<int> arr2, int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main()
{
    int n;
    cout<<"Enter the size of First Array :"<<endl;
    cin>>n;
    vector<int> arr1;
    cout<<"Enter the Element for First Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a1;
        cin>>a1;
        arr1.push_back(a1);
    }
    int m;
    cout<<"Enter the size of Second Array :"<<endl;
    cin>>m;
    vector<int> arr2;
    cout<<"Enter the Element for Second Array :"<<endl;
    for(int i=0;i<m;i++)
    {
        int a2;
        cin>>a2;
        arr2.push_back(a2);
    }
    vector < int > Union1 = Union_1(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union1)
    {
        cout << val << " ";
    }
    cout<<endl;
    vector < int > Union2 = Union_2(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union2)
    {
        cout << val << " ";
    }
    cout<<endl;
    vector < int > Union3 = Union_3(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union3)
    {
        cout << val << " ";
    }
    cout<<endl;
}