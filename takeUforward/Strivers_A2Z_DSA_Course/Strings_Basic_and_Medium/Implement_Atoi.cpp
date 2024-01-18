/*
The atoi() function in C takes a string (which represents an integer) as an argument and returns its value of type int. So basically the function is used to convert a string argument to an integer.

Syntax of atoi()
int atoi(const char strn);
Parameters
The function accepts one parameter strn which refers to the string argument that is needed to be converted into its integer equivalent.
Return Value
If strn is a valid input, then the function returns the equivalent integer number for the passed string number.
If no valid conversion takes place, then the function returns zero.
*/
#include <iostream>
using namespace std;

//Time Complexity: O(n), Only one traversal of the string is needed.
//Space Complexity: O(1), As no extra space is required.
int implement_atoi_1(char *str)
{
    return atoi(str);
}

//Time Complexity: O(n), Only one traversal of the string is needed.
//Space Complexity: O(1), As no extra space is required.
int implement_atoi_2(char *str)
{
    int res = 0;
    for(int i=0;str[i] != '\0';++i)
    {
        res = res*10 + str[i] - '0';
    }
    return res;
}

//Time Complexity: O(n), Only one traversal of the string is needed.
//Space Complexity: O(1), As no extra space is required.
int implement_atoi_3(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    if(str[0] == '-')
    {
        sign = -1;
        i++;
    }
    for(;str[i] != '\0';i++)
    {
        res = res*10 + str[i] - '0';
    }
    return sign*res;
}

//Time Complexity: O(n), Only one traversal of the string is needed.
//Space Complexity: O(1), As no extra space is required.
int implement_atoi_4(const char* str)
{
    int sign = 1,base = 0,i=0;

    while(str[i] == ' ')
    {
        i++;
    }
    if(str[i] == '-' || str[i] == '+')
    {
        sign = 1 - 2 * (str[i++] == '-');
    }
    while(str[i]>='0' && str[i] <= '9')
    {
        if(base>INT_MAX/10 || (base == INT_MAX/10 && str[i] - '0'>7))
        {
            if(sign == 1)
            {
                return INT_MAX;
            }
            else
            {
                return INT_MAX;
            }
        }
        base = 10*base + (str[i++] - '0');
    }
    return base*sign;
}

int main()
{
    const int maxSize = 100;
    char str[maxSize];
    cout<<"Enter the string :"<<endl;
    cin.getline(str,maxSize);

    int val1 = implement_atoi_1(str);
    cout<<"Value = "<<val1<<endl;

    int val2 = implement_atoi_2(str);
    cout<<"Value = "<<val2<<endl;

    int val3 = implement_atoi_3(str);
    cout<<"Value = "<<val3<<endl;

    int val4 = implement_atoi_4(str);
    cout<<"Value = "<<val4<<endl;
}