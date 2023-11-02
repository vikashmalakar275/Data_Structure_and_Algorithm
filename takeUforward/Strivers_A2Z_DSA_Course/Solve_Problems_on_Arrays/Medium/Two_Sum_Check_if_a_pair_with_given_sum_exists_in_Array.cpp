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

//Naive Approach(Brute-force approach)
//Time Complexity: O(N2), where N = size of the array.
//Reason: There are two loops(i.e. nested) each running for approximately N times.
//Space Complexity: O(1) as we are not using any extra space.
void twoSumCheck_1(vector<int> arr, int target) 
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

//Better Approach(using Hashing):
//TC = O(n)
//SC = O(n)
void twoSumCheck_2(vector<int> arr,int target)
{
       unordered_map<int, int> mpp;
       vector<int> indices;
       bool flag = false;
       for (int i = 0; i < arr.size(); i++)
       {
              int num = arr[i];
              int moreNeeded = target - num;
              if (mpp.find(moreNeeded) != mpp.end())
              {
                     flag = true;
                     indices.push_back(mpp[moreNeeded]);
                     indices.push_back(i);
              }
              mpp[num] = i;
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

//optimal Solution
//Time Complexity: O(N) + O(N*logN), where N = size of the array.
//Space Complexity: O(1) as we are not using any extra space.
// void twoSumCheck_3(vector<int> arr,int target)
// {
//        int n=arr.size();
//        sort(arr.begin(), arr.end());
//        vector<int> indices;
//        int left = 0, right = n - 1;
//        bool flag = false;
//        while (left < right)
//        {
//               int sum = arr[left] + arr[right];
//               if (sum == target) 
//               {
//                      flag = true;
//                      indices.push_back(left);
//                      indices.push_back(right);
//               }
//               else if (sum < target)
//               {
//                      left++;
//               }
//               else 
//               {
//                      right--;
//               }
//        }
//        if (flag)
//        {
//               cout << "YES, index are "<< "[" << indices[0] << ", " << indices[1] << "]" << endl;
//        }
//        else
//        {
//               cout << "NO " << "[-1, -1]" << endl;
//        }
// }


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
    twoSumCheck_1(arr,target);
    twoSumCheck_2(arr,target);
//    twoSumCheck_3(arr,target);
    return 0;
}
