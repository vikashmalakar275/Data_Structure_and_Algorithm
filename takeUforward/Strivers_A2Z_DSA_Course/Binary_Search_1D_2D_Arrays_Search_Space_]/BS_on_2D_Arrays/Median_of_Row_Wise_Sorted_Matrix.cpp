/*
Problem Statement: Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns, find the median in the given matrix.

Assume – r*c is odd

Examples:

Example 1:
Input: 
r = 3 , c = 3
1 4 9 
2 5 6
3 8 7
Output: Median = 5
Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9
So, median = 5

Example 2:
Input: 
r = 3 , c = 3
1 3 8
2 3 4
1 2 5
Output: Median = 3
Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8
So, median = 3
*/
#include <iostream>
using namespace std;

int median_1(vector<vector<int> > &arr)
{
    vector<int> arr1;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            arr1.push_back(arr[i][j]);
        }
    }
    sort(arr1.begin(),arr1.end());
    return arr1[arr1.size()/2];
}

// int median_2(vector<vector<int> > &arr)
// {
    
// }

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
    cout<<"Median = "<<median_1(arr)<<endl;
    //cout<<"Median = "<<median_2(arr)<<endl;
    return 0;
}