/*
Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

Examples
Example 1:
Input:
 arr = [4, 7, 1, 0]
Output:
 7 1 0
Explanation:
 Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]
Output:
 22 12 6
Explanation:
 6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.
*/
#include <iostream>
using namespace std;

//Brute force approach
//Time Complexity = O(n2)
//Space Complexity = O(n)
vector<int> leaders_in_array_1(vector<int> arr)
{
    vector<int> result;
    for(int i=0;i<arr.size();i++)
    {
        int isLeader = true;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]<arr[j])
            {
                isLeader = false;
                break;
            }
        }
        if(isLeader)
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}

//Optimal Solution
//Time Complexity = O(n2)
//Space Complexity = O(n)
vector<int> leaders_in_array_2(vector<int> arr)
{
    int n = arr.size();
    vector<int> result;
    int max = arr[n - 1];
    result.push_back(arr[n-1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max) 
        {
            result.push_back(arr[i]);
            max = arr[i];
        }
    }
    return result;
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<int> ans1 = leaders_in_array_1(arr);
    cout<<"Leaders in array are ";
    for(int i=0;i<ans1.size();i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    vector<int> ans2 = leaders_in_array_2(arr);
    cout<<"Leaders in array are ";
    for(int i=ans2.size()-1;i>=0;i--)
    {
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
}