/*
Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Examples
Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.

Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.
*/
#include <iostream>
using namespace std;

//Brite Force Approach
//TC = O(n)
//SC = O(1)
int find_number_appears_once_1(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        int count = 0;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count==1)
        {
            return arr[i];
        }
    }
    return -1;
}



int main()
{
    int n;
    cout<<"Enter the Size of Array:"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the Element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int result = find_number_appears_once_1(arr);
    if(result > 0)
    {
        cout<<"Number that appears once = "<<result<<endl;
    }
    else
    {
        cout<<"No Number appear Once."<<endl;
    }
}