/*
Friendly Pair in C++
friendly pair or not in c++
C Program to check Friendly Pair or not
We will write a code to Check Friendly pair in C++

Two numbers num1 & num2 are friendly pairs if the following holds true -

(Sum of divisors of num1)/num1= (Sum of divisors of num2)/num2
*/
#include <iostream>

using namespace std;

int main()
{
    int num1,num2;
    cout<<"Enter the First Number :"<<endl;
    cin>>num1;
    cout<<"Enter the Second Number :"<<endl;
    cin>>num2;
    int sum1 = 0,sum2 = 0;
    for(int i=1;i<num1;i++)
    {
        if(num1%i == 0)
        {
            sum1 += i;
        }
    }
    for(int i=1;i<num2;i++)
    {
        if(num2%i == 0)
        {
            sum2 += i;
        }
    }
    if((sum1/num1) ==(sum2/num2))
    {
        cout<<num1<<" & "<<num2<<" are friendly pair."<<endl;
    }
    else
    {
        cout<<num1<<" & "<<num2<<" are not a friendly pair."<<endl;
    }
    return 0;
}