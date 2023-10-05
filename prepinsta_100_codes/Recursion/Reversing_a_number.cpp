/*
Reversing a Number using Recursion in C++
 

Here, in this page we will discuss the program for reversing a number using recursion in C++ programming language. We are given with a number and need to print the reverse of the given number. We will discuss the both recursive and non-recursive method to find the reverse of the given input number.

Example :

Input : 1234
Output : 4321
*/

#include <iostream>
#include <string>

using namespace std;

void Reverse(string &str, int i = 0)
{
    int n = str.length();
    if (i == n / 2)
        return;
    swap(str[i], str[n - i - 1]);
    Reverse(str, i + 1);
}

int main()
{
    string n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    cout<<"Number :"<<n<<endl;
    Reverse(n);
    cout<<"Reverse of Number = "<<n<<endl;
    return 0;
}