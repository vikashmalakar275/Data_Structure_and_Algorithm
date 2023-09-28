/*
C++ Program to find the GCD of two numbers
Here, in this section we will discuss GCD of two numbers in C++. GCD (Greatest Common Divisor) of two numbers is the largest number that divides both numbers.

Example : The GCD of 45 and 30 will be :
Factors of 45 are 3 X 3 X 5
Factors of 30 are 2 X 3 X 5
Common factors of 45 and 30 are : 3 X 5 , So the required GCD will be 15

GCD of two number in C++
Various Methods to calculate the GCD
Using Prime Factorization,
Euclid’s Algorithm,
Lehmer’s GCD algorithm
*/

#include <iostream>

using namespace std;

//Lehmer’s GCD algorithm
int GCD_1(int n1, int n2)
{
    if(n1==0)
    {
        return n2;
    }
    if(n2==0)
    {
        return n1;
    }
    if(n1>n2)
    {
        return GCD_1(n1-n2,n2);
    }
    return GCD_1(n1,n2-n1);
}

int main()
{
    int num1,num2;
    cout<<"Enter the first number :"<<endl;
    cin>>num1;
    cout<<"Enter the Second Number :"<<endl;
    cin>>num2;
    cout<<"GCD of "<<num1<<" & "<<num2<<" is "<<GCD_1(num1,num2)<<endl;
    return 0;
}