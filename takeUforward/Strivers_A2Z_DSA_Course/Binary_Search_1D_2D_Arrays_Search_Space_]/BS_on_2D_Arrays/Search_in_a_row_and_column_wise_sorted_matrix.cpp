/*
Problem Statement: You have been given a 2-D array ‘mat’ of size ‘N x M’ where ‘N’ and ‘M’ denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order.
But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
You are given an integer ‘target’, and your task is to find if it exists in the given ‘mat’ or not.

Pre-requisite: Search in a 2D sorted matrix

Examples
Example 1:
Input Format: N = 5, M = 5, target = 14
mat[] = 
{
    {1, 4, 7, 11, 15}
    {2, 5, 8, 12, 19}
    {3, 6, 9, 16, 22}
    {10, 13, 14, 17, 24}
    {18, 21, 23, 26, 30}
}

Result: true
Explanation: Target 14 is present in the cell (3, 2)(0-based indexing) of the matrix. So, the answer is true.

Example 2:
Input Format: N = 3, M = 3, target = 12,
mat[] = 
{
    {1, 3, 7}
    {6, 13, 15}
    {14, 20, 21}
}

Result: false
Explanation: As target 12 is not present in the matrix, the answer is false.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(N X M), where N = given row number, M = given column number.
//Reason: In order to traverse the matrix, we are using nested loops running for n and m times respectively.
//Space Complexity: O(1) as we are not using any extra space.
pair<int,int> search_in_row_column_wise_1(vector<vector<int> > &arr,int row,int column,int target)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(arr[i][j] == target)
            {
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

//Time Complexity: O(N*logM), where N = given row number, M = given column number.
//Reason: We are traversing all rows and it takes O(N) time complexity. And for all rows, we are applying binary search. So, the total time complexity is O(N*logM).
//Space Complexity: O(1) as we are not using any extra space.
int binary_search(vector<int> arr,int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid]>target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
pair<int,int> search_in_row_column_wise_2(vector<vector<int> > &arr,int row,int column,int target)
{
    for(int i=0;i<row;i++)
    {
        int ind = binary_search(arr[i],target);
        if(ind != -1)
        {
            return make_pair(i,ind);
        }
    }
    return make_pair(-1,-1);
}

//Time Complexity: O(N+M), where N = given row number, M = given column number.
//Reason: We are starting traversal from (0, M-1), and at most, we can end up being in the cell (M-1, 0). So, the total distance can be at most (N+M). So, the time complexity is O(N+M).
//Space Complexity: O(1) as we are not using any extra space.
pair<int,int> search_in_row_column_wise_3(vector<vector<int> > &arr,int n,int m,int target)
{
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (arr[row][col] == target)
        {
            return make_pair(row,col);
        }
        else if (arr[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return make_pair(-1,-1);
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
    cout<<"Enter the element which you want to search :"<<endl;
    int target;
    cin>>target;
    pair<int,int> ans = search_in_row_column_wise_1(arr,n,m,target);
    cout<<"Target = "<<target<<" found at index = ("<<ans.first<<" , "<<ans.second<<")"<<endl;
    pair<int,int> ans1 = search_in_row_column_wise_2(arr,n,m,target);
    cout<<"Target = "<<target<<" found at index = ("<<ans1.first<<" , "<<ans1.second<<")"<<endl;
    pair<int,int> ans2 = search_in_row_column_wise_3(arr,n,m,target);
    cout<<"Target = "<<target<<" found at index = ("<<ans2.first<<" , "<<ans2.second<<")"<<endl;
    return 0;
}