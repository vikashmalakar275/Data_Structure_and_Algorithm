/*
Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Examples
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and 
sell on day 5 (price = 6), profit = 6-1 = 5.

Note: That buying on day 2 and selling on day 1 
is not allowed because you must buy before 
you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are 
done and the max profit = 0.
*/

#include <iostream>
using namespace std;

//Brute Force Approach
//Time Complexity = O(n2)
//Space Complexity = O(1)
int stock_buy_sell_max_profit_1(vector<int> arr)
{
    int maxProfit = 0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]<arr[j])
            {
                int profit = arr[j] - arr[i];
                maxProfit = max(maxProfit,profit);
            }
        }
    }
    return maxProfit;
}

//Optimal Approach
//Time Complexity = O(n)
//Space Complexity = O(1)
int stock_buy_sell_max_profit_2(vector<int> arr)
{
    int maxProfit = 0;
    int min = arr[0];
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>min)
        {
            int profit = arr[i] - min;
            maxProfit = max(profit,maxProfit);
        }
        if(arr[i]<min)
        {
            min = arr[i];
        }

    }
    return maxProfit;
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
    cout<<"Maximum Profit = "<<stock_buy_sell_max_profit_1(arr)<<endl;
    cout<<"Maximum Profit = "<<stock_buy_sell_max_profit_2(arr)<<endl;
    return 0;
}