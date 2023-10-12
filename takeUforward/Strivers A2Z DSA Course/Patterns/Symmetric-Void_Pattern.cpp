/*
Problem Statement: Given an integer N, print the following pattern : 
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********

Here, N = 5.

Examples:

Input Format: N = 3
Result: 
******
**  **
*    *
*    *
**  **
******

Input Format: N = 6
Result:   
************
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
************
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    int iniS = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<iniS;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }
        iniS+=2;
        cout<<endl;
    }
    iniS = 2*n -2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<iniS;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        iniS-=2;
        cout<<endl;
    }
    return 0;
}