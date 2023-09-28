/*
LCM of two numbers
 

Here we will discuss how to find the LCM of two numbers in C++ programming language. LCM, or least common multiple in mathematics, of two numbers is the smallest positive integer that is divisible by both the numbers.

LCM of two numbers in C++
We will learn
Method 1: A linear way to calculate LCM
Method 2: Modified interval Linear way
Method 3: Simple usage of HCF calculation to determine LCM
Method 4: Repeated subtraction to calculate HCF and determine LCM
Method 5: Recursive repeated subtraction to calculate HCF and determine LCM
Method 6: Modulo Recursive repeated subtraction to calculate HCF and determine LCM
*/

#include <iostream>

using namespace std;
//Method 1: A linear way to calculate LCM
int LCM_1(int n1,int n2)
{
    int result = 0;
    for(int i = max(n1,n2);i<(n1*n2);i++)
    {
        if(i%n1 ==0 && i%n2 == 0)
        {
            result = i;
            break;
        }
    }
    return result;
}

int main()
{
    int num1,num2;
    cout<<"Enter the first number :"<<endl;
    cin>>num1;
    cout<<"Enter the second number :"<<endl;
    cin>>num2;
    cout<<"LCM of "<<num1<<" & "<<num2<<" is "<<LCM_1(num1,num2)<<endl;
    return 0;
}