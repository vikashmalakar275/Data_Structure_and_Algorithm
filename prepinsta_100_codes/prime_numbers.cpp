/*
C++ Program to Check Whether the Number is Prime or Not
A prime number is a number that can be divided by 1 and itself i.e. a number that can not be divided by any 
other number other than 1 or itself is a prime number.
 
Example 
Input : 5
Output : 5 is a Prime
*/

#include <iostream>

using namespace std;

//Method-1 == Simple iterative solution
void isPrime_1(int num)
{
    cout<<"Output = Simple iterative solution"<<endl;
    int count = 0;
    if(num<=1)
    {
        cout<<num<<" is not a prime number."<<endl;
    }
    for(int i=1;i<=num;i++)
    {
        if(num%i == 0)
        {
            count++;
        }
    }
    if(count == 2)
    {
        cout<<num<<" is a prime number."<<endl;
    }
    else
    {
        cout<<num<<" is not a prime number."<<endl;
    }
}

//Method-2 == Optimization by break condition
void isPrime_2(int num)
{
    cout<<"Output = Optimization by break condition"<<endl;
    bool flag = true;
    if(num<2)
    {
        cout<<num<<" is not a prime number."<<endl;
        return;
    }
    for(int i=2;i<num;i++)
    {
        if(num%i==0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout<<num<<" is a Prime number."<<endl;
    }
    else
    {
        cout<<num<<" is not a prime number."<<endl;
    }
}

//Method-3 == Optimization by n/2 iterations
void isPrime_3(int num)
{
    cout<<"Output = Optimization by n/2 iterations"<<endl;
    bool flag = true;
    if(num<2)
    {
        cout<<num<<" is not a prime number."<<endl;
        return;
    }
    for(int i=2;i<num/2;i++)
    {
        if(num%i == 0)
        {
            flag = false;
        }
    }
    if(flag)
    {
        cout<<num<<" is a Prime number."<<endl;
    }
    else
    {
        cout<<num<<" is a not Prime number."<<endl;
    }
}

//Method-4 == Optimization by √n
void isPrime_4(int num)
{
    cout<<"Output = Optimization by √n"<<endl;
    bool flag = true;
    if(num<2)
    {
        cout<<num<<" is not a prime number."<<endl;
        return;
    }
    for(int i=2;i<sqrt(num);i++)
    {
        if(num%i == 0)
        {
            flag = false;
        }
    }
    if(flag)
    {
        cout<<num<<" is a Prime number."<<endl;
    }
    else
    {
        cout<<num<<" is a not Prime number."<<endl;
    }
}

//Method-5 == Optimization by skipping even iteration
void isPrime_5(int num)
{
    cout<<"Output = Optimization by skipping even iteration"<<endl;
    bool flag = true;
    if(num<2)
    {
        cout<<num<<" is not a prime number."<<endl;
        return;
    }
    if(num==2)
    {
        cout<<num<<" is a prime number."<<endl;
        return;
    }
    for(int i=3;i<sqrt(num);i=i+2)
    {
        if(num%i == 0)
        {
            flag = false;
        }
    }
    if(flag)
    {
        cout<<num<<" is a prime number."<<endl;
    }
    else
    {
        cout<<num<<" is not a prime number."<<endl;
    }
}

//Method-6 == Basic Recursion technique
bool isPrime_6(int num, int i)
{
    if (num < 2)
    {
        return false;
    }

    if (i == num)
    {
        return true;
    }

    if (num % i == 0)
    {
        return false;
    }

    i += 1;
    return isPrime_6(num, i);
}

int main()
{
    int number;
    cout<<"Enter the number :"<<endl;
    cin>>number;
    isPrime_1(number);
    isPrime_2(number);
    isPrime_3(number);
    isPrime_4(number);
    isPrime_5(number);
    cout<<"Output = Basic Recursion technique."<<endl;
    if(isPrime_6(number,2))
    {
        cout<<number<<" is a prime number."<<endl;
    }
    else
    {
        cout<<number<<" is not a prime number."<<endl;
    }
    return 0;
}