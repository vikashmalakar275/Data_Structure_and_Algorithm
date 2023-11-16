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
#include <map>
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

//Optimizing the Naive Approach (Using two loops)
//Time Complexity: O(N2) approx., where N = size of the array.
//Reason: We are using two nested loops, each running approximately N times.
//Space Complexity: O(1) as we are not using any extra space.
int getLongestSubarray_2(vector<int> arr,int k)
{
    int len = 0;
    for(int i=0;i<arr.size();i++)
    {
        int sum = 0;
        for(int j=i;j<arr.size();j++)
        {
            sum += arr[j];
            if(sum == k)
            {
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}

//Better Approach (using hashing)
//Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
//Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
//Space Complexity: O(N) as we are using a map data structure.
int getLongestSubarray_3(vector<int> arr,int k)
{
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if(sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) 
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()) 
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

//Optimal Approach (using 2 pointers)
//Time Complexity: O(2*N), where N = size of the given array.
//Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times rather it can run for n times in total. So, the time complexity will be O(2*N) instead of O(N2).
//Space Complexity: O(1) as we are not using any extra space.
int getLongestSubarray_4(vector<int> arr,int k)
{
    int left = 0, right = 0;
    int sum = arr[0];
    int maxLen = 0;
    while (right < arr.size()) 
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < arr.size())
        {
            sum += arr[right];
        }
    }
    return maxLen;
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
    cout<<"The length of the longest subarray is: "<<getLongestSubarray_2(arr,k)<<endl;
    cout<<"The length of the longest subarray is: "<<getLongestSubarray_3(arr,k)<<endl;
    cout<<"The length of the longest subarray is: "<<getLongestSubarray_4(arr,k)<<endl;
}