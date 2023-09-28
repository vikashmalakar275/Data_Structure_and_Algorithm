/*
HCF of Two Number
Here we will discuss how to find the HCF of Two Number (also known as GCD) using C++ programming language.

HCF ( Highest Common Factor ) of two numbers is the largest positive integer that can divide both the numbers
Method 1: Linear Quest to find HCF
Method 2: Euclidean Algorithm: Repeated Subtraction
Method 3: Recursive Euclidean Algorithm: Repeated Subtraction
Method 4: Modulo Recursive Euclidean Algorithm: Repeated Subtraction
Method 5: Handling Negative Numbers in HCF
*/

#include <iostream>

using namespace std;

//Linear Quest to find HCF
int HCF_1(int n1,int n2)
{
    int result = 0;
    for(int i=0;i<n1 || i<n2;i++)
    {
        if(n1%i == 0 && n2%i == 0)
        {
            result = i;
        }
    }
    return result;
}

int main()
{
    int num1,num2;
    cout<<"Enther the first Number :"<<endl;
    cin>>num1;
    cout<<"Enter the second Number :"<<endl;
    cin>>num2;
    cout<<"HCF of "<<num1<<" & "<<num2<<" is "<<HCF_1(num1,num2)<<endl;
    return 0;
}