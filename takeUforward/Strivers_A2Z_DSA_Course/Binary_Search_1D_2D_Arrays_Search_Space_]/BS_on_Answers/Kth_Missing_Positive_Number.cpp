/*
Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer ‘k’. Find the ‘kth’ positive integer missing from ‘vec’.

Examples
Example 1:
Input Format: vec[]={4,7,9,10}, k = 1
Result: 1
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.
Example 2:
Input Format: vec[]={4,7,9,10}, k = 4
Result: 5
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.
*/
#include <iostream>
using namespace std;

int kth_missing_number_1(vector<int> arr,int k)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int k;
    cout<<"Enther the nth missing number :"<<endl;
    cin>>k;
    cout<<k<<"th Missing Number : "<<kth_missing_number_1(arr,k)<<endl;
    //cout<<"Least Capacity = "<<leastCapacity_1(arr,k)<<endl;
}