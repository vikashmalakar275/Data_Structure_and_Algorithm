/*
Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if ‘arr[i]’ is the peak element, ‘arr[i – 1]’ < ‘arr[i]’ and ‘arr[i + 1]’ < ‘arr[i]’. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.

Pre-requisite: Binary Search Algorithm

Examples
Example 1:
Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
Result: 7
Explanation: In this example, there is only 1 peak that is at index 7.

Example 2:
Input Format: arr[] = {1,2,1,3,5,6,4}
Result: 1
Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.

Example 3:
Input Format: arr[] = {1, 2, 3, 4, 5}
Result: 4
Explanation: In this example, there is only 1 peak that is at the index 4.

Example 4:
Input Format: arr[] = {5, 4, 3, 2, 1}
Result: 0
Explanation: In this example, there is only 1 peak that is at the index 0.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(N), N = size of the given array.
//Reason: We are traversing the entire array.
//Space Complexity: O(1) as we are not using any extra space.
int peakElement_1(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if((i==0 || arr[i]>arr[i-1]) && (i==arr.size()-1 || arr[i]>arr[i+1]))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    cout<<"Enter the Element in Array :"<<endl;
    vector<int> arr;
    for(int i =0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Peak Element is at index = "<<peakElement_1(arr)<<endl;
    return 0;
}