/*
Finding number of digits in an integer in C++
Here we will discuss how to find the number of digits in an integer in c++ programming language.

An integer is made up a number of digits i.e. a number is a combination of 0-9. Example 9825 is any 
integer which has 4 digits.
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    int totalDigits = to_string(n).length();
    cout<<"The number of digits in an integer "<<n<<" is "<<totalDigits<<endl;
    return 0;
}