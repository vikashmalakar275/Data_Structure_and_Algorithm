/*
Armstrong number in C++
In this post, we will write a C++ Program to check a number is Armstrong or not. We will look at various ways to code Armstrong number in C++.

Armstrong number or not
While loop in C

Question: What is an Armstrong Number?
Answer: Any number that satisfies the following format –

abcd… = an + bn + cn + dn + …
Where n is the order(length/digits in number)
That is for any number num if the sum of individual digits is raised to the power of order if the result is equal to the number itself then it is an Armstrong number.
Example 1
Example = 407 (order/length = 3)
407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/

#include <iostream>

using namespace std;

int main()
{
    int number;
    cout<<"Enter the number :"<<endl;
    cin>>number;
    int length = to_string(number).length();
    int sum = 0;
    int num = number;
    while(number>0)
    {
        int rem = number%10;
        sum += pow(rem,length);
        number = number/10;
    }
    if(num == sum)
    {
        cout<<num<<" is Armstrong Number."<<endl;
    }
    else
    {
        cout<<num<<" is Not Armstrong Number."<<endl;
    }
    return  0;
}