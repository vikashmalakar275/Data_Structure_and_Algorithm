/*
Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Examples
Example 1:
Input: [1,2,4,7,7,5]
Output: Second Smallest : 2
	Second Largest : 5
Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2

Example 2:
Input: [1]
Output: Second Smallest : -1
	Second Largest : -1
Explanation: Since there is only one element in the array, it is the largest and smallest element present in the array. There is no second largest or second smallest element present.
*/

#include <iostream>
#include <algorithm>
using namespace std;


//Brute force approach
//TC = O(n*log n)
//SC = O(1)
vector<int> secondSmallestAndLargestElement_1(vector<int> arr,int n)
{
    sort(arr.begin(),arr.end());
    vector<int> result;
    if(n<=1)
    {
        result.push_back(-1);
        return result;
    }
    result.push_back(arr[1]);
    result.push_back(arr[n-2]);
    return result;
}

//Better approach
//TC = O(n)
//SC = O(1)
vector<int> secondSmallestAndLargestElement_2(vector<int> arr,int n)
{
    vector<int> result;
    if(n<=1)
    {
        result.push_back(-1);
        return result;
    }
    int small=INT_MAX,second_small=INT_MAX;
    int large=INT_MIN,second_large=INT_MIN;
    for(int i=0;i<n;i++)
    {
        small=min(small,arr[i]);
        large=max(large,arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
            second_small=arr[i];
        if(arr[i]>second_large && arr[i]!=large)
            second_large=arr[i];
    }
    result.push_back(second_small);
    result.push_back(second_large);
    return result;
}

//Optimal Solution
//TC = O(n)
//SC = O(1)
vector<int> secondSmallestAndLargestElement_3(vector<int> arr,int n)
{
    vector<int> result;
    if(n<=1)
    {
        result.push_back(-1);
        return result;
    }
    int small = INT_MAX, second_small = INT_MAX;
    int large=INT_MIN,second_large=INT_MIN;
    for(int i = 0; i < n; i++) 
    {
       if(arr[i] < small)
       {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small)
       {
          second_small = arr[i];
       }

       if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    result.push_back(second_small);
    result.push_back(second_large);
    return result;
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> v;
    cout<<"Enter the element of array ;"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    if(n>1)
    {
        cout<<"Second Smallest Element and Second Largest Element in the Array is "<<secondSmallestAndLargestElement_1(v,n).at(0)<<" and "<<secondSmallestAndLargestElement_1(v,n).at(1)<<" respectively."<<endl;
        cout<<"Second Smallest Element and Second Largest Element in the Array is "<<secondSmallestAndLargestElement_2(v,n).at(0)<<" and "<<secondSmallestAndLargestElement_2(v,n).at(1)<<" respectively."<<endl;
        cout<<"Second Smallest Element and Second Largest Element in the Array is "<<secondSmallestAndLargestElement_3(v,n).at(0)<<" and "<<secondSmallestAndLargestElement_3(v,n).at(1)<<" respectively."<<endl;
    }
    else
    {
        cout<<secondSmallestAndLargestElement_1(v,n).at(0)<<" === "<<secondSmallestAndLargestElement_2(v,n).at(0)<<" === "<<secondSmallestAndLargestElement_3(v,n).at(0)<<endl;
    }
    return 0;
}