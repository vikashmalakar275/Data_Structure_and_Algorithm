/*
Given two integer inputs num1 and num2, the objective is to write a code to Find the Sum of Numbers in a Given Range in C. To do so we’ll keep iterating and adding the numbers from num1 until num2 to the Sum variable.

Example
Input : 2 6
Output : 2 + 3 + 4 + 5 + 6 = 20
*/

#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the first num:"<<endl;
    int num1;
    cin>>num1;
    cout<<"Enter the second num:"<<endl;
    int num2;
    cin>>num2;
    int sum = 0;
    for(int i=num1;i<=num2;i++)
    {
        sum += i;
    }
    cout<<"Sum of the number from "<<num1<<" to "<<num2<<" is equal to "<<sum<<endl;
    return 0;
}