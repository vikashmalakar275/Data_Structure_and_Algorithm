/*
Program to find Factors of a number
To find the answer to a number we will use a loop in which we start dividing the number with 1 up to the number itself and the numbers which perfectly divides the number are the factors.

For Example 100

Factors are: 1, 2, 4, 5, 10, 20, 25, 50, 100

C++ program to find the factors of a number
*/
#include <iostream>

using namespace std;

void factor_1(int n)
{
    cout<<"Factor of number="<<n<<" is ";
    for(int i=1;i<=n;i++)
    {
        if(n%i == 0)
        {
            cout<<i<<" , ";
        }
    }
    cout<<endl;
}


int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    factor_1(num);
    return 0;
}