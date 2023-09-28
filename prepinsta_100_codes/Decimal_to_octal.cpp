/*
Program for Decimal to Octal conversion in C++
We are going. to understand how to code Decimal to Octal Conversion in C++ and different ways of coding Decimal to Octal in C++

The C++ program to convert decimal to octal number accepts a decimal number from the user. This number is further converted to its equivalent octal number after following a series of steps. The following section gives an algorithm for this conversion. It is then followed by a C++ program.

Decimal to Octal in C++
While loop in C
Methods discussed
Using an array to store the comparable octal value
Using int variable to store comparable octal value
*/

#include <iostream>

using namespace std;

//Method-1
int decimalToOctal(int num)
{
    string octal = "",result = "";
    while(num>0)
    {
        int rem = num%8;
        octal += to_string(rem);
        num /= 8;
    }
    for(int i=octal.length() - 1;i>=0;i--)
    {
        result += octal[i];
    }
    return stoi(result);
}

int main()
{
    int num;
    cout<<"Enter the Deciaml Number : "<<endl;
    cin>>num;
    cout<<"Deciaml : "<<num<<"\nOctal : "<<decimalToOctal(num)<<endl;

    return 0;
}