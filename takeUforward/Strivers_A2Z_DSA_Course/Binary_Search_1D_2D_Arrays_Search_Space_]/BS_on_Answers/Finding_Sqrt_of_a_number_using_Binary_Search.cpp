/*
Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of ‘sqrt(n)’.

Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.

Examples
Example 1:
Input Format: n = 36
Result: 6
Explanation: 6 is the square root of 36.

Example 2:
Input Format: n = 28
Result: 5
Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5.
*/

#include <iostream>
using namespace std;

//Time Complexity: O(N), N = the given number.
//Reason: Since we are using linear search, we traverse the entire answer space.
//Space Complexity: O(1) as we are not using any extra space.
int find_sqrt(int n)
{
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int mul = i*i;
        if(mul<=n)
        {
            ans = i;
        }
    }
    return ans;
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are basically using the Binary Search algorithm.
//Space Complexity: O(1) as we are not using any extra space.
int find_sqrt_1(int n)
{
    return sqrt(n);
}

//Time Complexity: O(logN), N = size of the given array.
//Reason: We are basically using the Binary Search algorithm.
//Space Complexity: O(1) as we are not using any extra space.
int find_sqrt_2(int n)
{
    int low = 1;
    int high = n;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int val = mid*mid;
        if(val<=n)
        {
            low = mid +1;
        }
        else
        {
            high = mid -1;
        }
    }
    return high;
}

int main()
{
    int n;
    cout<<"Enter the Number :"<<endl;
    cin>>n;
    cout<<"Square root of "<<n<<" is "<<find_sqrt(n)<<endl;
    cout<<"Square root of "<<n<<" is "<<find_sqrt_1(n)<<endl;
    cout<<"Square root of "<<n<<" is "<<find_sqrt_2(n)<<endl;
    return 0;
}