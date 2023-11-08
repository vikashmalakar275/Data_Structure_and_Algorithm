/*
Set Matrix Zero
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

Examples
Examples 1:

Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]

Output: [[1,0,1],[0,0,0],[1,0,1]]

Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.
 
Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0.
*/


#include <iostream>
using namespace std;


void makeRowZero(vector<vector<int> > &arr,int n,int m,int i)
{
    for(int j=0;j<m;j++)
    {
        if(arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}
void makeColumnZero(vector<vector<int> > &arr,int n,int m,int j)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

void matrixZero(vector<vector<int> > &arr,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == 0)
            {
                makeRowZero(arr,n,m,i);
                makeColumnZero(arr,n,m,j);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n,m;
    cout<<"Enter the Row :"<<endl;
    cin>>n;
    cout<<"Enter the Column :"<<endl;
    cin>>m;
    vector<vector<int> > arr(n);
    cout<<"Enter the value of Array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for (int j = 0; j < m; j++) 
        {
            cin >> arr[i][j];
        }
    }
    matrixZero(arr,n,m);
    cout<<"The Final Matrix is :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}