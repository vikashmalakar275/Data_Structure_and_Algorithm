/*
Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

Examples
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Output: [0]
*/

#include <iostream>
using namespace std;

//Brute force approach
//Time Complexity: O(N*logN)
//Space Complexity: O(1)

void sort_array_012_1(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    cout<<"Array after soritng :"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Better Approach
//Time Complexity: O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.
//Space Complexity: O(1) as we are not using any extra space.
void sort_array_012_2(vector<int> arr)
{
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    for(int i=0;i<arr.size();i++)
    {
        switch (arr[i])
        {
        case 0:
        count_0++;
        break;

        case 1:
        count_1++;
        break;

        case 2:
        count_2++;
        break;
        }
    }
    for(int i=0;i<count_0;i++)
    {
        arr[i] = 0;
    }
    for(int i=count_0;i<count_1;i++)
    {
        arr[i] = 0;
    }
    for(int i=count_1;i<count_2;i++)
    {
        arr[i] = 0;
    }

    cout<<"Array after soritng :"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//Optimal Approach = Dutch National flag algorithm
//Time Complexity: O(N), where N = size of the given array.
//Reason: We are using a single loop that can run at most N times.
//Space Complexity: O(1) as we are not using any extra space.
void sortArray(vector<int> arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of aaray :"<<endl;
    cin>>n;
    vector<int>  arr;
    cout<<"Enter the element of array ;"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
}