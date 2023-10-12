/*
Binary Number Triangle Pattern
Problem Statement: Given an integer N, print the following pattern : 
1
01
101
0101
10101

Here, N = 5.

Examples:

Input Format: N = 3
Result: 
1
01
101

Input Format: N = 6
Result:   
1
01
101
0101
10101
010101
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    int binary = 1;
    for(int i=0;i<n;i++)
    {
        if(i%2==0) binary=1;
        else binary = 0;
        for(int j=0;j<=i;j++)
        {
            cout<<binary;
            binary = 1-binary;
        }
        cout<<"\n";
    }
    return 0;
}