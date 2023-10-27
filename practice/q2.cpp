//fibbonacci series

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;
    int first = 0;
    int second = 1;
    cout<<first<<" "<<second<<" ";
    int temp = n-2;
    int i=1;
    while(i<=temp)
    {
        int next = first + second;
        cout<<next<<" ";
        first = second;
        second = next;
        i++;
    }
}