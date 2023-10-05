/*
Given a string S, the task is to write a program to print all permutations of a given string. 

A permutation also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered 
list S into a one-to-one correspondence with S itself. A string of length N has N! permutations. 
*/

#include <iostream>
#include <string>

using namespace std;

void permute(string& a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << endl;
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l + 1, r);
 
            // backtrack
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    string str;
    cout<<"Enter the string :"<<endl;
    getline(cin,str);
    cout<<"Permuation of string :"<<endl;
    permute(str,0,str.length() - 1);
    return 0;
}