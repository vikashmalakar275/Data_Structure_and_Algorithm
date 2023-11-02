/*
Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

Examples
Example 1:
Input Format: N = 3, nums[] = {3,2,3}
Result: 3
Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution. 

Example 2:
Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}

Result: 2

Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

Example 3:
Input Format:  N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}

Result: 4
*/
#include <iostream>
#include <map>
using namespace std;

//Bruteforce approach
//TC = O(n^2)
//SC = O(1)
int majority_element_1(vector<int> arr)
{
    int result = 0;
    for(int i=0;i<arr.size();i++)
    {
        int searchedElement = arr[i];
        int count = 0;
        for(int j=0;j<arr.size();j++)
        {
            if(searchedElement == arr[j])
            {
                count++;
            }
        }
        if(count>(arr.size()/2))
        {
            result = searchedElement;
        }
    }
    return result;
}

//Better Approach
//TC = O(n * log n)
//SC = O(n)
int majority_element_2(vector<int> arr)
{
    map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    for(auto x : mp)
    {
        if(x.second>arr.size()/2)
        {
            return x.first;
        }
    }
    return -1;
}

//Optimal Solution : Moore’s Voting Algorithm
//TC = O(n)
//SC = O(1)
int majority_element_3(vector<int> arr)
{
    int count = 0;
    int element;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            element = arr[i];
        }
        else if (element == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count1 = 0;
    for (int i = 0; i <arr.size(); i++)
    {
        if (arr[i] == element)
        {
            count1++;
        }
    }
    if (count1 > (arr.size() / 2))
    {
        return element;
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the Size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Majority Element that occurs more than N/2 = "<<majority_element_1(arr)<<endl;
    cout<<"Majority Element that occurs more than N/2 = "<<majority_element_2(arr)<<endl;
    cout<<"Majority Element that occurs more than N/2 = "<<majority_element_3(arr)<<endl;
    return 0;
}