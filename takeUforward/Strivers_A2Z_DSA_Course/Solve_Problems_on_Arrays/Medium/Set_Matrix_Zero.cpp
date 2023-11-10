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

//Brute Force Approach
//Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
//Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
//Another O(N*M) is taken to mark all the cells with -1 as 0 finally.
//Space Complexity: O(1) as we are not using any extra space.
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

//Better Approach
//Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
//Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.
//Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
//Reason: O(N) is for using the row array and O(M) is for using the col array.
vector<vector<int> > matrixZero_1(vector<vector<int> > arr,int n,int m)
{
    vector<int> row(n,0);
    vector<int> column(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == 0)
            {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i] || column[j])
            {
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}

//Optimal Approach
//Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
//Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.
//Space Complexity: O(1) as we are not using any extra space.
vector<vector<int> > matrixZero_2(vector<vector<int> > arr,int n,int m)
{
    int col0 = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == 0)
            {
                arr[i][0] = 0;
                if(j != 0)
                {
                    arr[0][j] = 0;
                }
                else
                {
                    col0 = 0;

                }
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j] != 0)
            {
                if(arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    if(arr[0][0] == 0)
    {
        for(int j = 0;j<m;j++)
        {
            arr[0][j] = 0;
        }
    }
    if(col0 == 0)
    {
        for(int i=0;i<n;i++)
        {
            arr[i][0] = 0;
        }
    }
    return arr;
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


    vector<vector<int> > ans = matrixZero_1(arr,n,m);
    cout<<"The Final Matrix is :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    vector<vector<int> > ans1 = matrixZero_2(arr,n,m);
    cout<<"The Final Matrix is :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans1[i][j]<<" ";
        }
        cout<<"\n";
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