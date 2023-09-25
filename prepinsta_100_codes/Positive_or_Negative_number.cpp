//The objective of the C++ code is to check whether a given integer input is Positive or Negative.
#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the number : \n";
    int number;
    cin>>number;
    if (number>=0)
    {
        cout<<number<<" is a postive number.";
    }
    else
    {
        cout<<number<<" is a negative number.";
    }
    
    return 0;
}