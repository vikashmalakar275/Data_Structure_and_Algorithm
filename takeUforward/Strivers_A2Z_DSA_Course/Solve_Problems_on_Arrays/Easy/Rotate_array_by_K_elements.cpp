/*
Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

Examples:

Example 1:
Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
Output: 6 7 1 2 3 4 5
Explanation: array is rotated to right by 2 position .

Example 2:
Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left 
Output: 9 10 11 3 7 8
Explanation: Array is rotated to right by 3 position.
*/

#include <iostream>
using namespace std;

//Approach 1
//using a temp array
//This function used for rotate a array to right by k 
//Time Complexity: O(n)
//Space Complexity: O(k) since k array element needs to be stored in temp array 
void Rotatetoright(vector<int> arr, int n, int k)
{
  if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  int temp[k];
  for (int i = n - k; i < n; i++)
  {
    temp[i - n + k] = arr[i];
  }
  for (int i = n - k - 1; i >= 0; i--)
  {
    arr[i + k] = arr[i];
  }
  for (int i = 0; i < k; i++)
  {
    arr[i] = temp[i];
  }
  cout << "After Rotating the elements to right " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout<<endl;
}

//using a temp array
//This function used for rotate a array to left by k 
//Time Complexity: O(n)
//Space Complexity: O(k) since k array element needs to be stored in temp array 
void Rotatetoleft(vector<int> arr, int n, int k)
{
  if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  int temp[k];
  for (int i = 0; i < k; i++)
  {
    temp[i] = arr[i];
  }
  for (int i = 0; i < n - k; i++)
  {
    arr[i] = arr[i + k];
  }
  for (int i = n - k; i < n; i++)
  {
    arr[i] = temp[i - n + k];
  }
  cout << "After Rotating the elements to left " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout<<endl;
}


//Approach 2 : using recursion
//Function used for resvese the array
void Reverse(vector<int> &arr, int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

// Function to Rotate k elements to right
//Time Complexity – O(N) where N is the number of elements in an array
//Space Complexity – O(1) since no extra space is required
void Rotateeletoright(vector<int> &arr, int n, int k)
{
  // Reverse first n-k elements
  Reverse(arr, 0, n - k - 1);
  // Reverse last k elements
  Reverse(arr, n - k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);
}

// Function to Rotate k elements to left
//Time Complexity – O(N) where N is the number of elements in an array
//Space Complexity – O(1) since no extra space is required
void Rotateeletoleft(vector<int> &arr, int n, int k)
{
  // Reverse first k elements
  Reverse(arr, 0, k - 1);
  // Reverse last n-k elements
  Reverse(arr, k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);
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
    int k;
    cout<<"Eneter the number you want rotate :"<<endl;
    cin>>k;
    string str;
    cout<<"Enter you rotate choice eg. left/right :"<<endl;
    cin>>str;
    if(str == "left")
    {
      cout<<"Array after left rotate :"<<endl;
      Rotatetoleft(arr,n,k);
      Rotateeletoleft(arr,n,k);
    }
    if(str == "right")
    {
      cout<<"Array after right rotate :"<<endl;
     Rotatetoright(arr,n,k);
     Rotateeletoright(arr,n,k);
    }
    for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}