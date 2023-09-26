/*
Finding Prime Factors of a Number
What are Prime Factors?
Prime factors are factors of a number that are, themselves, prime numbers. There are many methods to find the prime factors of a number, but one of the most common is to use a prime factor tree.

For example, if the Input number is 12, then the Output should be [2, 2, 3]. And if the input number is 315, then the output should be [3, 3, 5, 7].

Finding Prime Factors of a Number
Finding Prime Factors of a Number in C++
Prime factors are basically the factors of the number input which are prime themselves. For instance the prime factors of “24”, without duplication, are [ 12, 2, 6, 3] but the Prime Factors, without duplication, are [ 2, 3]. The best way to find out the prime factors is to find the factors of the given number input and check whether they’re prime numbers or not. 

For instance, Let the input number be “315”. The factors of “315”, without duplication, are [ 63, 21, 5, 3, 7]. For Prime factors we will now check which of the following numbers are Prime number by dividing each number with all the number from 2 to square root of the current factor. If it’s divisible by any number other than itself, it’s not a prime. It’s  prime otherwise. Therefore the Prime Factors of “315”, Without duplication, are [ 5, 3, 7].
*/
#include <iostream>
using namespace std;

bool isPrime(int num)
{
    bool flag = true;
    if(num<2)
    {
        return false;
    }
    for(int i=2;i<num;i++)
    {
        if(num%i==0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int num;
    cout<<"Enter the number :"<<endl;
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        if(num%i == 0 && isPrime(i))
        {
            cout<<i<<" ";
        }
    }
    cout<<"is prime factor of "<<num<<endl;
    return 0;
}