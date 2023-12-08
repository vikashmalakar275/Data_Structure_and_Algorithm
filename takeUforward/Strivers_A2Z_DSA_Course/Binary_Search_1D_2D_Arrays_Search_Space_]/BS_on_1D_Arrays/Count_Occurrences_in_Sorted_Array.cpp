/*
Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Examples
Example 1:
Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
Explanation: 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
Explanation: 2 is occurring 5 times in the given array so it is our answer.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(n) 
//Space Complexity: O(1) not considering the given array
int count_occurence_1(vector<int> arr, int x)
{
    int count = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == x)
        {
            count++;
        }
    }
    return count;
}

//Time Complexity: O(2*logN), where N = size of the given array.
//Reason: We are basically using the binary search algorithm twice.
//Space Complexity: O(1) as we are using no extra space.
int first_occurence(vector<int> arr, int x)
{
    int first = -1;
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid]<x) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return first;
}
int last_occurence(vector<int> arr, int x)
{
    int last = -1;
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid]<x) 
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}
int count_occurence_2(vector<int> arr, int x)
{
    int first = first_occurence(arr,x);
    int last = last_occurence(arr,x);
    if(first == -1)
    {
        return 0;
    }
    return last - first + 1; 
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
    int search;
    cout<<"Enter the searched element :"<<endl;
    cin>>search;
    cout <<"Total occurrence of "<<search<<" is = "<<count_occurence_1(arr,search)<<endl;
    cout <<"Total occurrence of "<<search<<" is = "<<count_occurence_2(arr,search)<<endl;
}