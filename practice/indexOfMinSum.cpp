/*
int arr[] = [5,3,8,2,9,1,4,6]
min sum of index = 3,5
*/


#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the sie of array :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the element in array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum = INT_MAX;
    int first_index = -1, second_index = -1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum1 = arr[i]+arr[j];
            if(sum1<sum)
            {
                sum = sum1;
                first_index = i;
                second_index = j;
            }
        }
    }
    cout<<"The minium Sum is "<<sum<<" and the element at index ("<<first_index<<","<<second_index<<")"<<endl;

    return 0;
}