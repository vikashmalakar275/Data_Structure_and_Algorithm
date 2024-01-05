/*
Problem Statement: You have been given a non-empty grid ‘mat’ with ‘n’ rows and ‘m’ columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index. If there’s no row with at least 1 zero, return -1.

Pre-requisite: Lower Bound implementation, Upper Bound implementation, & Find the first occurrence of a number.

Examples
Example 1:
Input Format: n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0
Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Example 2:
Input Format: n = 2, m = 2 , 
mat[] = 
0 0
0 0
Result: -1
Explanation:  The matrix does not contain any 1. So, -1 is the answer.
*/

#include <iostream>
using namespace std;

int max_numbers_of_ones_1(vector<vector<int> > &arr,int row,int column)
{
    int max_No_1s = 0;
    int result_row = -1;
    for(int i=0;i<row;i++)
    {
        int ones_count = 0; 
        for(int j=0;j<column;j++)
        {
            if(arr[i][j] == 1)
            {
                ones_count++;
            }
        }
        if(ones_count>max_No_1s)
        {
            max_No_1s = ones_count;
            result_row = i;
        }
    }
    return result_row;
}

int Lower_Bound(vector<int> arr,int n,int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid]>=target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int max_numbers_of_ones_2(vector<vector<int> > &arr,int row,int column)
{
    int max_No_1s = 0;
    int result_row = -1;
    for(int i=0;i<row;i++)
    {
        int ones_count = column - Lower_Bound(arr[i],column,1); 
        
        if(ones_count>max_No_1s)
        {
            max_No_1s = ones_count;
            result_row = i;
        }
    }
    return result_row;
}

int main()
{
    int n,m;
    cout<<"Enter the number of Row :"<<endl;
    cin>>n;
    cout<<"Enter the number of Column :"<<endl;
    cin>>m;
    vector<vector<int> > arr(n);
    cout<<"Enter the Value in Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i].resize(m);
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Maximum Number of 1's Present at Row index = "<<max_numbers_of_ones_1(arr,n,m)<<endl;
    cout<<"Maximum Number of 1's Present at Row index = "<<max_numbers_of_ones_2(arr,n,m)<<endl;
    return 0;
}