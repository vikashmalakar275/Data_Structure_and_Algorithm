/*
Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

Pre-requisite: Majority Element(>N/2 times)

Examples
Example 1:
Input Format: N = 5, array[] = {1,2,2,3,2}
Result: 2
Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

Example 2:
Input Format:  N = 6, array[] = {11,33,33,11,33,11}
Result: 11 33
Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.
*/


#include <iostream>
using namespace std;

vector<int> majorityElement_1(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(ans.size() == 0 || ans[0] != arr[i])
        {
            int count = 0;
            for(int j=0;j<n;j++)
            {
                if(arr[i] == arr[j])
                {
                    count++;
                }
            }
            if(count>n/3)
            {
                ans.push_back(arr[i]);
            }
        }
        if (ans.size() == 2)
        {
            break;
        }
        
    }
    return ans;
    
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of the array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<int> ans1 = majorityElement_1(arr);
    if(ans1.size() == 0)
    {
        cout<<"No Majority Element presnet."<<endl;
    }
    else
    {
        for(int i=0;i<ans1.size();i++)
        {
            cout<<ans1[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}