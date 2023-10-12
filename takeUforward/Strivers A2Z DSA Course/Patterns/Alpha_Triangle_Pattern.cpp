/*
Problem Statement: Given an integer N, print the following pattern : 
E 
D E 
C D E 
B C D E 
A B C D E 

Here, N = 5.

Examples:

Input Format: N = 3
Result: 
C
B C
A B C

Input Format: N = 6
Result:   
F
E F
D E F
C D E F
B C D E F
A B C D E F
*/


#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    int num = n;
    for(int i=0;i<n;i++)
    {
        char ch = 'A'+num-1;
        char ch1 = ch;
        for(int j=0;j<=i;j++)
        {
            cout<<ch1++<<" ";
        }
        num--;
        cout<<"\n";
    }
    return 0;
}