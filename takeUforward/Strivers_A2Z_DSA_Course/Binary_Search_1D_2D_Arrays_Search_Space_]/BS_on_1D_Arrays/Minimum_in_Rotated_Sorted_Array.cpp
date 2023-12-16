/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

Pre-requisites: Search in Rotated Sorted Array I,  Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3]
Result: 0
Explanation: Here, the element 0 is the minimum element in the array.

Example 2:
Input Format: arr = [3,4,5,1,2]
Result: 1
Explanation: Here, the element 1 is the minimum element in the array.
*/
#include <iostream>
using namespace std;

//Time Complexity: O(N), N = size of the given array.
//Reason: We have to iterate through the entire array to check if the target is present in the array.
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
int minElement(vector<int> arr)
{
    int min = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(min>arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are basically using binary search to find the minimum.
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
int minElement_1(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int min_no = arr[0];
    while(low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[low]<=arr[mid])
        {
            min_no = min(min_no,arr[low]);
            low = mid + 1;
        }
        else
        {
            min_no = min(min_no,arr[mid]);
            high = mid - 1;
        }
    }
    return min_no;
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are basically using binary search to find the minimum. 
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
int minElement_2(vector<int> arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high]) 
        {
            ans = min(ans, arr[low]);
            break;
        }
        if (arr[low] <= arr[mid]) 
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else 
        {
            ans = min(ans, arr[mid]);
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
    cout <<"Minimum Element = "<<minElement(arr)<<endl;
    cout <<"Minimum Element = "<<minElement_1(arr)<<endl;
    cout <<"Minimum Element = "<<minElement_2(arr)<<endl;
}