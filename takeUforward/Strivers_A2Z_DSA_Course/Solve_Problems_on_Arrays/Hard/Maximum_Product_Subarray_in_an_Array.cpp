/*
Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

Examples
Example 1:
Input:
 Nums = [1,2,3,4,5,0]
Output:
 120
Explanation:
 In the given array, we can see 1×2×3×4×5 gives maximum product value.


Example 2:
Input:
 Nums = [1,2,-3,0,-4,-5]
Output:
 20
Explanation:
 In the given array, we can see (-4)×(-5) gives maximum product value.
*/
#include <iostream>
using namespace std;

//Brute Force Approach
//Time Complexity: O(N3)
//Reason: We are using 3 nested loops for finding all possible subarrays and their product.
//Space Complexity: O(1)
//Reason: No extra data structure was used
int max_product_subarray_1(vector<int> arr)
{
    int maxProd = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i;j<arr.size();j++)
        {
            int prod = 1;
            for(int k=i;k<=j;k++)
            {
                prod *= arr[k]; 
            }
            maxProd = max(prod,maxProd);
        }
    }
    return maxProd;
}

//Better Approach
//Time Complexity: O(N2)
//Reason: We are using two nested loops
//Space Complexity: O(1)
//Reason: No extra data structures are used for computation
int max_product_subarray_2(vector<int> arr)
{
    int maxProd = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        int prod = 1;
        for(int j=i;j<arr.size();j++)
        {
            prod *= arr[j];
            maxProd = max(prod,maxProd);
        }
    }
    return maxProd;
}

//optimal approach 1
//Time Complexity: O(N), N = size of the given array.
//Reason: We are using a single loop that runs for N times.
//Space Complexity: O(1) as No extra data structures are used for computation.
int max_product_subarray_3(vector<int> arr)
{
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < arr.size(); i++) 
    {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[arr.size() - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

//Optimal approach 2
//Time Complexity: O(N)
//Reason: A single iteration is used.
//Space Complexity: O(1)
//Reason: No extra data structure is used for computation
int max_product_subarray_4(vector<int> arr)
{
    int prod1 = arr[0],prod2 = arr[0],result = arr[0];
    for(int i=1;i<arr.size();i++) 
    {
        int temp = max({arr[i],prod1*arr[i],prod2*arr[i]});
        prod2 = min({arr[i],prod1*arr[i],prod2*arr[i]});
        prod1 = temp;
        result = max(result,prod1);
    }
    return result;
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

    cout<<"Maximum product subarray = "<<max_product_subarray_1(arr)<<endl;
    cout<<"Maximum product subarray = "<<max_product_subarray_2(arr)<<endl;
    cout<<"Maximum product subarray = "<<max_product_subarray_3(arr)<<endl;
    cout<<"Maximum product subarray = "<<max_product_subarray_4(arr)<<endl;
    return 0;
}