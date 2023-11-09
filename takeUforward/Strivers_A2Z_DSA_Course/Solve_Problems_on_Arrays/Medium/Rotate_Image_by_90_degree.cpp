/*
Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
Examples
Example 1:

Input: [[1,2,3],
        [4,5,6],
        [7,8,9]]

Output: [[7,4,1],
         [8,5,2],
         [9,6,3]]

Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

Example 2:

Input: [[5,1,9,11],
        [2,4,8,10],
        [13,3,6,7],
        [15,14,12,16]]

Output:[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix
*/
#include<iostream>
using namespace std;

vector<vector<int> > rotateImageBy90Degree_clockwise(vector<vector<int> > &arr)
{
    int n = arr.size();
    vector< vector<int> > rotated_arr(n, vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            rotated_arr[j][n-i-1] = arr[i][j];
        }
    }
    return rotated_arr;
}

int main()
{
    int n;
    cout<<"Enter the size of n X n matrix :"<<endl;
    cin>>n;
    vector<vector<int> > arr(n);
    cout<<"Enter the value of Array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(n);
        for (int j = 0; j < n; j++) 
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int> > clockwise_rotated_array_1 = rotateImageBy90Degree_clockwise(arr);
    cout<<"Array after 90-degree clockwise rotation:"<<endl;
    for(int i=0;i<clockwise_rotated_array_1.size();i++)
    {
        for(int j=0;j<clockwise_rotated_array_1.size();j++)
        {
            cout<<clockwise_rotated_array_1[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
}