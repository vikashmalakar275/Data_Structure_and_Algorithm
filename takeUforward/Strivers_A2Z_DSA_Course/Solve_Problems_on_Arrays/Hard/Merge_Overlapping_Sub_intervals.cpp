/*
Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

Examples
Example 1:
Example 1: 

Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
 intervals.

Example 2:

Input: [[1,4],[4,5]]

Output: [[1,5]]

Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].
*/

#include <iostream>
using namespace std;

vector

int main()
{
    int row,column;
    cout<<"Enter size of row :"<<endl;
    cin>>row;
    cout<<"Enter size of column :"<<endl;
    cin>>column;
    vector<vector<int>> arr(row,vector<int>(column));
    cout<<"Enter the elements of Array :"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin>>arr[i][j];
        }
    }

    return 0;
}