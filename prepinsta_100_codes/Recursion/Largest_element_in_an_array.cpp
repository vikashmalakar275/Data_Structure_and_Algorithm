/*
*/

#include <iostream>
#include <vector>

using namespace std;


int maxElement(vector<int> arr,int n)
{
    if(n==1)
    {
        return arr[0];
    }
    return max(arr[n-1],maxElement(arr,n-1));
}
int main()
{
    int n;
    cout<<"enter the size of array :"<<endl;
    cin>>n;
    cout<<"Enter the element of array :"<<endl;
    int a;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    int max_element = maxElement(arr,n);
    cout<<"Maximum element = "<<max_element<<endl;
    return 0;
}