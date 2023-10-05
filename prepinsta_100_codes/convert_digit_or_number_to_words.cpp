/*
Converting digit/number to words in C++
Here, in this page we will discuss the program for Digit/number to words in C++ .The conversion of numbers in words is just a conversion of numeric values to the English format of reading numbers. This code supports the conversion of numbers from 0 – 9999 in English format. 
Digits have different places when read from its ones place to above.
*/

#include <iostream>

using namespace std;


void numToWords (string num)
{
    int length_of_string = num.size ();
    if (length_of_string == 0)
    {
        cout << "String is Empty"<<endl;
        return;
    }
    if (length_of_string > 4)
    {
        cout << "Please enter the string with supported length"<<endl;
        return;
    }
    string ones_digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine"};
    string tens_digits[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
    string multiple_of_ten[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy","eighty", "ninety"};
    string power_of_ten[] = {"hundred", "thousand"};
    cout << num << ": ";
    if (length_of_string == 1)
    {
        cout << ones_digits[num[0] - '0'];
    }
    int x = 0;
    while (x < num.size ())
    {
      if (length_of_string >= 3)
      {
        if (num[x] - 48 != 0)
	    {
            cout << ones_digits[num[x] - 48]<<" ";
            cout << power_of_ten[length_of_string - 3] << " ";
            length_of_string--;
        }
      }  
      else
      {
        if (num[x] - 48 == 1)
	    {
            int sum = (num[x] - 48 + num[x] - 48);
            cout << tens_digits[sum];
	    }
        else if (num[x] - 48 == 2 and num[x + 1] - 48 == 0)
	    {
            cout << "twenty";
            return;
	    }
        else
	    {
            int i = num[x] - 48;
            if (i > 0)
            {
                cout << multiple_of_ten[i] << " ";
            }
            else
            {
                cout << " ";
            }
            x += 1;
            if (num[x] - 48 != 0)
            {
                cout << ones_digits[num[x] - 48];
            }
        }
      }
      x++;
    }
    cout<<endl;
}


int main ()
{
    string n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    numToWords (n);
    return 0;
}