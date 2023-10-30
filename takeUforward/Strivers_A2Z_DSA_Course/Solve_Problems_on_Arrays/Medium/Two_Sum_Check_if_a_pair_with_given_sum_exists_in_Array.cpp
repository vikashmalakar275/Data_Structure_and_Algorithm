/*
Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Examples:

Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
	[-1, -1] (for 2nd variant)
Explanation: There exist no such two numbers whose sum is equal to the target.
*/

#include <iostream>
#include <vector>
using namespace std;

void twoSumCheck(vector<int> &arr, int target) 
{
       vector<int> indices;
       bool flag = false;
       for (int i = 0; i < arr.size(); i++)
       {
              for (int j = i + 1; j < arr.size(); j++)
              {
                     if (arr[i] + arr[j] == target)
                     {
                            indices.push_back(i);
                            indices.push_back(j);
                            flag = true;
                     }
              }
       }
       if (flag)
       {
              cout << "YES, index are "<< "[" << indices[0] << ", " << indices[1] << "]" << endl;
       }
       else
       {
              cout << "NO " << "[-1, -1]" << endl;
       }
}

int main() {
    int n;
    cout << "Enter the Size of Array: " << endl;
    cin >> n;
    
    int target;
    cout << "Enter the target sum: " << endl;
    cin >> target;
    
    cout << "Enter the elements of the array: " << endl;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    twoSumCheck(arr,target);
    return 0;
}
