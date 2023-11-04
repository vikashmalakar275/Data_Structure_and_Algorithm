/*
Problem Statement:
There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

Note: Start the array with positive elements.

Examples: 

Example 1:

Input:
arr[] = {1,2,-4,-5,3,4}, N = 6
Output:
1 -4 2 -5 3 4

Explanation: 

Positive elements = 1,2
Negative elements = -4,-5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
Leftover positive elements are 3 and 4 which are then placed at the end of the array.

Example 2:
Input:
arr[] = {1,2,-3,-1,-2,-3}, N = 6
Output:
1 -3 2 -1 3 -2
Explanation: 

Positive elements = 1,2
Negative elements = -3,-1,-2,-4
To maintain relative ordering, 1 must occur before 2.
Also, -3 should come before -1, and -1 should come before -2.
After alternate ordering, -2 and -4 are left, which would be placed at the end of the ans array.
*/

#include <iostream>
using namespace std;

//Brute Force Approach
//Time Complexity: O(2*N) { The worst case complexity is O(2*N) which is a combination of O(N) of traversing the array to segregate into neg and pos array and O(N) for adding the elements alternatively to the main array}.
//Explanation: The second O(N) is a combination of O(min(pos, neg)) + O(leftover elements). There can be two cases: when only positive or only negative elements are present, O(min(pos, neg)) + O(leftover) = O(0) + O(N), and when equal no. of positive and negative elements are present, O(min(pos, neg)) + O(leftover) = O(N/2) + O(0). So, from these two cases, we can say the worst-case time complexity is O(N) for the second part, and by adding the first part we get the total complexity of O(2*N).
//Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
vector<int> arrange_by_sign(vector<int> arr)
{
    int n = arr.size();
    vector<int> positive;
    vector<int> negative;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            positive.push_back(arr[i]);
        }
        else
        {
            negative.push_back(arr[i]);
        }
    }
    if(positive.size() < negative.size())
    {
        for(int i=0;i<positive.size();i++)
        {
            arr[2*i] = positive[i];
            arr[2*i+1] = negative[i];
        }
        int index = positive.size()*2;
        for(int i = positive.size();i<negative.size();i++)
        {
            arr[index] = negative[i];
            index++;
        }
    }
    else
    {
        for(int i=0;i<negative.size();i++)
        {
            arr[2*i] = positive[i];
            arr[2*i+1] = negative[i];
        }
        int index = negative.size()*2;
        for(int i = negative.size();i<positive.size();i++)
        {
            arr[index] = positive[i];
            index++;
        }
    }
    return arr;
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
    vector<int> ans1 = arrange_by_sign(arr);
    for(int i=0;i<ans1.size();i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
}