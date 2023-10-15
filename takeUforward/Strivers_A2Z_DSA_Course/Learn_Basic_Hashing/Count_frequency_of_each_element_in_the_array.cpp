/*
Problem statement: Given an array, we have found the number of occurrences of each element in the array.

Examples:

Example 1:
Input: arr[] = {10,5,10,15,10,5};
Output: 10  3
	 5  2
        15  1
Explanation: 10 occurs 3 times in the array
	      5 occurs 2 times in the array
              15 occurs 1 time in the array

Example2: 
Input: arr[] = {2,2,3,4,4,2};
Output: 2  3
	3  1
        4  2
Explanation: 2 occurs 3 times in the array
	     3 occurs 1 time in the array
             4 occurs 2 time in the array
*/

#include <iostream>
#include <unordered_map>
using namespace std;


//Brute Fore Approach
//TC = O(n^2)
//SC = O(n)
void count_frequency_1(int arr[],int n)
{
    vector<bool> visited(n,false);
    cout<<"Number : Frequency"<<endl;
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
        cout<<arr[i]<<" : "<<count<<endl;
    }
}

//Optimized solution
//TC = O(n)
//SC = O(n)
void count_frequency_2(int arr[],int n)
{
    cout<<"Optimized Solution\nNumber : Frequency"<<endl;
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
    for(auto x : ump)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
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
    count_frequency_1(arr,n);
    count_frequency_2(arr,n);
}