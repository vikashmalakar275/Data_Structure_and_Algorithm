/*
Problem Statement: Given an array of size N. Find the highest and lowest frequency element.

Pre-requisite: Hashing Theory and  Counting frequencies of array elements

Examples:

Example 1:
Input: array[] = {10,5,10,15,10,5};
Output: 10 15
Explanation: The frequency of 10 is 3, i.e. the highest and the frequency of 15 is 1 i.e. the lowest.

Example 2:

Input: array[] = {2,2,3,4,4,2};
Output: 2 3
Explanation: The frequency of 2 is 3, i.e. the highest and the frequency of 3 is 1 i.e. the lowest.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

//Brute Fore Approach
//TC = O(n^2)
//SC = O(n)
void highestAndLowestFrequencyElement_1(int arr[],int n)
{
    cout<<"By Brute Force Approach\n";
    vector<bool> visited(n,false);
    cout<<"Number : Frequency"<<endl;
    int maxFreqElement = 0, minFreqElement = 0;
    int maxFreq = 0, minFreq = n;
    for(int i=0;i<n;i++)
    {
        if(visited[i] == true)
        {
            continue;
        }
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[i] == arr[j])
            {
                visited[j] = true;
                count++;
            }
        }
        if(count>maxFreq)
        {
            maxFreq = count;
            maxFreqElement = arr[i];
        }
        if(count<minFreq)
        {
            minFreq = count;
            minFreqElement = arr[i];
        }
    }
    cout<<" Max Frequency Element : Frequecy\n"<<maxFreqElement<<" : "<<maxFreq<<endl;
    cout<<" Min Frequency Element : Frequecy\n"<<minFreqElement<<" : "<<minFreq<<endl;
}

//Optimized solution
//TC = O(n)
//SC = O(n)
void highestAndLowestFrequencyElement_2(int arr[],int n)
{
    cout<<"By Optimized solution\n";
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++)
    {
        ump[arr[i]]++;
    }
    // for (auto it = ump.begin(); it != ump.end(); ++it) 
    // {
    //     auto x = *it;
    //     cout<<it->first<<" : "<<it->second<<endl;
    // }
    int maxFreqElement = 0, minFreqElement = 0;
    int maxFreq = 0, minFreq = n;
    for(auto x : ump)
    {
        if(x.second>maxFreq)
        {
            maxFreq = x.second;
            maxFreqElement = x.first;
        }
        if(x.second<minFreq)
        {
            minFreq = x.second;
            minFreqElement = x.first;
        }
    }
    cout<<" Max Frequency Element : Frequecy\n"<<maxFreqElement<<" : "<<maxFreq<<endl;
    cout<<" Min Frequency Element : Frequecy\n"<<minFreqElement<<" : "<<minFreq<<endl;
}

int main()
{
    cout<<"Enter the size of array :"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the element of array :"<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    highestAndLowestFrequencyElement_1(arr,n);
    highestAndLowestFrequencyElement_2(arr,n);
}