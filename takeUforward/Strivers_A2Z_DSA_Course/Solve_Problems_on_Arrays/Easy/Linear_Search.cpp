/*
Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Examples:

Example 1:
Input: arr[]= 1 2 3 4 5, num = 3
Output: 2
Explanation: 3 is present in the 2nd index

Example 2:
Input: arr[]= 5 4 3 2 1, num = 5
Output: 0
Explanation: 5 is present in the 0th index
*/

#include <iostream>
using namespace std;

//Time Complexity: O(n), where n is the length of the array.
//Space Complexity: O(1)
int linearSearch(vector<int> arr, int search)
{
    for(int i=0;i<arr.size();i++)
    {
        if(search==arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the Element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int searchedElement;
    cout<<"Enter the element you want to search :"<<endl;
    cin>>searchedElement;
    int result = linearSearch(arr,searchedElement);
    if(result>-1)
    {
        cout<<searchedElement<<" found at index = "<<result<<endl;
    }
    else
    {
        cout<<searchedElement<<" not found"<<endl;
    }
}