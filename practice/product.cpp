/*
Given an array that contains both positive and negative integers, find the product of the 
maximum product subarray. TC=O(n) SC=O(1)

Examples:                                                                                                                                                                                      
Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60  // The subarray is {60}

Input: arr[] = {-1, -3, -10, 0, 0}
Output:   30  // The subarray is {-3, -10}
*/

#include <iostream>
#include <math.h>

using namespace std;

//Brute Force Approach
//TC = O(n^3)
int maxProductSubarray_1(vector<int> &arr)
{
    cout<<"Brute Force Approach "<<endl;
    int Max = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i;j<arr.size();j++)
        {
            int product = 1;
            for(int k=i;k<=j;k++)
            {
                product *= arr[k];
            }
            Max = max(Max,product);
        }
    }
    return Max;
}

//Better Approach
//We can optimize the brute force by making 3 nested iterations to 2 nested iterations
//TC = O(n^2)
int maxProductSubarray_2(vector<int> &arr)
{
    cout<<"Better Approach "<<endl;
    int Max = INT_MIN;
    int product = 1;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i;j<arr.size();j++)
        {
            product *= arr[j];
            Max = max(Max,product);
        }
    }
    return Max;
}

//Optimal solution
int maxProductSubarray_3(vector<int> &arr) 
{
    cout<<"Optimal Solution"<<endl;
    int prefix = 1, suffix = 1;
    int MAX = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;
        prefix *= arr[i];
        suffix *= arr[arr.size() - i - 1];
        MAX = max(MAX, max(prefix, suffix));
    }
    return MAX;
}

//Kadane's Algorithm
int maxProductSubarray_4(vector<int>& nums) 
{
    cout<<"Kadane's Algorithm"<<endl;
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max(nums[i],max(prod1*nums[i],prod2*nums[i]));
        prod2 = min(nums[i],min(prod1*nums[i],prod2*nums[i]));
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}

int main()
{
    int n;
    cout<<"Enter the size of Array :"<<endl;
    cin>>n;
    int a;
    vector<int> arr;
    cout<<"enter The element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    cout<<"The Maximum product of Subarray is :"<<maxProductSubarray_1(arr)<<endl;
    cout<<"The Maximum product of Subarray is :"<<maxProductSubarray_2(arr)<<endl;
    cout<<"The Maximum product of Subarray is :"<<maxProductSubarray_3(arr)<<endl;
    cout<<"The Maximum product of Subarray is :"<<maxProductSubarray_4(arr)<<endl;
}