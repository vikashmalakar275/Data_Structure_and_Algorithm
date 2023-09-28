/*
Octal to Binary Conversion
There are 2 approaches of converting an octal number into a binary number like:

Write 3 digit binary number for all the digits of a number from left to right. 
first convert octal to decimal and then decimal to binary .
We are using the second approach, it is a long but very simple approach which can also be implemented easily with minimum chances of error.

Octal to binary conversion
While loop in C
Method 1:-
Accept octal number
Convert it into decimal Equivalent
Convert this decimal value into Binary
Make sure you have visited these two pages before moving ahead with the code –

Octal to Decimal conversion
Decimal to Binary Conversion
*/
// this program converts octal to binary
// by converting octal->decimal->binary
#include<iostream>
#include<math.h>
using namespace std;

 
void
convert (int octal) 
{
  
int i = 0, decimal = 0;
  
 
    //converting octal to decimal
    while (octal != 0)
    
    {
      
int digit = octal % 10;
      
decimal += digit * pow (8, i);
      
 
octal /= 10;
      
i++;
    
} 
 
printf ("Decimal Value: %d\n", decimal);
  
 
long long binary = 0;
  
int rem;
  
i = 1;
  
 
    // converting decimal to binary here
    while (decimal != 0)
    
    {
      
rem = decimal % 2;
      
decimal /= 2;
      
binary += rem * i;
      
 
	// moving to next position ex: units -> tens
	i *= 10;
    
}
  
 
cout << binary<<endl;

}


 
int
main () 
{
  
int octal;
  
 
cout << "Octal Value: "; cin >> octal;
  convert (octal);
  return 0;
}