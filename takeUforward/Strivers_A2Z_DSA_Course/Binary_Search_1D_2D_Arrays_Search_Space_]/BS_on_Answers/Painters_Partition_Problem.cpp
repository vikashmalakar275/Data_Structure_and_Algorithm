/*
Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

Pre-requisite: BS-18. Allocate Books or Book Allocation | Hard Binary Search

Examples
Example 1:
Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
Result: 10
Explanation: We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.

Example 2:
Input Format: N = 4, boards[] = {10, 20, 30, 40}, k = 2
Result: 60
Explanation: We can divide the first 3 boards for one painter and the last board for the second painter.

We can allocate the boards to the painters in several ways but it is clearly said in the question that we have to allocate the boards in such a way that the painters can paint all the boards in the minimum possible time. The painters will work simultaneously.


Note: Upon close observation, we can understand that this problem is similar to the previous problem: BS-18. Allocate Books or Book Allocation | Hard Binary Search. There we had to allocate books to the students and here we need to allocate walls to the painters.


Assume the given array is {10, 20, 30, 40} and number of painters, k = 2. Now, we can allocate these boards in different ways. Some of them are the following:


10 | 20, 30, 40  → Minimum time required to paint all the boards  = 90
10, 20 | 30, 40  → Minimum time required to paint all the boards = 70
10, 20, 30 | 40  → Minimum time required to paint all the boards = 60

From the above allocations, we can clearly observe that in the last case, the first painter will paint the first 3 walls in 60 units of time and the second painter will take 40 units of time. So, the minimum time required to paint all the boards is 60.


Observations:


Minimum possible answer: We will get the minimum answer when we give n boards of the array to n painters(i.e. Each painter will be allocated 1 board). Now, in this case, the minimum time required to paint all the boards will be the maximum element in the array. So, the minimum possible answer is max(arr[]).
Maximum possible answer: We will get the maximum answer when we give all n boards to a single painter. The total time required is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).

From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].


How to calculate the number of painters we need if we have to paint all the walls within ‘time’ units of time:


In order to calculate the number of painters we will write a function, countPainters(). This function will take the array and ‘time’ as parameters and return the number of painters to whom we can allocate the boards.


countPainters(arr[], time):


We will first declare two variables i.e. ‘painters’(stores the no. of painters), and ‘boardsPainter’(stores the unit of boards, a painter will paint). As we are starting with the first painter, ‘painters’ should be initialized with 1.
We will start traversing the given array.
If boardsPainter + arr[i] <= time: If upon adding the current board with ‘boardsPainter’ does not exceed the time limit, we can allocate this i-th board to the current painter.
Otherwise, we will move to the next painter(i.e. painters += 1 ) and allocate the i-th board.

Finally, we will return the value of ‘painters’.
*/

#include <iostream>
#include <numeric>
using namespace std;

int countPainter(vector<int> boards,int painter)
{
    int painter_count = 1;
    int board_sum = 0;
    for(int i=0;i<boards.size();i++)
    {
        if (board_sum + boards[i] <= painter)
        {
            board_sum += boards[i];
        }
        else
        {
            painter_count++;
            board_sum = boards[i];
        }
    }
    return painter_count;
}

//Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
//Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPainters() function for each number. Now, inside the countPainters() function, we are using a loop that runs for N times.
//Space Complexity:  O(1) as we are not using any extra space to solve this problem.
int painters_partition_1(vector<int> boards,int painters)
{
    int maxi = *max_element(boards.begin(),boards.end());
    int sum = accumulate(boards.begin(),boards.end(),0);
    for(int i=maxi;i<=sum;i++)
    {
        int calculate_painter = countPainter(boards,i);
        if(calculate_painter == painters)
        {
            return i;
        }
    }
    return -1;
}

//Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
//Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPainters() function for the value of ‘mid’. Now, inside the countPainters() function, we are using a loop that runs for N times.
//Space Complexity:  O(1) as we are not using any extra space to solve this problem.
int painters_partition_2(vector<int> boards, int painter)
{
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);
    while(low<=high)
    {
        int mid = (low+high)/2;
        int calculate_painter = countPainter(boards,mid);
        if(calculate_painter>painter)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int k;
    cout<<"Enter the Numbers of Painters :"<<endl;
    cin>>k;
    cout<<"area of the minimum time : "<<painters_partition_1(arr,k)<<endl;
    cout<<"area of the minimum time : "<<painters_partition_2(arr,k)<<endl;
    return 0;
}