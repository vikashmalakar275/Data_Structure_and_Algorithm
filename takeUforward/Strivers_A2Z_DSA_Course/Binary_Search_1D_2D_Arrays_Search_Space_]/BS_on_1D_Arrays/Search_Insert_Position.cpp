/*
Search Insert Position
Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

Pre-requisite: Lower Bound & Binary Search

Example 1:
Input Format: arr[] = {1,2,4,7}, x = 6
Result: 3
Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

Example 2:
Input Format: arr[] = {1,2,4,7}, x = 2
Result: 1
Explanation: 2 is present in the array and so we will return its index i.e. 1.
*/

#include <iostream>
using namespace std;

//Brute Force Approach
//Time Complexity: O(N), where N = size of the given array.
//Reason: In the worst case, we have to travel the whole array. This is basically the time complexity of the linear search algorithm.
//Space Complexity: O(1) as we are using no extra space.
int Lower_Bound_1(vector<int> arr,int target)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>=target)
        {
            return i;
        }
    }
    return -1;
}

//Optimal Solution
//Time Complexity: O(logN), where N = size of the given array.
//Reason: We are basically using the Binary Search algorithm.
//Space Complexity: O(1) as we are using no extra space.
int Lower_Bound_2(vector<int> arr,int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid]>=target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

//By using inbuilt function;
int Lower_Bound_3(vector<int> arr,int x)
{
    int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
    return lb;
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
    cout <<"insert position = "<<Lower_Bound_1(arr,search)<<endl;
    cout <<"insert position = "<<Lower_Bound_2(arr,search)<<endl;
    cout <<"insert position = "<<Lower_Bound_3(arr,search)<<endl;
}