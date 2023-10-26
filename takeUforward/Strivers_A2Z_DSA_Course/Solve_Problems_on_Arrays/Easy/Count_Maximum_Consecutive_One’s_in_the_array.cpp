/*
Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

Examples:

Example 1:

Input: prices = {1, 1, 0, 1, 1, 1}

Output: 3

Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Input: prices = {1, 0, 1, 1, 0, 1} 

Output: 2

Explanation: There are two consecutive 1's in the array. 
*/
#include <iostream>
using namespace std;

int countMaximumConsecutiveOne(vector<int> arr)
{
    int count = 0;
    int maxCount = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==1)
        {
            count++;
            if(count>maxCount)
            {
                maxCount = count;
            }
        }
        else
        {
            count = 0;
        }
    }
    return maxCount;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array:"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the Element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Maximum Consecutive One's = "<<countMaximumConsecutiveOne(arr)<<endl;
}