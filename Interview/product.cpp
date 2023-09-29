/*
Given an array that contains both positive and negative integers, find the product of the 
maximum product subarray. TC=O(n) SC=O(1)

Examples:                                                                                                                                                                                      
Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60  // The subarray is {60}

Input: arr[] = {-1, -3, -10, 0, 0}
Output:   30  // The subarray is {-3, -10}
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the size and element :"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int min = arr[0];
    int product = 1;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        int index = i;
        product *= arr[index];
        if(product>min)
        {
            min = product;
        }
        if(i== (n-1))
        {
            flag = true;
        }
    }
    cout<<"maximum product = "<<min<<endl;
    return 0;
}