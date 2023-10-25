/*
Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

Examples
Example 1:
Input Format: N = 5, array[] = {1,2,4,5}
Result: 3
Explanation: In the given array, number 3 is missing. So, 3 is the answer.

Example 2:
Input Format: N = 3, array[] = {1,3}
Result: 2
Explanation: In the given array, number 2 is missing. So, 2 is the answer.
*/
#include <iostream>
using namespace std;

//Brute Force Approach
//TC = O(n)
//SC = O(1)
int missingNumber_1(vector<int> &arr,int n)
{
    for(int i=1;i<=n;i++)
    {
        int flag = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return i;
        }
    }
    return -1;
}

//Better Approach
//TC = O(n)
//SC = O(n)
int missingNumber_2(vector<int> &arr,int n)
{
    vector<int> hashArr(n + 1,0);
    for (int i = 0; i < n; i++)
    {
        hashArr[arr[i]]++;
    }
    for (int i = 1; i <= n; i++) 
    {
        if (hashArr[i] == 0) 
        {
            return i;
        }
    }
    return -1;
}

//Optimal Approach1
//TC = O(n)
//SC = O(1)
int missingNumber_3(vector<int> &arr,int n)
{
    int sum1 = (n * (n+1))/2;
    int sum2 = 0;
    for(int i=0;i<n-1;i++)
    {
        sum2 += arr[i];
    }
   // cout<<sum1<<" "<<sum2<<endl;
    return sum1 - sum2;
}

//Optimal Approach2
//TC = O(n)
//SC = O(1)
int missingNumber_4(vector<int> &arr, int n) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n - 1; i++) {
        xor2 = xor2 ^ arr[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ n; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

int main()
{
    int n;
    cout<<"Enter the size of Array;"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the Element of Array:"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int result1 = missingNumber_1(arr,n);
    if(result1>0)
    {
        cout<<"Missing number is "<<result1<<endl;
    }
    else
    {
        cout<<"No number is missing."<<endl;
    }
    int result2 = missingNumber_2(arr,n);
    if(result2>0)
    {
        cout<<"Missing number is "<<result2<<endl;
    }
    else
    {
        cout<<"No number is missing."<<endl;
    }
    int result3 = missingNumber_3(arr,n+1);
    if(result3>0)
    {
        cout<<"Missing number is "<<result3<<endl;
    }
    else
    {
        cout<<"No number is missing."<<endl;
    }
    int result4 = missingNumber_4(arr,n+1);
    if(result4>0)
    {
        cout<<"Missing number is "<<result4<<endl;
    }
    else
    {
        cout<<"No number is missing."<<endl;
    }

}