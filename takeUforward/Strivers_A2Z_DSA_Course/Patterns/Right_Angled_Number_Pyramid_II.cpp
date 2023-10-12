/*
Problem Statement: Given an integer N, print the following pattern : 
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

Here, N = 5.

Examples:

Input Format: N = 3
Result: 
1
2 2 
3 3 3

Input Format: N = 6
Result:
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
6 6 6 6 6 6
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}