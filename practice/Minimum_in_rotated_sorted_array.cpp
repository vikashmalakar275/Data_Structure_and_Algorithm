/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.

[0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the 
array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].Given the sorted rotated array nums of unique elements,
 return the minimum element of this array.TC= O(log n) 
*/

#include <iostream>
#include <vector>
using namespace std;

//Naive Approach (Brute force):
int findMin_1(vector<int>& arr) {
    cout<<"Naive Approach (Brute force):"<<endl;
    int n = arr.size(); // size of the array.
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        // Always keep the minimum.
        mini = min(mini, arr[i]);
    }
    return mini;
}

//Optimal Approach(Using Binary Search): 
int findMin_2(vector<int>& arr) {
    cout<<"Optimal Approach(Using Binary Search): "<<endl;
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

//Further Optimization(Using Binary Search):
int findMin_3(vector<int>& arr) {
    cout<<"Further Optimization(Using Binary Search):"<<endl;
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    int a;
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    int ans1 = findMin_1(arr);
    cout << "The minimum element is: " << ans1 <<endl;
    int ans2 = findMin_2(arr);
    cout << "The minimum element is: " << ans2 <<endl;
    int ans3 = findMin_3(arr);
    cout << "The minimum element is: " << ans3 <<endl;
    return 0;
}