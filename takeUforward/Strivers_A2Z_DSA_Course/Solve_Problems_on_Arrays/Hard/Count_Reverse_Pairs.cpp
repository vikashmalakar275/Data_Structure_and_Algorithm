/*
Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

Examples
Example 1:

Input: N = 5, array[] = {1,3,2,3,1)

Output: 2 

Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

Example 2:

Input: N = 4, array[] = {3,2,1,4}

Output: 1

Explaination: There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]
*/

#include <iostream>
using namespace std;


//Brute force approach
//Time Complexity: O(N2), where N = size of the given array.
//Reason: We are using nested loops here and those two loops roughly run for N times.
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
int count_reverse_pair(vector<int> array)
{
    int count = 0;
    for(int i=0;i<array.size();i++)
    {
        for(int j=i+1;j<array.size();j++)
        {
            if(array[i]>2*array[j])
            {
                count++;
            }
        }
    }
    return count;
}

//Optimal Approach
//Time Complexity: O(2N*logN), where N = size of the given array.
//Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).
//Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
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

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for(int i = low;i <= mid; i++)
    {
        while(right <= high && arr[i]>2*arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
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
    cnt += countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}

int count_reverse_pair_2(vector<int>  arr)
{
    return mergeSort(arr,0,arr.size()-1);
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

    cout<<"Toatl Inversion = "<<count_reverse_pair(arr)<<endl;
    cout<<"Toatl Inversion = "<<count_reverse_pair_2(arr)<<endl;
    return 0;
}