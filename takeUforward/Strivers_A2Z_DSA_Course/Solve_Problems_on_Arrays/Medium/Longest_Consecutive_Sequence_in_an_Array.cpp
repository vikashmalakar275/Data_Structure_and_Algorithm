/*
Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

Examples
Example 1:

Input: [100, 200, 1, 3, 2, 4]

Output: 4

Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

Input: [3, 8, 5, 7, 6]

Output: 4

Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
*/

#include <iostream>
#include <unordered_set>
using namespace std;

//Brute Force Approach
//Time Complexity: O(N2), N = size of the given array.
//Reason: We are using nested loops each running for approximately N times.
//Space Complexity: O(1), as we are not using any extra space to solve this problem.
bool linearSearch(vector<int> &arr, int num) 
{
    for (int i = 0; i < arr.size(); i++) 
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}
int longest_consecutives_Array_2(vector<int> &arr) {
    int n = arr.size();
    int longest = 1;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int cnt = 1;
        while (linearSearch(arr, x + 1) == true) 
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}


//Optimal Approach 1
//Time Complexity: O(NlogN) + O(N), N = size of the given array.
//Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).
//Space Complexity: O(1), as we are not using any extra space to solve this problem.
int longest_consecutives_Array_1(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    int max_count = 0;
    int count = 0;
    for(int i=1;i<arr.size();i++)
    {
        if((arr[i]-arr[i-1]) == 1)
        {
            count++;
            max_count = max(count,max_count);
        }
        else
        {
            count = 0;
        }
    }
    return max_count+1;
}

//Optimal Approach 2 (using set data structure)
//Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
//Space Complexity: O(N), as we are using the set data structure to solve this problem.
int longest_consecutives_Array_3(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return 0;
    }

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < arr.size(); i++) 
    {
        st.insert(arr[i]);
    }
    for (auto it : st) 
    {
        if (st.find(it - 1) == st.end()) 
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() 
{
    int n;
    cout << "Enter the Size of Array: " << endl;
    cin >> n;
    cout << "Enter the elements of the array: " << endl;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout<<"The longest consecutive subsequence length = "<<longest_consecutives_Array_2(arr)<<endl;
    cout<<"The longest consecutive subsequence length = "<<longest_consecutives_Array_1(arr)<<endl;
    cout<<"The longest consecutive subsequence length = "<<longest_consecutives_Array_3(arr)<<endl;
    return 0;
}