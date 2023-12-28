/*
Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer ‘k’. Find the ‘kth’ positive integer missing from ‘vec’.

Examples
Example 1:
Input Format: vec[]={4,7,9,10}, k = 1
Result: 1
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.
Example 2:
Input Format: vec[]={4,7,9,10}, k = 4
Result: 5
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.
*/
#include <iostream>
using namespace std;

//Time Complexity: O(N), N = size of the given array.
//Reason: We are using a loop that traverses the entire given array in the worst case.
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
int kth_missing_number_1(vector<int> arr,int k)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are using the simple binary search algorithm.
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
int kth_missing_number_2(vector<int> arr,int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int missing = arr[mid] - (mid+1);
        if(missing<k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low+k;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int k;
    cout<<"Enther the nth missing number :"<<endl;
    cin>>k;
    cout<<k<<"th Missing Number : "<<kth_missing_number_1(arr,k)<<endl;
    cout<<k<<"th Missing Number : "<<kth_missing_number_2(arr,k)<<endl;
}