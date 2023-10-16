/*
Problem Statement: Given an array of N integers, write a program to implement the Insertion sorting algorithm.

Examples:

Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: 
After sorting the array is: 9,13,20,24,46,52


Example 2:
Input: N=5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting the array is: 1,2,3,4,5

Approach: 

1. Select an element in each iteration from the unsorted array(using a loop).

2. Place it in its corresponding position in the sorted part and shift the remaining elements accordingly (using an inner loop and swapping).

3.The “inner while loop” basically shifts the elements using swapping.

*/

#include <iostream>

using namespace std;

void insertionSort(int arr[],int n)
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    } 
}

void printArray(int arr[], int n)
{
    cout<<"After Insertion Sort:"<<endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionSort(arr,n);
    printArray(arr,n);
}