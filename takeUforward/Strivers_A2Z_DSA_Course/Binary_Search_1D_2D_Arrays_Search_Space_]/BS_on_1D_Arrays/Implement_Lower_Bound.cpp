/*
Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

Pre-requisite: Binary Search algorithm

Examples
Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
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
    cout <<"smallest index such that arr[i] >= x => "<<Lower_Bound_1(arr,search)<<endl;
    cout <<"smallest index such that arr[i] >= x => "<<Lower_Bound_2(arr,search)<<endl;
    cout <<"smallest index such that arr[i] >= x => "<<Lower_Bound_3(arr,search)<<endl;
}