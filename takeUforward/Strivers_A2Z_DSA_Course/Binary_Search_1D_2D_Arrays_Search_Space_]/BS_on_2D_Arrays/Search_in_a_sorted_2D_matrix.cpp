/*
Problem Statement: You have been given a 2-D array ‘mat’ of size ‘N x M’ where ‘N’ and ‘M’ denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given ‘mat’ or not.

Examples
Example 1:
Input Format: N = 3, M = 4, target = 8,
mat[] = 
1 2 3 4
5 6 7 8 
9 10 11 12
Result: true
Explanation: The ‘target’  = 8 exists in the 'mat' at index (1, 3).

Example 2:
Input Format: N = 3, M = 3, target = 78,
mat[] = 
1 2 4
6 7 8 
9 10 34
Result: false
Explanation: The ‘target' = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(N X M), where N = given row number, M = given column number.
//Reason: In order to traverse the matrix, we are using nested loops running for n and m times respectively.
//Space Complexity: O(1) as we are not using any extra space.
pair<int,int> search_in_2D_sorted_1(vector<vector<int> > &arr,int row,int column,int target)
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

//Time Complexity: O(N + logM), where N = given row number, M = given column number.
//Reason: We are traversing all rows and it takes O(N) time complexity. But for all rows, we are not applying binary search rather we are only applying it once for a particular row. That is why the time complexity is O(N + logM) instead of O(N*logM).
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
pair<int,int> search_in_2D_sorted_2(vector<vector<int> > &arr,int row,int column,int target)
{
    for(int i=0;i<row;i++)
    {
        if(arr[i][0]<=target && target <=arr[i][column-1])
        {
            return make_pair(i,binary_search(arr[i],target));
        }
    }
    return make_pair(-1,-1);
}

//Time Complexity: O(log(NxM)), where N = given row number, M = given column number.
//Reason: We are applying binary search on the imaginary 1D array of size NxM.
//Space Complexity: O(1) as we are not using any extra space.
pair<int,int> search_in_2D_sorted_3(vector<vector<int> > &arr,int row,int column,int target)
{
    int low = 0, high = row * column - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        int row = mid / column, col = mid % column;
        if (arr[row][col] == target)
        {
            return make_pair(row,col);
        }
        else if (arr[row][col] < target) low = mid + 1;
        else high = mid - 1;
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
    pair<int,int> ans = search_in_2D_sorted_1(arr,n,m,target);
    cout<<"Target = "<<target<<" found at index = ("<<ans.first<<" , "<<ans.second<<")"<<endl;
    pair<int,int> ans1 = search_in_2D_sorted_2(arr,n,m,target);
    cout<<"Target = "<<target<<" found at index = ("<<ans1.first<<" , "<<ans1.second<<")"<<endl;
    pair<int,int> ans2 = search_in_2D_sorted_3(arr,n,m,target);
    cout<<"Target = "<<target<<" found at index = ("<<ans2.first<<" , "<<ans2.second<<")"<<endl;
    return 0;
}