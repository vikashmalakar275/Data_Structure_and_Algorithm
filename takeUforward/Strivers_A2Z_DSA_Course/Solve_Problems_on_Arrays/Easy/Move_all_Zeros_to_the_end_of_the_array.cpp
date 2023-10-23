/*
Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Examples
Example 1:
Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Example 2:
Input: 1,2,0,1,0,4,0
Output: 1,2,1,4,0,0,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
*/

#include <iostream>
using namespace std;

vector<int> moveAllZeroToLast(vector<int> &arr)
{
    vector<int> temp;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++)
    {
        arr[i] = temp[i];
    }
    for(int i=temp.size();i<arr.size();i++)
    {
        arr[i] = 0;
    }
    return arr;
}

vector<int> moveAllZeros(int n, vector<int> a) {
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return a;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    moveAllZeroToLast(arr);
    cout<<"Output :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    vector<int> ans = moveAllZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout<<endl;
    return 0;
}