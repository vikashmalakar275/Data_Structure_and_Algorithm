/*
Hexadecimal to Decimal in C++
All of us would remember Mark Watney, a botanist, who with the help of Hexadecimal escaped mars. In this post, we will do a little to write. a Program Hexadecimal to Decimal in C.

But, first we must understand what Hexadecimals are. Hexadecimal are number system with base 15. Generally, all addresses in memory are indexed in Hexadecimal format

Hexadecimal Range - (0, 15)

With numbers (0 - 9) represented as is

And 10 - A, 11 - B, 12 - C, 13 - D, 14 - E, 15 - F 
*/
#include <iostream>

using namespace std;

//Method-1 ==
int hexadecimalToDecimal(string num)
{
    int len = num.size();
    int dec = 0, index = 0;
    
    for(int i = len - 1; i >= 0; i--)
    {
        // Here we check if current array char is between (0-9)
        if (num[i] >= '0' && num[i] <= '9') 
        {
            // whenever current num[i] is in range '0' - '9' 
            // ascii int value can be fetched 
            // by subtracting 48 (Refer Ascii table) as ASCII val 0 : 48 
            int digit = int(num[i]) - 48; 
            dec += digit * pow(16, index); 
            index++; 
        } 

        // Here we check if current array char is between (A-F) 
        else if (num[i] >= 'A' && num[i] <= 'F') 
        { 
            // whenever current num[i] is in range 'A' - 'F' 
            // ascii int value can be fetched 
            // by subtracting 55 (Refer Ascii table) as 
            // ASCII val A : 65 and A must result 10 as value 
            int digit = int(num[i]) - 55; 
            dec += digit * pow(16, index); 
            index++; 
        } 
    } 
    return dec; 
}

int main()
{
    string num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    cout<<"Hexadecimal : "<<num<<"\nDecimal : "<<hexadecimalToDecimal(num)<<endl;
    return 0;
}