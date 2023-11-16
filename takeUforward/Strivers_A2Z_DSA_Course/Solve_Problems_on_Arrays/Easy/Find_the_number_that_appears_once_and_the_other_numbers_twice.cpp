/*
Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Examples
Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.

Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.
*/
#include <iostream>
#include<map>
using namespace std;

//Brute Force Approach
//Time Complexity: O(N2), where N = size of the given array.
//Reason: For every element, we are performing a linear search to count its occurrence. The linear search takes O(N) time complexity. And there are N elements in the array. So, the total time complexity will be O(N2).
//Space Complexity: O(1) as we are not using any extra space.
int find_number_appears_once_1(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        int count = 0;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count==1)
        {
            return arr[i];
        }
    }
    return -1;
}

//Better Approach 1
//Time Complexity: O(N)+O(N)+O(N), where N = size of the array
//Reason: One O(N) is for finding the maximum, the second one is to hash the elements and the third one is to search the single element in the array.
//Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
int find_number_appears_once_2(vector<int> arr)
{
    int maxElement = arr[0];
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>maxElement)
        {
            maxElement = arr[i];
        }
    }
    vector<int> freq(maxElement+1,0);
    for(int i=0;i<arr.size();i++)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<freq.size();i++)
    {
        if(freq[i] == 1)
        {
            return i;
        }
    }
    return -1;
}

//Better Approach 2
//Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
//Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M = size of the map). So this results in the first term O(N*logM). The second term is to iterate the map and search the single element. In Java, HashMap generally takes O(1) time complexity for insertion and search. In that case, the time complexity will be O(N) + O(M).
//Note: The time complexity will be changed depending on which map data structure we are using. If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).
//Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
int find_number_appears_once_3(vector<int> arr)
{
    map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp)
    {
        if(it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

//Optimal Approach(Using XOR)
//Time Complexity: O(N), where N = size of the array.
//Reason: We are iterating the array only once.
//Space Complexity: O(1) as we are not using any extra space.
int find_number_appears_once_4(vector<int> arr)
{
    int xorr = 0;
    for(int i=0;i<arr.size();i++)
    {
        xorr = xorr^arr[i];
    }
    return xorr;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array:"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the Element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int result1 = find_number_appears_once_1(arr);
    if(result1 > 0)
    {
        cout<<"Number that appears once = "<<result1<<endl;
    }
    else
    {
        cout<<"No Number appear Once."<<endl;
    }

    int result2 = find_number_appears_once_2(arr);
    if(result2 > 0)
    {
        cout<<"Number that appears once = "<<result2<<endl;
    }
    else
    {
        cout<<"No Number appear Once."<<endl;
    }

    int result3 = find_number_appears_once_3(arr);
    if(result3 > 0)
    {
        cout<<"Number that appears once = "<<result3<<endl;
    }
    else
    {
        cout<<"No Number appear Once."<<endl;
    }

    int result4 = find_number_appears_once_4(arr);
    if(result4 > 0)
    {
        cout<<"Number that appears once = "<<result4<<endl;
    }
    else
    {
        cout<<"No Number appear Once."<<endl;
    }
}