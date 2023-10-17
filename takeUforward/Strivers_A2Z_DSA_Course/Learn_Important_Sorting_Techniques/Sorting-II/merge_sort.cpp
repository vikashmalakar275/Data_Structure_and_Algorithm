/*
Problem:  Given an array of size n, sort the array using Merge Sort.

Examples:

Example 1:
Input: N=5, arr[]={4,2,1,6,7}
Output: 1,2,4,6,7,


Example 2:
Input: N=7,arr[]={3,2,8,5,1,4,23}
Output: 1,2,3,4,5,8,23
*/
#include <iostream>
using namespace std;


//TC = O(n*log n)
//SC = O(n)
void merge(vector<int> &arr,int low,int mid,int high)
{
    vector<int> tempArray;
    int left = low;
    int right = mid + 1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            tempArray.push_back(arr[left]);
            left++;
        }
        else
        {
            tempArray.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        tempArray.push_back(arr[left]);
            left++;
    }
    while(right<=high)
    {
        tempArray.push_back(arr[right]);
        right++;
    }
    for(int i = low;i<=high;i++)
    {
        arr[i] = tempArray[i - low];
    }
}

void mergeSort(vector<int> &arr,int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int mid = (low + high)/2; 
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
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
    cout<<endl;
    mergeSort(v,0,n-1);
    cout<<"Element after merger sort:\n";
    for (int i = 0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}