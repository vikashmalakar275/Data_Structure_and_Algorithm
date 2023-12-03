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

int max_product_subarray_1(vector<int> arr)
{

}

int max_product_subarray_2(vector<int> arr)
{

}

int max_product_subarray_3(vector<int> arr)
{

}

int max_product_subarray_4(vector<int> arr)
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

    cout<<"Toatl Inversion = "<<max_product_subarray_1(arr)<<endl;
    cout<<"Toatl Inversion = "<<max_product_subarray_2(arr)<<endl;
    cout<<"Toatl Inversion = "<<max_product_subarray_3(arr)<<endl;
    cout<<"Toatl Inversion = "<<max_product_subarray_4(arr)<<endl;
    return 0;
}