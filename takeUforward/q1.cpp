/*
0 1 2 3
1 2 3 4 0
4 5 6 5 1
7 8 9 6 2
4 5 6 1 3
*/
// 4 = 0 3
// 6 = 1 2
// 8 = 2 1
// 4 = 3 0

// 1 2 3 4 
// 5 6 7 8 
// 9 10 11 12 
// 13 14 15 16

// 1+6+11+16
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n][n];
    cout<<"Enter the element :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    //input
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                sum1 += arr[i][j];
            }
        }
    }
   // cout<<sum1<<endl;
    int k = 0,l=n-1;
    while(k<n)
    {
        sum2 += arr[k][l];
       // cout<<sum2<<endl;
        k++;
        l--;
    }
   // cout<<sum2<<endl;
    int result = sum1 + sum2;
    if(n%2 != 0)
    {
        result = result - arr[n/2][n/2];
    }
    cout<<result<<endl;
}