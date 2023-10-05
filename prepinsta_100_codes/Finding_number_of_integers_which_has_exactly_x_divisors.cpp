/*
Number of integers which has exactly x divisors in C++
 
Numbers dividing with self or 1 are called prime numbers but numbers having multiple divisors are called composite numbers. In this c++ program, we will find the numbers with the exact number of divisors defined by the user. The divisor of a number is defined as, when we divide a number ‘a’ by other number ‘b’ and gives remainder zero, so the ‘b’ will be considered as the divisor of the ‘a’.
Number of integers which has exactly x divisors in C++
Here, in this page we will discuss the two different ways for finding the required count of numbers that have exactly x divisors. These two methods are given below,

Method 1 : Naive approach
Method 2 : Efficient approach
*/

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    
    int n, x;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    cout<<"enter the value of x :"<<endl;
    cin>>x;
    
    //Variable of count required numbers
    int count = 0;
    
    for(int i=1; i<=n; i++){
        
        //variable to count the factors of i-th number
        int count_factors = 0;
        for(int j = 1; j<=sqrt(i); j++){
            if(i%j==0){
                if(i/j != j)
                    count_factors += 2;
                else
                    count_factors++;
            }
        }
        
        if(count_factors == x)
            count++;
    }
    
    cout<<count<<endl;
}