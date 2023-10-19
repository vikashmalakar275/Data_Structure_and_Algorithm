/*
Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Note: Return k after placing the final result in the first k slots of the array.

Examples
Example 1: 

Input: arr[1,1,2,2,2,3,3]

Output: arr[1,2,3,_,_,_,_]

Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Example 2: 

Input: arr[1,1,1,2,2,3,3,3,3,4,4]

Output: arr[1,2,3,4,_,_,_,_,_,_,_]

Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.
*/
#include <iostream>
#include <set>
using namespace std;

//Brute Force Approach
// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n) 
int removed_duplicate_element_1(vector<int> &arr)
{
    set < int > set;
    int n = arr.size();
    for (int i = 0; i < n; i++) 
    {
        set.insert(arr[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

//Optimal Solution
// Time Complexity: O(N)
// Space Complexity: O(1)
void removed_duplicate_element_2(vector<int> arr)
{
    int i = 0;
    int n = arr.size();
    for (int j = 1; j < n; j++) 
    {
        if (arr[i] != arr[j]) 
        {
            i++;
            arr[i] = arr[j];
        }
    }
    int k = i-1;
    cout << "The array after removing duplicate elements is " << endl;
    for (int l = 0; l < k; l++) 
    {
        cout << arr[l] << " ";
    }
    cout<<endl;
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
    int k = removed_duplicate_element_1(v);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++) 
    {
        cout << v[i] << " ";
    }
    cout<<endl;
    removed_duplicate_element_2(v);

    
    return 0;
}