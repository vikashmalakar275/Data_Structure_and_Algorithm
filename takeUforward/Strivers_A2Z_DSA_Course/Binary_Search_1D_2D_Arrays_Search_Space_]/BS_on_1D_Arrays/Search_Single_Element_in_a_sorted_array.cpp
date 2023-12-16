/*
Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

Pre-requisite: Binary Search Algorithm

Examples
Example 1:
Input Format: arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Result: 4
Explanation: Only the number 4 appears once in the array.

Example 2:

Input Format: arr[] = {1,1,3,5,5}
Result: 3
Explanation: Only the number 3 appears once in the array.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(N), N = size of the given array.
//Reason: We are traversing the entire array.
//Space Complexity: O(1) as we are not using any extra space.
int searchSingleElement_1(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if(i==0 && arr[i] != arr[i+1])
        {
            return arr[i];
        }
        else if(i==arr.size()-1 && arr[i] != arr[i-1])
        {
            return arr[i];
        }
        else if(arr[i] != arr[i+1] && arr[i] != arr[i-1])
        {
            return arr[i];
        }
    }
    return -1;
}

//Time Complexity: O(N), N = size of the given array.
//Reason: We are traversing the entire array.
//Space Complexity: O(1) as we are not using any extra space.
int searchSingleElement_2(vector<int> arr)
{
    int ans = 0;
    for(int i=0;i<arr.size();i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are basically using the Binary Search algorithm.
//Space Complexity: O(1) as we are not using any extra space.
int searchSingleElement_3(vector<int> arr)
{
    int n = arr.size();
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) 
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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
    cout <<"Single Element = "<<searchSingleElement_1(arr)<<endl;
    cout <<"Single Element = "<<searchSingleElement_2(arr)<<endl;
    cout <<"Single Element = "<<searchSingleElement_3(arr)<<endl;
}