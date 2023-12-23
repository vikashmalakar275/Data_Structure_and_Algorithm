/*
Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the ‘nth root is not an integer, return -1.

Examples
Example 1:
Input Format: N = 3, M = 27
Result: 3
Explanation: The cube root of 27 is equal to 3.

Example 2:
Input Format: N = 4, M = 69
Result: -1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(M), M = the given number.
//Reason: Since we are using linear search, we traverse the entire answer space.
//Space Complexity: O(1) as we are not using any extra space.
int func(int base, int exp) {
    int ans = 1;
    while (exp-- > 0) 
    {
        ans *= base;
    }
    return ans;
}

int nth_root_1(int n,int m)
{
    for(int i=1;i<=m;i++)
    {
        if(func(i,n) == m)
        {
            return i;
        }
        if(func(i,n) > m)
        {
            break;
        }
    }
    return -1;
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are basically using binary search to find the minimum.
//Space Complexity: O(1)
//Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).

int nth_root_2(int n,int m)
{
    int low = 1;
    int high = m;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(func(mid,n) == m)
        {
            return mid;
        }
        else if(func(mid,n)>m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the Number 'N':"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the Number 'M':"<<endl;
    cin>>m;
    cout<<n<<"th root of "<<m<<" is = "<<nth_root_1(n,m)<<endl;
    cout<<n<<"th root of "<<m<<" is = "<<nth_root_2(n,m)<<endl;
}