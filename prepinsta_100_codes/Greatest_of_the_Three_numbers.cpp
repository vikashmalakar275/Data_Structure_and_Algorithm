/*
Here we will discuss how to find the greatest of three numbers 
in C++ entered by the user in c++ programming language.
*/
#include <iostream>

using namespace std;

int main()
{
    int num1,num2,num3;
    cout<<"Enter the First Number :"<<endl;
    cin>>num1;
    cout<<"Enter the Second Number :"<<endl;
    cin>>num2;
    cout<<"Enter the Third Number :"<<endl;
    cin>>num3;
    if(num1>num2 && num1>num3)
    {
        cout<<num1<<" is greater."<<endl;
    }
    else if(num2>num1 && num2 > num3)
    {
        cout<<num2<<" is greater."<<endl;
    }
    else
    {
        cout<<num3<<" is greater."<<endl;
    }
    return 0;
}