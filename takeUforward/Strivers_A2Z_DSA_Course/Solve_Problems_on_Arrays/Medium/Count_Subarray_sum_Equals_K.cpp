/*
Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.
Example 1:
Input Format: N = 4, array[] = {3, 1, 2, 4}, k = 6
Result: 2
Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

Example 2:
Input Format: N = 3, array[] = {1,2,3}, k = 3
Result: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
*/

#include <iostream>
using namespace std;

//Brute Force Approach
//TC = O(n3)
//SC = O(1)
int countSubarray_1(vector<int> arr,int k)
{
    int count = 0;
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
                count++;
            }
        }
    }
    return count;
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
    cout<<"The subarrays that sum up to "<<k<<" are: "<<countSubarray_1(arr,k)<<endl;
}