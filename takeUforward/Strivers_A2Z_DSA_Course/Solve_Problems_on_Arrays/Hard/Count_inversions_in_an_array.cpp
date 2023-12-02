/*
Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Examples
Example 1:
Input Format: N = 5, array[] = {1,2,3,4,5}
Result: 0
Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.

Example 2:
Input Format: N = 5, array[] = {5,4,3,2,1}
Result: 10
Explanation: we have a reverse sorted array and we will get the maximum inversions as for i < j we will always find a pair such that A[j] < A[i]. Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will satisfy out conditions and for reverse sorted array we will get maximum inversions and that is (n)*(n-1) / 2.For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

Example 3:
Input Format: N = 5, array[] = {5,3,2,1,4}
Result: 7
Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition. 
*/

#include <iostream>
using namespace std;

//Brute Force approach
//Time Complexity: O(N2), where N = size of the given array.
//Reason: We are using nested loops here and those two loops roughly run for N times.
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
int count_inversions(vector<int> array)
{
    int count = 0;
    for(int i=0;i<array.size();i++)
    {
        for(int j=i+1;j<array.size();j++)
        {
            if(array[j]<array[i])
            {
                count++;
            }
        }
    }
    return count;
}

//Optimal solution (using merge sort concept)
//Time Complexity: O(N*logN), where N = size of the given array.
//Reason: We are not changing the merge sort algorithm except by adding a variable to it. So, the time complexity is as same as the merge sort.
//Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
int merge(vector<int> &arr,int low,int mid,int high)
{
    vector<int> tempArray;
    int left = low;
    int right = mid + 1;

    int cnt = 0;

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
            cnt += (mid - left + 1);
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

    return cnt;
}

int mergeSort(vector<int> &arr,int low,int high)
{
    int cnt = 0;
    if(low>=high)
    {
        return cnt;
    }
    int mid = (low + high)/2; 
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}

int count_inversions_2(vector<int> &array)
{
    return mergeSort(array,0,array.size()-1);
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout<<"Toatl Inversion = "<<count_inversions(arr)<<endl;
    cout<<"Toatl Inversion = "<<count_inversions_2(arr)<<endl;
    return 0;
}