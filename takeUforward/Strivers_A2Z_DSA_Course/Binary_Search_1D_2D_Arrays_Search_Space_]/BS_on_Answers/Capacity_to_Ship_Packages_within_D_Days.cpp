/*
Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within ‘d’ days.
The weights of the packages are given in an array ‘of weights’. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
Find out the least-weight capacity so that you can ship all the packages within ‘d’ days.

Examples
Example 1:
Input Format: N = 8, weights[] = {5,4,5,2,3,4,5,6}, d = 5
Result: 9
Explanation: If the ship capacity is 9, the shipment will be done in the following manner:
Day         Weights            Total
1        -       5, 4          -        9
2        -       5, 2          -        7
3        -       3, 4          -        7
4        -       5              -        5
5        -       6              -        6
So, the least capacity should be 9.

Example 2:

Input Format: N = 10, weights[] = {1,2,3,4,5,6,7,8,9,10}, d = 1
Result: 55
Explanation: We have to ship all the goods in a single day. So, the weight capacity should be the summation of all the weights i.e. 55.

Observation:


Minimum ship capacity: The minimum ship capacity should be the maximum value in the given array. Let’s understand using an example. Assume the given weights array is {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} and the ship capacity is 8. Now in the question, it is clearly stated that the loaded weights in the ship must not exceed the maximum weight capacity of the ship. For this constraint, we can never ship the weights 9 and 10, if the ship capacity is 8. That is why, in order to ship all the weights, the minimum ship capacity should be equal to the maximum of the weights array i.e. nax(weights[]).
Maximum capacity: If the ship capacity is equal to the sum of all the weights, we can ship all goods within a single day. Any capacity greater than this will yield the same result. So, the maximum capacity will be the summation of all the weights i.e. sum(weights[]).

From the observations, it is clear that our answer lies in the range
[max(weights[]), sum(weights[])].


How to calculate the number of days required to ship all the weights for a certain ship capacity:


In order to calculate this, we will write a function findDays(). This function accepts the weights array and a capacity as parameters and returns the number of days required for that particular capacity. The steps will be the following:


findDays(weights[], cap):


1. We will declare to variables i.e. ‘days’(representing the required days) and ‘load’ (representing the loaded weights in the ship). As we are on the first day, ‘days’ should be initialized with 1 and ‘load’ should be initialized with 0.
2. Next, we will use a loop(say i) to iterate over the weights. For each weight, weights[i], we will check the following:
   1. If load+weights[i] > cap: If upon adding current weight with load exceeds the ship capacity, we will move on to the next day(i.e. day = day+1) and then load the current weight(i.e. Set load to weights[i], load = weights[i]).
   2. Otherwise, We will just add the current weight to the load(i.e. load = load+weights[i]).
3. Finally, we will return ‘days’ which represents the number of days required.
*/
#include <iostream>
using namespace std;

pair<int,int> get_max_sum(vector<int> arr)
{
    int maxi = arr[0];
    int sum = 0;
    for(int i=0;i<arr.size();i++)
    {
        maxi = max(maxi,arr[i]);
        sum += arr[i];
    }
    return make_pair(maxi,sum);
}

int daysreq(vector<int> weight,int cap)
{
    int days = 1,load = 0;
    for(int i=0;i<weight.size();i++)
    {
        if(load+weight[i]>cap)
        {
            days += 1;
            load = weight[i];
        }
        else
        {
            load += weight[i];
        }
    }
    return days;
}

//Time Complexity: O(N * (sum(weights[]) – max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
//Reason: We are using a loop from max(weights[]) to sum(weights[]) to check all possible weights. Inside the loop, we are calling findDays() function for each weight. Now, inside the findDays() function, we are using a loop that runs for N times.
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
int leastCapacity(vector<int> arr,int day)
{
    int maxi = get_max_sum(arr).first;
    int sum = get_max_sum(arr).second;
    for(int i=maxi;i<=sum;i++)
    {
        if(daysreq(arr,i)<=day)
        {
            return i;
        }
    }
    return -1;
}

//Time Complexity: O(N * log(sum(weights[]) – max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
//Reason: We are applying binary search on the range [max(weights[]), sum(weights[])]. For every possible answer ‘mid’, we are calling findDays() function. Now, inside the findDays() function, we are using a loop that runs for N times.
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
int leastCapacity_1(vector<int> arr,int day)
{
    int low = get_max_sum(arr).first;
    int high = get_max_sum(arr).second;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(daysreq(arr,mid)<=day)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int day;
    cout<<"Enter the days :"<<endl;
    cin>>day;
    cout<<"Least Capacity = "<<leastCapacity(arr,day)<<endl;
    cout<<"Least Capacity = "<<leastCapacity_1(arr,day)<<endl;
}