/*
Binary to decimal conversion in C++
Binary Numbers are used by computers to do almost all operations. We will look at how Binary to decimal conversion in C++ works.

Ex:-  (11011)2 = 1 * 24 + 1 * 23 + 0 * 22 + 1 * 21 + 2 * 20
               = 16 + 8 + 0 + 2 + 1
               = (27)10

We will discuss the following methods in the post –

Algorithmic way (Binary to Decimal)
Inbuilt Method (Binary to Decimal)
*/
#include <iostream>
#include <string.h>

using namespace std;

//Method-1 == Algorithmic way (Binary to Decimal)
int BinaryToDecimal_1(int n)
{
    cout<<"Using Algorithmic way (Binary to Decimal)"<<endl;
    int i=0;
    int decimal = 0;
    while(n>0)
    {
        int rem = n%10;
        decimal += pow(2,i++)*rem;
        n /= 10;
    }
    return decimal;
    
}

//Method-2 == Inbuilt Method (Binary to Decimal)
int BinaryToDecimal_2(int n)
{
    cout<<"Using Inbuilt Method (Binary to Decimal)"<<endl;
    string str = to_string(n);
    return stoi(str,0,2);

}

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    cout<<"Binary = "<<num<<"\nDecimal = "<<BinaryToDecimal_1(num)<<endl;
    cout<<"Binary = "<<num<<"\nDecimal = "<<BinaryToDecimal_2(num)<<endl;
    return 0;
}