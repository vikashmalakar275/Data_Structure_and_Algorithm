/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

Pre-requisite: Search Element in Rotated Sorted Array I & Binary Search algorithm

Examples
Example 1:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Result: True
Explanation: The element 3 is present in the array. So, the answer is True.

Example 2:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Result: False
Explanation: The element 10 is not present in the array. So, the answer is False.
*/
#include <iostream>
using namespace std;

//Time Complexity: O(N), N = size of the given array.
//Reason: We have to iterate through the entire array to check if the target is present in the array.
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
bool rotated_sorted_1(vector<int> arr, int x)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

bool rotated_sorted_2(vector<int> arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == x)
        {
            return true;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(arr[low] <= arr[mid])
        {
            if (arr[low] <= x && x <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= x && x <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
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
    if(rotated_sorted_1(arr,search))
    {
        cout<<"Element is present."<<endl;
    }
    else
    {
        cout<<"Element is not present."<<endl;
    }
    if(rotated_sorted_2(arr,search))
    {
        cout<<"Element is present."<<endl;
    }
    else
    {
        cout<<"Element is not present."<<endl;
    }
}