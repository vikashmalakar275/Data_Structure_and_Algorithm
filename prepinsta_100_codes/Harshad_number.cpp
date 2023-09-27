/*
Harshad Number in C++ 
A Harshad number is a positive integer that is divisible by the sum of the digits of the integer. It is also called the Niven number.

For Example : 153
Sum of digits = 1 + 5 + 3 = 9

153is divisible by 9 so 153 is a Harshad Number.
*/
#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    int temp = num;
    int sum = 0;
    while(num>0)
    {
        int rem = num%10;
        sum += rem;
        num /= 10;
    }
    if(temp%sum == 0)
    {
        cout<<temp<<" is Harshad Number."<<endl;
    }
    else
    {
        cout<<temp<<" is not a Harshad Number."<<endl;
    }
    return 0;
}