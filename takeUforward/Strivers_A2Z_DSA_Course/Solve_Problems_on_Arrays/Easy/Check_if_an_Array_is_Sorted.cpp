/*
Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

Note: Two consecutive equal values are considered to be sorted.

Examples
Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.


Example 2:
Input: N = 5, array[] = {5,4,6,7,8}
Output: False.
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.

Here element 5 is not smaller than or equal to its future elements.
*/

#include <iostream>
#include <algorithm>
using namespace std;


//Brute force approach
//TC = O(n^2)
//TC = O(1)
bool isSorted_1(vector<int> arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i])
        return false;
    }
  }

  return true;
}


//Optimal Solution
//TC = O(n)
//TC = O(1)
bool isSorted_2(vector<int> arr,int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> v;
    cout<<"Enter the element of array ;"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    string str = (isSorted_1(v,n) && isSorted_2(v,n))? " is sorted. ": " is not sorted";
    cout<<" array "<<str<<endl;
    return 0;
}