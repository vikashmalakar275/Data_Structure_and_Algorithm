/*
Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.

Note: Consider 0 based indexing

Examples:

Example 1:
Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
Output: 4
Explanation: As the target value is 13 , it appears for the first time at index number 2.

Example 2:
Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
Output: -1
Explanation: Target value 60 is not present in the array 
*/
#include <iostream>
using namespace std;

//Time Complexity: O(n) 
//Space Complexity: O(1) not considering the given array
int last_occurence_1(vector<int> arr, int x)
{
    int ans = -1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == x)
        {
            ans = i;
        }
    }
    return ans;
}

//Time Complexity: O(log n)
//Space Complexity: O(1)
int last_occurence_2(vector<int> arr, int x)
{
    int ans = -1;
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == x)
        {
            ans = mid;
            low = mid + 1;
        }
        else if(arr[mid]<x) 
        {
            low = mid + 1;
        }
        else if(arr[mid]>x)
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array ;"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int search;
    cout<<"Enter the searched element :"<<endl;
    cin>>search;
    cout <<"Last occurence of "<<search<<"is at index = "<<last_occurence_1(arr,search)<<endl;
    cout <<"Last occurence of "<<search<<"is at index = "<<last_occurence_2(arr,search)<<endl;
}