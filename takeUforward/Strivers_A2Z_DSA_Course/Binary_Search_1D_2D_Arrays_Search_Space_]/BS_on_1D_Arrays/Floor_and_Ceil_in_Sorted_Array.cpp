/*
Problem Statement: You’re given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

Pre-requisite: Lower Bound & Binary Search

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(logN), where N = size of the given array.
//Reason: We are basically using the Binary Search algorithm.
//Space Complexity: O(1) as we are using no extra space.
int getFloor(vector<int> arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid]<=x)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

//Time Complexity: O(logN), where N = size of the given array.
//Reason: We are basically using the Binary Search algorithm.
//Space Complexity: O(1) as we are using no extra space.
int getCeil(vector<int> arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid]>=x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int,int> getFloor_and_Ceil(vector<int> arr, int x)
{
    int f = getFloor(arr,x);
    int c = getCeil(arr,x);
    return make_pair(f,c);
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
    pair<int,int> ans = getFloor_and_Ceil(arr,search);
    cout <<"Floor and Ceil in an array of value "<<search<<" is "<<ans.first<<" & "<<ans.second<<" respectively."<<endl;
}