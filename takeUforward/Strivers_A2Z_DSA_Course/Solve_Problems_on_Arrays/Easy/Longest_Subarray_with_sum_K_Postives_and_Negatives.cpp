/*
Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Examples
Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.
*/


#include <iostream>
using namespace std;

//Brute Force Approach
//TC = O(n3)
//SC = O(1)
int getLongestSubarray_1(vector<int> arr,int k)
{
    int len = 0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i;j<arr.size();j++)
        {
            int sum = 0;
            for(int k=i;k<=j;k++)
            {
                sum += arr[k];
            }
            if(sum==k)
            {
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}


int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    int k;
    cout<<"Enter the sum :"<<endl;
    cin>>k;
    vector<int> arr;
    cout<<"Enter the element of array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<"The length of the longest subarray is: "<<getLongestSubarray_1(arr,k)<<endl;
}