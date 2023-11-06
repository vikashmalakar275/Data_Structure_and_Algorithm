/*
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

Examples
Example 1 :

Input format: Arr[] = {1,3,2}
Output: Arr[] = {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
Example 2:

Input format: Arr[] = {3,2,1}
Output: Arr[] = {1,2,3}
Explanation: As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the topmost permutation.
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//own Function
//Time Complexity: O(3N), where N = size of the given array
//Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each, where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(3N).
//Space Complexity: Since no extra storage is required. Thus, its space complexity is O(1).
vector<int> nextGreaterPermutation(vector<int> &arr) 
{
    int n = arr.size();
    int ind = -1;
    for (int i = n - 2; i >= 0; i--) 
    {
        if (arr[i] < arr[i + 1]) 
        {
            ind = i;
            break;
        }
    }
    if (ind == -1) 
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for (int i = n - 1; i > ind; i--) 
    {
        if (arr[i] > arr[ind]) 
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }
    reverse(arr.begin() + ind + 1, arr.end());
    return arr;
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
    next_permutation(arr.begin(),arr.end());
    cout<<"The next permutation is: "<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
    vector<int> ans = nextGreaterPermutation(arr);

    cout << "The next permutation is: [";
    for (int i=0;i<ans.size();i++) 
    {
        cout << ans[i] << " ";
    }
    cout << "]"<<endl;
    return 0;
}