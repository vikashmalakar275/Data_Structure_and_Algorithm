/*
Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Examples
Example 1:

Input: 
n = 4, arr1[] = [1 4 8 10] 
m = 5, arr2[] = [2 3 9]

Output: 
arr1[] = [1 2 3 4]
arr2[] = [8 9 10]

Explanation:
After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.

Example2:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]

Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]

Explanation:
After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.
*/

#include <iostream>
using namespace std;

//Brute Force Approach
vector<int> merge_array_1(vector<int> arr1, vector<int> arr2)
{
    vector<int> result;
    int left = 0, right = 0;
    while(left<arr1.size() && right<arr2.size())
    {
        if(arr1[left]<=arr2[right])
        {
            result.push_back(arr1[left]);
            left++;
        }
        else
        {
            result.push_back(arr2[right]);
            right++;
        }
    }

    while(left<arr1.size())
    {
        result.push_back(arr1[left]);
        left++;
    }

    while(right<arr2.size())
    {
        result.push_back(arr2[right]);
        right++;
    }

    return result;
}

int main()
{
    int n1,n2;
    cout<<"Enter size of first array :"<<endl;
    cin>>n1;
    vector<int> arr1;
    cout<<"Enter the elements of First Array :"<<endl;
    for(int i=0;i<n1;i++)
    {
        int a;
        cin>>a;
        arr1.push_back(a);
    }
    cout<<"Enter size of Second array :"<<endl;
    cin>>n2;
    vector<int> arr2;
    cout<<"Enter the elements of First Array :"<<endl;
    for(int i=0;i<n2;i++)
    {
        int b;
        cin>>b;
        arr2.push_back(b);
    }

    vector<int> ans = merge_array_1(arr1,arr2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}