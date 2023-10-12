/*
Problem Statement: Given an integer N, print the following pattern : 
A
A B
A B C
A B C D
A B C D E

Here, N = 5.

Examples:

Input Format: N = 3
Result: 
A
A B
A B C

Input Format: N = 6
Result:   
A
A B
A B C
A B C D
A B C D E
A B C D E F
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char ch = 'A';
        for(int j=0;j<=i;j++)
        {
            cout<<ch++<<" ";
        }
        cout<<"\n";
    }
    return 0;
}