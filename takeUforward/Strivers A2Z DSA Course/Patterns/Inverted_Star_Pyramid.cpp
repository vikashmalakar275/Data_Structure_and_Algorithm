/*
Problem Statement: Given an integer N, print the following pattern : 
 *********
  *******
   ***** 
    ***    
     *

Here, N = 5.

Examples:

Input Format: N = 3
Result: 
*****  
 ***
  *   
Input Format: N = 6
Result:     
***********
 *********
  *******
   ***** 
    ***    
     *
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
        for(int j=0;j< 2*n -(2*i +1);j++)
        {
            
            cout<<"*";
        }
        cout << endl;
    }
    return 0;
}