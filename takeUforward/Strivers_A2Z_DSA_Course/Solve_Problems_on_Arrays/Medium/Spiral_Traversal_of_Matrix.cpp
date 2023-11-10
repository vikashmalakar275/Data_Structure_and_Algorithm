/*
Problem Statement: Given a Matrix, print the given matrix in spiral order.

Examples:

Example 1:
Input: Matrix[][] = { { 1, 2, 3, 4 },
		      { 5, 6, 7, 8 },
		      { 9, 10, 11, 12 },
	              { 13, 14, 15, 16 } }

Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Example 2:
Input: Matrix[][] = { { 1, 2, 3 },
	              { 4, 5, 6 },
		      { 7, 8, 9 } }
			    
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.
*/

#include <iostream>
using namespace std;

void spiralTraversalMatrix(vector<vector<int> > arr,int n,int m)
{
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n - 1;
    vector<int> ans;
    while(left<=right && top<=bottom)
    {
        for(int i=left;i<=right;i++)
        {
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom)
        {
            for(int i=right;i>=0;i--)
            {
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }

    cout<<"Result after Spiral Traversal of Matrix :"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
    spiralTraversalMatrix(arr,n,m);

}