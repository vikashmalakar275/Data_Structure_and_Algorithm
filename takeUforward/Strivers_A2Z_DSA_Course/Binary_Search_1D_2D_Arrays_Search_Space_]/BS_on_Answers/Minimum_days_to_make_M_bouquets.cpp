/*
Problem Statement: You are given ‘N’ roses and you are also given an array ‘arr’  where ‘arr[i]’  denotes that the ‘ith’ rose will bloom on the ‘arr[i]th’ day.
You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly ‘k’ adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least ‘m’ bouquets each containing ‘k’ roses. Return -1 if it is not possible.

Examples
Example 1:
Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
Result: 12
Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

Example 2:
Input Format: N = 5, arr[] = {1, 10, 3, 10, 2}, m = 3, k = 2
Result: -1
Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.


Let's grasp the question better with the help of an example. Consider an array: {7, 7, 7, 7, 13, 11, 12, 7}. We aim to create bouquets with k, which is 3 adjacent flowers, and we need to make m, which is 2 such bouquets. Now, if we try to make bouquets on the 11th day, the first 4 flowers and the 6th and the last flowers would have bloomed. So, we will be having 6 flowers in total on the 11th day. However, we require two groups of 3 adjacent flowers each. Although we can form one group with the first 3 adjacent flowers, we cannot create a second group. Therefore, 11 is not the answer in this case.


If we choose the 12th day, we can make 2 such groups, one with the first 3 adjacent flowers and the other with the last 3 adjacent flowers. Hence, we need a minimum of 12 days to make 2 bouquets.


Observation: 


- Impossible case: To create m bouquets with k adjacent flowers each, we require a minimum of m*k flowers in total. If the number of flowers in the array, represented by array-size, is less than m*k, it becomes impossible to form m bouquets even after all the flowers have bloomed. In such cases, where array-size < m*k, we should return -1.
- Maximum possible answer: The maximum potential answer corresponds to the time needed for all the flowers to bloom. In other words, it is the highest value within the given array i.e. max(arr[]).
- Minimum possible answer: The minimum potential answer corresponds to the time needed for atleast one flower to bloom. In other words, it is the smallest value within the given array i.e. min(arr[]).

Note: From the above observations, we can conclude that our answer lies between the range [min(arr[]), max(arr[])].


How to calculate the number of bouquets we can make on dth day:


We will count the number of adjacent bloomed flowers(say cnt) and whenever we get a flower that is not bloomed, we will add the number of bouquets we can make with ‘cnt’ adjacent flowers i.e. floor(cnt/k) to the answer. We will follow the process throughout the array. 


Now, we will write a function possible(), that will return true if, on a certain day, we can make at least m bouquets otherwise it will return false. The steps will be the following:


possible(arr[], day, m, k) algorithm:


1. We will declare two variables i.e. ‘cnt’ and ‘noOfB’.
   cnt -> the number of adjacent flowers,
   noOfB -> the number of bouquets.
2. We will run a loop to traverse the array.
3. Inside the loop, we will do the following:
   1. If arr[i] <= day: This means the ith flower has bloomed. So, we will increase the number of adjacent flowers i.e. ‘cnt’ by 1.
   2. Otherwise, the flower has not bloomed. Here, we will calculate the number of bouquets we can make with ‘cnt’ adjacent flowers i.e. floor(cnt/k), and add it to the noOfB. Now, as this ith flower breaks the sequence of the adjacent bloomed flowers, we will set the ‘cnt’ 0.
4. Lastly, outside the loop, we will calculate the floor(cnt/k) and add it to the noOfB.
5. If noOfB >= m: This means, we can make at least m bouquets. So, we will return true.
6. Otherwise, We will return false.

Note: We actually pass a particular day as a parameter to the possible() function. The function returns true if it is possible to make atleast m bouquets on that particular day, otherwise, it returns false.
*/

#include <iostream>
typedef long long ll;
using namespace std;

bool possible(vector<int> arr,int day, int m,int k)
{
    int cnt = 0;
    int noOfB = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt/k);
            cnt = 0;
        }
    }
    noOfB += (cnt/k);
    return noOfB >= m;
}

//Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
//Reason: We are running a loop to check our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
int min_days_to_make_M_bouquets_1(vector<int> arr,int m,int k)
{
    long long bou = m * 1ll * k * 1ll;
    if(arr.size()<bou)
    {
        return -1;
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        mini = min(mini,arr[i]);
        maxi = max(maxi,arr[i]);
    }
    for(int i=mini;i<maxi;i++)
    {
        if(possible(arr,i,m,k))
        {
            return i;
        }
    }
    return -1;   
}

//Time Complexity: O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
//Reason: We are applying binary search on our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer ‘mid’, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).
//Space Complexity: O(1) as we are not using any extra space to solve this problem.
int min_days_to_make_M_bouquets_2(vector<int> arr,int m,int k)
{
    int bou = m*k;
    int n = arr.size();
    if (bou > n) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;   
}

int main()
{
    int n;
    cout<<"Enter the Size :"<<endl;
    cin>>n;
    cout<<"Enter the element of array :"<<endl;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int m,k;
    cout<<"Enter the number of bouque (m):"<<endl;
    cin>>m;
    cout<<"Enter the number of roses (k):"<<endl;
    cin>>k;

    cout<<"Minimum Number of days required = "<<min_days_to_make_M_bouquets_1(arr,m,k)<<endl;
    cout<<"Minimum Number of days required = "<<min_days_to_make_M_bouquets_2(arr,m,k)<<endl;
}