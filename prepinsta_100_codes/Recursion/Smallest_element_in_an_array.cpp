/*
In this method we will discuss the recursive solution to find the smallest element of an array. We will do the following steps to achieve the smallest element.

Create a recursive function say smallest_element(int n, int arr).
Base Condition : If(n==1) return arr[0].
Else, return min(arr[n-1], smallest_element(n-1, arr).
*/

#include <iostream>
#include <vector>

using namespace std;


int minElement(vector<int> arr,int n)
{
    if(n==1)
    {
        return arr[0];
    }
    return min(arr[n-1],minElement(arr,n-1));
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
    int max_element = minElement(arr,n);
    cout<<"Maximum element = "<<max_element<<endl;
    return 0;
}