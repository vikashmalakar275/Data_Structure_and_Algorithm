/*
Octal to Decimal Conversion in C++
Here, on this page, we will discuss octal to decimal conversion in C++. Let’s have a look at an example before moving ahead with code of Octal to Decimal in C++.

(462)8 = 4 * 82 + 6 * 81 + 2 * 80
256 + 48 + 2 = (306)10

Different Methods discussed
We will discuss the following methods in the post –

Algorithmic way (Octal to Decimal)
Inbuilt Method (Octal to Decimal)
*/
#include <iostream>

using namespace std;

//Algorithmic way (Octal to Decimal)
int octalToDecimal_1(int n)
{
    int decimal = 0;
    int i=0;
    while(n>0)
    {
        int rem = n%10;
        decimal += pow(8,i++)*rem;
        n /= 10;
    }
    return decimal;
}

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    cout<<"Ocatl = "<<num<<"\nDecimal = "<<octalToDecimal_1(num)<<endl;  
    return 0;
}