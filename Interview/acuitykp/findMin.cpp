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

int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the middle element is greater than the rightmost element,
        // the minimum element must be in the right subarray.
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        // If the middle element is less than the rightmost element,
        // the minimum element must be in the left subarray.
        else {
            right = mid;
        }
    }

    // At this point, left and right will point to the minimum element.
    return nums[left];
}

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << findMin(nums) << std::endl; // Output: 0
    return 0;
}
