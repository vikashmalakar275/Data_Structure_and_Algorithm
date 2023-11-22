/*
Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
Example 1:
Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result: 5
Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!

Example 2:
Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result: 8
Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
Length of longest subarray = 8

Example 3:
Input Format: N = 3, array[] = {1, 0, -5}
Result: 1
Subarray : {0}
Length of longest subarray = 1

Example 4:
Input Format: N = 5, array[] = {1, 3, -5, 6, -2}
Result: 0
Subarray: There is no subarray that sums to zero
*/
#include <iostream>
using namespace std;

//brute force approach
int lengthSumZero_1(vector<int> arr)
{
    int maxlen = 0;
    int sum = 0;
    unordered_map<int,int> sumIndexMap;

    for(int i=0;i<arr.size();i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            maxlen = i+1;
        }
        else if(sumIndexMap.find(sum) != sumIndexMap.end()) 
        {
            maxlen = max(maxlen,i - sumIndexMap[sum]);
        }
        else
        {
            sumIndexMap[sum] = i;
        }
    }
    return maxlen;
}

int lengthSumZero_2(vector<int> arr)
{
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<arr.size();i++) 
    {
        sum += arr[i]; 
        if(sum == 0)
        {
            maxi = i + 1; 
        }
        else 
        {
            if(mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else
            {
                mpp[sum] = i;
            }
        }   
    }
    return maxi;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout<<"Length of Longest subarray with zero sum = "<<lengthSumZero_1(arr)<<endl;
    cout<<"Length of Longest subarray with zero sum = "<<lengthSumZero_2(arr)<<endl;
}