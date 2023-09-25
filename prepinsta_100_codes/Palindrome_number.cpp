/*
Palindrome or not
A number is a Palindrome number if the reverse of the number and the numbers itself are equal i.e. if the number and its reverse are the same then a number is a palindrome number.

Example :
Number : 12321
Reverse : 12321

Both number & reverse are equal so palindrome number.
*/
#include <iostream>

using namespace std;

int main()
{
    int number;
    cout<<"Enter the number :"<<endl;
    cin>>number;
    int num = number;
    int reverse = 0;
    while(number>0)
    {
        int rem = number%10;
        reverse = reverse*10 + rem;
        number = number/10;
    }

    if(num == reverse)
    {
        cout<<num<<" is Plaindrome Number. "<<endl;
    }
    else
    {
        cout<<num<<" is Not Plaindrome Number. "<<endl;
    }
    return 0;
}