/*
Problem Statement: Given an array, we have to find the largest element in the array.

Examples
Example 1:
Input: arr[] = {2,5,1,3,0};
Output: 5
Explanation: 5 is the largest element in the array. 

Example2: 
Input: arr[] = {8,10,5,7,9};
Output: 10
Explanation: 10 is the largest element in the array. 
*/

#include <iostream>
#include <algorithm>
using namespace std;

//Brute Force Approach
//TC = O(N*log(N))
//SC = O(n)
int maxElement_1(vector<int> arr,int n)
{
    sort(arr.begin(),arr.end());
    return arr[n-1];

}

//Recursive Approach
//TC = O(n)
//SC = O(1)
int maxElement_2(vector<int> arr,int n)
{
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
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
    cout<<"Largest Element in the Array is "<<maxElement_1(v,n)<<endl;
    cout<<"Largest Element in the Array is "<<maxElement_2(v,n)<<endl;
    return 0;
}