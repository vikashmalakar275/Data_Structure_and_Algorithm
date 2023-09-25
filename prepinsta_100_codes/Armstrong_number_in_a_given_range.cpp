/*
Find the Armstrong Numbers in a given Interval in C++
Given two integer inputs as high and low, the objective is to find all the Armstrong Numbers that falls under the limits [Low,High] interval. Before Going into the Explanation let’s understand the problem.

Armstrong Numbers
In number theory, a narcissistic number in a given number base b is a number that is the sum of its own digits each raised to the power of the number of digits.

Example 1:
Input : 100 400
Output :153 370 371
Explanation : 100 and 400 are given 
two integers.(interval)
  153 = 1*1*1 + 5*5*5 + 3*3*3 
      = 1 + 125 + 27
      =  153  
  370 = 3*3*3 + 7*7*7 + 0
      = 27 + 343 
      = 370
  371 = 3*3*3 + 7*7*7 + 1*1*1
      = 27 + 343 +1
      = 371 
Let’s take the above example and try to understand the definition of Armstrong Numbers, The input for the code as mentioned is the range within which we search for the Armstrong Numbers. The Armstrong Number we Found were 153, 370 and 371. According to the Definition an Armstrong number is any number that can be expressed an the sum of it’s digits raised to the power of it’s length. And as the above mentioned numbers satisfy the conditions, They are printed out as Armstrong Numbers lying with the range [100,400].
*/

#include <iostream>

using namespace std;

bool isArmstrong(int number)
{
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
        return true;
    }
    return false;
}

int main()
{
    int num1,num2;
    cout<<"Enter the first number :"<<endl;
    cin>>num1;
    cout<<"Enter the first number :"<<endl;
    cin>>num2;
    for(int i=num1;i<=num2;i++)
    {
        if(isArmstrong(i))
        {
            cout<<i<<" is a Armstrong number."<<endl;
        }
    }
}