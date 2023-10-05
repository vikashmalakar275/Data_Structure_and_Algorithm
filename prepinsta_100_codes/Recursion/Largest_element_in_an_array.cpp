/*
Largest Element of  the array using Recursion in C++
Here, in this page we will discuss the program to find the largest element of the array using recursion in C++ programming language. We are given with an array and we need to print the largest element among the elements of the array.

Example :

Input : arr[6] = {13, 89, 76, 43, 7, 90}
Output : Largest Element is 90
We will discuss both approaches to find largest element using recursion and iteratively.
*/

#include <iostream>
#include <vector>

using namespace std;


int maxElement(vector<int> arr,int n)
{
    if(n==1)
    {
        return arr[0];
    }
    return max(arr[n-1],maxElement(arr,n-1));
}
int main()
{
    int n;
    cout<<"enter the size of array :"<<endl;
    cin>>n;
    cout<<"Enter the element of array :"<<endl;
    int a;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    int max_element = maxElement(arr,n);
    cout<<"Maximum element = "<<max_element<<endl;
    return 0;
}