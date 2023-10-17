/*
Problem Statement: Given an array of N integers, write a program to implement the Recursive Insertion Sort algorithm.

Examples:

Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting we get 9,13,20,24,46,52

Example 2:
Input: N = 5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting we get 1,2,3,4,5
*/

#include <iostream>
using namespace std;

void recursiveInsertionSort(vector<int> &arr,int i,int n)
{
    if(i==n)
    {
        return;
    }
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) 
    {
        swap(arr[j],arr[j-1]);
        j--;
    }

    recursiveInsertionSort(arr,i+1,n);
}

int main()
{
    int n;
    cout<<"Enter the size of Array :"<<endl;
    cin>>n;
    vector<int> v;
    cout<<"Enter the element of aaray :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    recursiveInsertionSort(v,0,n);
    cout<<"Element after recursice bubble sort sort:\n";
    for (int i = 0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}