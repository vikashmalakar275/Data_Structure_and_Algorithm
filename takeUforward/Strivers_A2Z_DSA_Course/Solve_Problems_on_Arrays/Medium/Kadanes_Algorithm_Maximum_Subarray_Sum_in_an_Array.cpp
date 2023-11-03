/*
Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.

Examples
Example 1:

Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 

Output: 6 

Explanation: [4,-1,2,1] has the largest sum = 6. 

Examples 2: 

Input: arr = [1] 

Output: 1 

Explanation: Array has only one element and which is giving positive sum of 1.
*/

#include <iostream>
using namespace std;


//Brute Force approach
//TC = O(n3)
//SC = O(1)
int maxSubarraySum_1(vector<int> arr)
{
    int max_result = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i;j<arr.size();j++)
        {
            int sum = 0;
            for(int k=i;k<=j;k++)
            {
                sum += arr[k];
            }
            if(sum>max_result)
            {
                max_result = sum;
            }
        }
    }
    return max_result;
}

//Better Approach
//TC = O(n2)
//SC = O(1)
int maxSubarraySum_2(vector<int> arr)
{
    int max_result = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        int sum = 0;
        for(int j=i;j<arr.size();j++)
        {
            sum += arr[j];
            if(sum>max_result)
            {
                max_result = sum;
            }
        }
    }
    return max_result;
}

//Optimal Solution
//TC = O(n)
//SC = O(1)
int maxSubarraySum_3(vector<int> arr)
{
    int max_result = 0;
    int sum = 0;
    for(int i=0;i<arr.size();i++)
    {
        sum += arr[i];
        if(sum>max_result)
        {
            max_result = sum;
        }
        if(sum<0)
        {
            sum = 0;
        }
    }

    return max_result;
}

int main()
{
    int n;
    cout<<"Enter the Size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Maximum Subarray Sum = "<<maxSubarraySum_1(arr)<<endl;
    cout<<"Maximum Subarray Sum = "<<maxSubarraySum_2(arr)<<endl;
    cout<<"Maximum Subarray Sum = "<<maxSubarraySum_3(arr)<<endl;
    return 0;
}