/*
Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Examples
Example 1:
Input Format:  array[] = {3,1,2,5,3}
Result: {3,4)
Explanation: A = 3 , B = 4 
Since 3 is appearing twice and 4 is missing

Example 2:
Input Format: array[] = {3,1,2,5,4,6,7,5}
Result: {5,8)
Explanation: A = 5 , B = 8 
Since 5 is appearing twice and 8 is missing
*/

#include <iostream>
using namespace std;

void repeatingAndMissing_1(vector<int> arr)
{
    for(int i=1;i<=arr.size();i++)
    {
        int count = 0;
        for(int j=0;j<arr.size();j++)
        {
            if(i==arr[j])
            {
                count++;
            }
        }
        if(count==2)
        {
            cout<<"Repeating element is = "<<i<<endl;
        }
        if(count==0)
        {
            cout<<"Mising element is = "<<i<<endl;
        }
    }
}

void repeatingAndMissing_2(vector<int> arr)
{

}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    repeatingAndMissing_1(arr);
}