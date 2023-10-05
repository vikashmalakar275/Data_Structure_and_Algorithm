/*
Occurrence of a digit in a given number using C++
Here, in this page we will discuss the program that count the occurrence of a digit in a given number using C++.
The input may lie within the range of integer.
Method Discussed
Method 1 : Iterative way
Method 2 : Recursive way.
*/
#include <iostream>

using namespace std;

int occurrenceOfDigit(int num,char x)
{
    int count = 0;
    string str = to_string(num);
    for(int i=0;i<str.length();i++)
    {
        if(x == str[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    char x;
    cout<<"Enter the number whih you want to search count :"<<endl;
    cin>>x;
    cout<<x<<" comes "<<occurrenceOfDigit(n,x)<<" times in "<<n<<endl;
    return 0;
}