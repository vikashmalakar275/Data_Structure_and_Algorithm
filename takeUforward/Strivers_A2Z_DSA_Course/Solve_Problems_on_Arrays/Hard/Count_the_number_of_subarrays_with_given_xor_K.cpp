/*
Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.
Example 1:
Input Format: A = [4, 2, 2, 6, 4] , k = 6
Result: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Example 2:
Input Format: A = [5, 6, 7, 8, 9], k = 5
Result: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/

#include <iostream>
#include <map>
using namespace std;

int countSubarray_XOR_1(vector<int> arr,int k)
{
    int count = 0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i;j<arr.size();j++)
        {
            int xorr = 0;
            for(int k=i;k<=j;k++)
            {
                xorr = xorr^arr[k];
            }
            if(xorr == k)
            {
                count++;
            }
        }
    }
    return count;
}

int countSubarray_XOR_2(vector<int> arr,int k)
{
    int count = 0;
    for(int i=0;i<arr.size();i++)
    {
        int xorr = 0;
        for(int j=i;j<arr.size();j++)
        {
            xorr = xorr^arr[j];
            if(xorr == k)
            {
                count++;
            }
        }
    }
    return count;   
}


int countSubarray_XOR_3(vector<int> arr, int k)
{
    int xorr = 0;
    map<int, int> mpp;
    mpp[xorr]++;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        xorr = xorr ^ arr[i];
        int x = xorr ^ k;
        count += mpp[x];
        mpp[xorr]++;
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of the array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int k;
    cout<<"Enter the value pof K"<<endl;
    cin>>k;
    cout<<"The number of subarray with given XOR "<<k<<" = "<<countSubarray_XOR_1(arr,k)<<endl;
    cout<<"The number of subarray with given XOR "<<k<<" = "<<countSubarray_XOR_2(arr,k)<<endl;
    cout<<"The number of subarray with given XOR "<<k<<" = "<<countSubarray_XOR_3(arr,k)<<endl;
}