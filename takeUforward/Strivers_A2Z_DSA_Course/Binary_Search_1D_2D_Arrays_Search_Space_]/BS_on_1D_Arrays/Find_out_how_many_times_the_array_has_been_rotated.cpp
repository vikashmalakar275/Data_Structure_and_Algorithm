/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3]
Result: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Example 2:
Input Format: arr = [3,4,5,1,2]
Result: 3
Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.

*/

#include <iostream>
using namespace std;

//Time Complexity: O(N), N = size of the given array.
//Reason: We have to iterate through the entire array to check if the target is present in the array.
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
int Count_total_rotation_1(vector<int> arr)
{
    int n = arr.size();
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < ans) {
            ans = arr[i];
            index = i;
        }
    }
    return index;
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are basically using binary search to find the minimum.
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
int Count_total_rotation_2(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int min_no = arr[0];
    int minIndex = -1;
    while(low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<min_no)
            {
                minIndex = low;
                min_no = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if(arr[mid]<min_no)
            {
                minIndex = mid;
                min_no = arr[mid];
            }
            high = mid - 1;
        }
    }
    return minIndex;
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
    cout <<"Number of Times array is rotated = "<<Count_total_rotation_1(arr)<<endl;
    cout <<"Number of Times array is rotated = "<<Count_total_rotation_2(arr)<<endl;
}