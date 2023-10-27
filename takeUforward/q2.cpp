#include <iostream>
using namespace std;


bool check(vector<int> temp)
{
    for(int i=0;i<temp.size()-1;i++)
    {
        if(temp[i>temp[i+1]])
        {
            return false;
        }
    }
    return true;
}

bool checkStrickly(vector<int> arr)
{
    int j=0;
    while(j<arr.size())
    {
        //cout<<j<<endl;
        vector<int> temp;
        for(int i=0;i<arr.size();i++)
        {
            if(i!=j)
            {
                temp.push_back(arr[i]);
            }
        }
        if(check(temp))
        {
            temp.clear();
            j++;
            continue;
        }else
        {
            return true;
        }
       // j++;
       // cout<<j<<endl;
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the size :"<<endl;
    cin>>n;
    cout<<"Enter the element of array :"<<endl;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    if(checkStrickly(arr))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}