/*
Binary Search: Explained
This is the very first article of the Binary Search series. Until now, we have learned the linear search algorithm. Now, in this article, we will discuss another search algorithm i.e. the Binary Search algorithm. The flow of this article will be the following:

A real-life example of Binary Search
Coding problem example
Iterative code implementation of Binary Search
Recursive code implementation of Binary Search
Time complexity
Overflow case
A real-life example of Binary Search:
Problem statement: Assume there is a dictionary and we have to find the word “raj”.

Method 1: One of the many ways is to check every possible page of the entire dictionary and see if we can find the word “raj”. This technique is known as linear search.
Basically, we can traverse from the first till the end to find the target value in the search space i.e. the entire dictionary in our example.

Method 2: In this case, we will optimize our search by using the property of a dictionary i.e. a dictionary is always in the sorted order.

We will first try to open the dictionary in such a way that it is roughly divided into two parts. Then, we will check the left page. Now, assume the words on the left page starts with ‘s’. We can certainly say that our target word i.e. “raj” definitely comes before the words start with ‘s’. So, now, we need not search in the entire dictionary rather we will only search in the left half.
Now, we will do the same thing with the left half. First, we will divide it into 2 halves and then try to locate which half contains the word “raj”. Eventually, after certain steps, we will end up finding the word “raj”.
This is a typical real-life example of binary search. 

Note:

Binary search is only applicable in a sorted search space. The sorted search space does not necessarily have to be a sorted array. It can be anything but the search space must be sorted.
In binary search, we generally divide the search space into two equal halves and then try to locate which half contains the target. According to that, we shrink the search space size.
Coding problem example:
Problem statement: You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.

Let’s say the given array is = {3, 4, 6, 7, 9, 12, 16, 17} and target = 6.

Solution: 
present at index 2
*/
#include <iostream>
using namespace std;

//iterative approach
//So the overall time complexity is O(logN), where N = size of the given array.
int binarySearch(vector<int> arr,int target)
{
    sort(arr.begin(),arr.end());
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid]<target) 
        {
            low = mid + 1;
        }
        else if(arr[mid]>target)
        {
            high = mid - 1;
        }
    }
    return -1;
}

//Recursive approach
//So the overall time complexity is O(logN), where N = size of the given array.
int BS(vector<int> arr,int low,int high,int target)
{
    if(low>high)
    {
        return -1;
    }
    int mid = (low+high)/2;
    if(arr[mid] == target)
    {
        return mid;
    }
    else if(arr[mid]>target)
    {
        return BS(arr,low,mid-1,target);
    }
    return BS(arr,mid+1,high,target);
}
int binarySearch_2(vector<int> arr,int target)
{
    return BS(arr,0,arr.size()-1,target);
}

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of array ;"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int search;
    cout<<"Enter the searched element :"<<endl;
    cin>>search;
    cout <<"Target element present at index = "<<binarySearch(arr,search)<<endl;
    cout <<"Target element present at index = "<<binarySearch_2(arr,search)<<endl;
}
