/*
Add two fractions in C++
In this article we will discuss the program for add two fractions in C++. For this purpose we need to ask the user to enter two fractional values where each fraction must consist a Numerator and a Denominator.

Program to add two fractions
Addtion of two fractions in C++
Concept
 For understanding this in a better way lets suppose an example :

 Suppose, First fraction consist of 1 as numerator and 3 as denominator, and Second fraction consist of 3 as numerator and 9 as denominator.

 (1 / 3) + (3 / 9) = (6 / 9) = (2 / 3)

Find LCM of 3 and 9 and the result will be 9.
Multiply 3 in first fraction : (3 / 9) + (3 / 9)
Add both fractions and then the result will be : (6 / 9)
Now simplify it by finding the HCF of 6 and 9 and the result will be 3.
So divide 6 and 9 by 3 and then the result will be : (2 / 3)
This will be your simplified answer for the given problem.
Algorithm
Initialize variables of numerator and denominator
Take user input of two fraction
Find numerator using this condition (n1*d2) +(d1*n2 ) where n1,n2 are numerator and d1 and d2 are denominator
Find denominator using this condition (d1*d2) for lcm
Calculate GCD of a this new numerator and denominator
Display a two value of this condition x / gcd, y/gcd
*/
#include <iostream>

using namespace std;

// int LCM(int n1,int n2)
// {
//     int result = 0;
//     for(int i = max(n1,n2);i<(n1*n2);i++)
//     {
//         if(i%n1 ==0 && i%n2 == 0)
//         {
//             result = i;
//             break;
//         }
//     }
//     return result;
// }

int HCF(int n1,int n2)
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
    int num1,den1,num2,den2;
    cout<<"Enter the first Numerator : "<<endl;
    cin>>num1;
    cout<<"Enter the first denominator : "<<endl;
    cin>>den1;
    cout<<"Enter the first Numerator : "<<endl;
    cin>>num2;
    cout<<"Enter the first denominator : "<<endl;
    cin>>den2;
    //finding lcm of the denominators
    int lcm = (den1*den2)/HCF(den1,den2);
    
    //finding the sum of the numbers
    int sum=(num1*lcm/den1) + (num2*lcm/den2);
    
    //normalizing numerator and denominator of result
    int num3=sum/HCF(sum,lcm);
    
    lcm=lcm/HCF(sum,lcm);
    
    //printing output
    cout<<num1<<"/"<<den1<<" + "<<num2<<"/"<<den2<<" = "<<num3<<"/"<<lcm<<endl;
    return 0;
}