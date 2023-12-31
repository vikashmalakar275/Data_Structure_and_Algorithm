/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

Examples
Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
Result: 4
Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Example 2:
Input Format: arr = [4,5,6,7,0,1,2], k = 3
Result: -1
Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.
*/
#include <iostream>
using namespace std;

//Time Complexity: O(N), N = size of the given array.
//Reason: We have to iterate through the entire array to check if the target is present in the array.
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
int rotated_sorted_1(vector<int> arr, int x)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are using binary search to search the target.
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
int rotated_sorted_2(vector<int> arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == x)
        {
            return mid;
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
    return -1;
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
    cout <<"Element "<<search<<" found is at index = "<<rotated_sorted_1(arr,search)<<endl;
    cout <<"Element "<<search<<" found is at index = "<<rotated_sorted_2(arr,search)<<endl;
}