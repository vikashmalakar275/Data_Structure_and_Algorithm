/*
Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Examples
Example 1:
Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Example 2:
Input: 1,2,0,1,0,4,0
Output: 1,2,1,4,0,0,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
*/

#include <iostream>
using namespace std;

//Brute Force Approach
//Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
//X = no. of non-zero elements, and N-X = total no. of zeros.
//Reason: O(N) for copying non-zero elements from the original to the temporary array. O(X) for again copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).
//Space Complexity: O(N), as we are using a temporary array to solve this problem and the maximum size of the array can be N in the worst case.
//Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements will be non-zero.
vector<int> moveAllZeroToLast_1(vector<int> arr)
{
    vector<int> temp;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++)
    {
        arr[i] = temp[i];
    }
    for(int i=temp.size();i<arr.size();i++)
    {
        arr[i] = 0;
    }
    return arr;
}

//Optimal Approach
//Time Complexity: O(N), N = size of the array.
//Reason: We have used 2 loops and using those loops, we are basically traversing the array once.
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
vector<int> moveAllZeroToLast_2(vector<int> arr)
{
    int j = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        return arr;
    }

    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
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
    vector<int> ans1 =  moveAllZeroToLast_1(arr);
    cout<<"Output :"<<endl;
    for(int i=0;i<ans1.size();i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    cout<<"Output :"<<endl;
    vector<int> ans2 = moveAllZeroToLast_2(arr);
    for(int i=0;i<ans2.size();i++)
    {
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
    return 0;
}