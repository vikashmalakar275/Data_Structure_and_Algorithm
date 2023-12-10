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
    //cout <<"smallest index such that arr[i] >= x => "<<Lower_Bound_2(arr,search)<<endl;
    //cout <<"smallest index such that arr[i] >= x => "<<Lower_Bound_3(arr,search)<<endl;
}