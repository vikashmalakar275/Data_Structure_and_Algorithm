/*
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.
NOTE: Elements in the union should be in ascending order.

Examples
Example 1:
Input:
n = 5,m = 5.
arr1[] = {1,2,3,4,5}  
arr2[] = {2,3,4,4,5}
Output:
 {1,2,3,4,5}

Explanation: 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5} 

Example 2:
Input:
n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 
*/
#include <iostream>
#include <map>
#include <set>
using namespace std;

//Solution1
//Time Compleixty : O( (m+n)log(m+n) ) . Inserting a key in map takes logN times, where N is no of elements in map. At max map can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across insertion of all elements in worst it would take O((m+n)log(m+n) time.
//Using HashMap also takes the same time, On average insertion in unordered_map takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.
//Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 
//O(1) {If Space of union ArrayList is not considered}
vector <int> Union_1(vector<int> arr1, vector<int> arr2, int n, int m) 
{
  map <int,int > freq;
  vector <int> Union;
  for (int i = 0; i < n; i++)
  {
    freq[arr1[i]]++;
  }
  for (int i = 0; i < m; i++)
  {
    freq[arr2[i]]++;
  }
  for (auto & it: freq)
  {
    Union.push_back(it.first);
  }
  return Union;
}

//Solution2
//Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.
//Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.
//Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 
//O(1) {If Space of union ArrayList is not considered}
vector <int> Union_2(vector<int> arr1, vector<int> arr2, int n, int m) 
{
  set <int> s;
  vector <int> Union;
  for (int i = 0; i < n; i++)
  {
    s.insert(arr1[i]);
  }
  for (int i = 0; i < m; i++)
  {
    s.insert(arr2[i]);
  }
  for (auto & it: s)
  {
    Union.push_back(it);
  }
  return Union;
}

//Solution3
//Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 
//Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 
//O(1) {If Space of union ArrayList is not considered}
vector <int> Union_3(vector<int> arr1, vector<int> arr2, int n, int m) 
{
  int i = 0, j = 0;
  vector <int> Union;
  while (i < n && j < m) 
  {
    if (arr1[i] <= arr2[j])
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
      {
        Union.push_back(arr1[i]);
      }
      i++;
    } 
    else 
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
      {
        Union.push_back(arr2[j]);
      }
      j++;
    }
  }
  while (i < n)
  {
    if (Union.back() != arr1[i])
    {
      Union.push_back(arr1[i]);
    }
    i++;
  }
  while (j < m)
  {
    if (Union.back() != arr2[j])
    {
      Union.push_back(arr2[j]);
    }
    j++;
  }
  return Union;
}

int main()
{
    int n;
    std::cout<<"Enter the size of First Array :"<<endl;
    cin>>n;
    vector<int> arr1;
    std::cout<<"Enter the Element for First Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a1;
        cin>>a1;
        arr1.push_back(a1);
    }
    int m;
    std::cout<<"Enter the size of Second Array :"<<endl;
    cin>>m;
    vector<int> arr2;
    std::cout<<"Enter the Element for Second Array :"<<endl;
    for(int i=0;i<m;i++)
    {
        int a2;
        cin>>a2;
        arr2.push_back(a2);
    }
    vector < int > Union1 = Union_1(arr1, arr2, n, m);
    std::cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union1)
    {
        std::cout << val << " ";
    }
    std::cout<<endl;
    vector < int > Union2 = Union_2(arr1, arr2, n, m);
    std::cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union2)
    {
        std::cout << val << " ";
    }
    std::cout<<endl;
    vector < int > Union3 = Union_3(arr1, arr2, n, m);
    std::cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union3)
    {
        std::cout << val << " ";
    }
    std::cout<<endl;
}