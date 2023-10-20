/*
Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

Examples:

Example 1:
Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
Output: 6 7 1 2 3 4 5
Explanation: array is rotated to right by 2 position .

Example 2:
Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left 
Output: 9 10 11 3 7 8
Explanation: Array is rotated to right by 3 position.
*/

#include <iostream>
using namespace std;

void rotatearray(vector<int> &arr)
{
    
}

void rotate_array_2(vector<int> arr, int n) {
  
}


int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array ;"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Array after one left rotate :"<<endl;
    rotate_array_2(arr,n);
    cout<<endl;
    otatearray(arr);
    cout<<"Array after one left rotate :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}