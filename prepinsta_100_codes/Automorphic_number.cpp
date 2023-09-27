/*
Automorphic  Number in C++
In this post, we will learn to code Automorphic Number in C++

An Automorphic number is a special number, whose’s square ends with the same digits as the number itself

C++ Program to check whether a number is an Automorphic number or not
Algorithm:-
Calculate the square of the number
Extract digits of the square from the end
If end digits and the number become equal at some point
Then its an automorphic number
*/
#include <iostream>
#include <string.h>

using namespace std;

bool isAutomorphic(int num)
{
    int sq = pow(num,2);
    string str = "";
    string sq_str = to_string(sq);
    for(int i=sq_str.length()/2;i<sq_str.length();i++)
    {
        str += sq_str[i];
    }
    if(to_string(num) == str)
    {
        return true;
    }
    return false;
}

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    if(isAutomorphic(num))
    {
        cout<<num<<" is a Automorphic Number."<<endl;
    }
    else
    {
        cout<<num<<" is not a Automorphic Number."<<endl;
    }
    return 0;
}