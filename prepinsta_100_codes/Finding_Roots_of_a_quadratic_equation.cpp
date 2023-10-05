/*
Program to find roots of a quadratic equation in C++
Here we will discuss how to find the roots of a quadratic equation using the C++ programming language. An equation is said to be a quadratic equation if it’s in the form, ax^2+bx+c = 0 (where a!= 0).

 

Roots of a quadratic equation in C++
Algorithm
Let’s see how the code works:

The discriminant is found, d = b*b – 4*a*c
If d is greater than 0, real and different roots are found, root1 = (-b + sqrt(d)) / (2*a) and root2 = (-b – sqrt(d)) / (2*a);
If d is less than 0, complex(imaginary) roots are found, real = -b/(2*a) and imaginary =sqrt(-d)/(2*a);
If d is equal to 0 then real and equal roots are found, root1 = (-b + sqrt(d)) / (2*a);
*/

#include <iostream>

using namespace std;

int main()
{
    float a,b,c;
    cout<<"enter the value of 'a' :"<<endl;
    cin>>a;
    cout<<"enter the value of 'b' :"<<endl;
    cin>>b;
    cout<<"enter the value of 'c' :"<<endl;
    cin>>c;
    cout<<"Quadratic Equation : "<<a<<"*X^2 + "<<b<<"*X + "<<c<<endl;
    float d = b*b - 4*a*c;
    if(d>0)
    {
        float root1 = (-b + sqrt(d)) / (2*a);
        float root2 = (-b - sqrt(d)) / (2*a);

        cout<<"Real and different roots are found : \nRoot1 = "<<root1<<"\nRoot2 = "<<root2<<endl;
    }
    else if(d<0)
    {
        float real = -b/(2*a);
        float img = sqrt(-d) / (2*a);

        cout<<"Complex(Imaginary) roots are found : \nReal = "<<real<<"\nImaginary = "<<img<<endl;
    }
    else if(d == 0)
    {
        float root = (-b + sqrt(d)) / (2*a);

        cout<<"Real and Equal roots are found : \nRoot = "<<root<<endl;

    }

    return 0;
}