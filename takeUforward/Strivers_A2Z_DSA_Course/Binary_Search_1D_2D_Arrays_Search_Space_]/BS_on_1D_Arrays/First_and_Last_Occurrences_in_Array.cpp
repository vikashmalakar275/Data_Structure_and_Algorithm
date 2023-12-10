/*
Problem Statement: Given a sorted array arr of n integers and a target value k. Write a program to find the indices of the first and the last occurrences of the target value. If the target is not found then return -1 as indices.

Note: Consider 0-based indexing

Pre-requisites: Lower Bound,  Upper Bound, & Binary Search

Examples
Example 1:
Input Format: n = 8, arr[] = {2, 4, 6, 8, 8, 8, 11, 13}, k = 8
Result: 3 5
Explanation: The first occurrence of 8 is at index 3 and the last occurrence is at index 5.

Example 2:
Input Format: n = 8, arr[] = {2, 4, 6, 8, 8, 8, 11, 13}, k = 10
Result: -1 -1
Explanation: The target value is not present in the array. So, we have returned -1 as the indices of the first and the last occurrence.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(N), N = size of the given array
//Reason: We are traversing the entire array.
//Space Complexity: O(1) as we are not using any extra space.
pair<int,int> first_and_last_occurrence_1(vector<int> arr, int x)
{
    int first = -1;
    int last = -1;
    bool isFirstFound = false;
    for(int i=0;i<arr.size();i++)
    {
        if((arr[i] == x) && !isFirstFound)
        {
            first = i;
            last = i;
            isFirstFound = true;
        }
        else if(isFirstFound && (arr[i] == x))
        {
            last = i;
        }
    }
    return make_pair(first,last);
}

//Time Complexity: O(2*logN), where N = size of the given array.
//Reason: We are basically using a lower-bound and upper-bound algorithm.
//Space Complexity: O(1) as we are using no extra space.
int Lower_Bound(vector<int> arr,int target)
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
int Upper_Bound(vector<int> arr,int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid]>target)
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
pair<int,int> first_and_last_occurrence_2(vector<int> arr, int x)
{
    int first = Lower_Bound(arr,x);
    int last = Upper_Bound(arr,x);
    return make_pair(first,last-1);
}

//Time Complexity: O(2*logN), where N = size of the given array.
//Reason: We are basically using the binary search algorithm twice.
//Space Complexity: O(1) as we are using no extra space.
int first_occurence(vector<int> arr, int x)
{
    int first = -1;
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid]<x) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return first;
}
int last_occurence(vector<int> arr, int x)
{
    int last = -1;
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid]<x) 
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}
pair<int,int> first_and_last_occurrence_3(vector<int> arr, int x)
{
    int first = first_occurence(arr,x);
    int last = last_occurence(arr,x);
    return make_pair(first,last);
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
    pair<int,int> ans = first_and_last_occurrence_1(arr,search);
    cout <<"First Occurrence = "<<ans.first<<"\nLast Occurrence = "<<ans.second<<endl;
    pair<int,int> ans1 = first_and_last_occurrence_2(arr,search);
    cout <<"First Occurrence = "<<ans1.first<<"\nLast Occurrence = "<<ans1.second<<endl;
    pair<int,int> ans2 = first_and_last_occurrence_3(arr,search);
    cout <<"First Occurrence = "<<ans2.first<<"\nLast Occurrence = "<<ans2.second<<endl;
}