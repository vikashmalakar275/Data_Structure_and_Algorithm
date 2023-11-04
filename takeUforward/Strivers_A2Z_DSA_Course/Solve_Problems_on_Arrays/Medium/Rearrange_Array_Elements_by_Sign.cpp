/*
Variety-1

Problem Statement:

There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

Note: Start the array with positive elements.

Examples: 

Example 1:

Input:
arr[] = {1,2,-4,-5}, N = 4
Output:
1 -4 2 -5

Explanation: 

Positive elements = 1,2
Negative elements = -4,-5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.

Example 2:
Input:
arr[] = {1,2,-3,-1,-2,3}, N = 6
Output:
1 -3 2 -1 3 -2
Explanation: 

Positive elements = 1,2,3
Negative elements = -3,-1,-2
To maintain relative ordering, 1 must occur before 2, and 2 must occur before 3.
Also, -3 should come before -1, and -1 should come before -2.
*/
#include <iostream>
using namespace std;

//Brute Force Approach
//Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.
//Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
vector<int> arrange_by_sign_1(vector<int> arr)
{
    vector<int> positive;
    vector<int> negative;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>=0)
        {
            positive.push_back(arr[i]);
        }
        else
        {
            negative.push_back(arr[i]);
        }
    }
    for(int i=0;i<arr.size()/2;i++)
    {
        arr[2*i] = positive[i];
        arr[2*i + 1] = negative[i];
    }
    return arr;
}

//Optimal Solution
//Time Complexity: O(N) { O(N) for traversing the array once and substituting positives and negatives simultaneously using pointers, where N = size of the array A}.
//Space Complexity:  O(N) { Extra Space used to store the rearranged elements separately in an array, where N = size of array A}.
vector<int>  arrange_by_sign_2(vector<int> arr)
{
    vector<int> ans(arr.size(),0);
    int posIndex = 0, negIndex = 1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<0)
        {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of aaray :"<<endl;
    cin>>n;
    vector<int>  arr;
    cout<<"Enter the element of array ;"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<int> ans1 = arrange_by_sign_1(arr);
    vector<int> ans2 = arrange_by_sign_2(arr);
    for(int i=0;i<ans1.size();i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ans2.size();i++)
    {
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
}