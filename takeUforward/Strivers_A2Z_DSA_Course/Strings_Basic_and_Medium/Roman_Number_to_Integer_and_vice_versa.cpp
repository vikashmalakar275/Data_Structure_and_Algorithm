/*
Given a Roman numeral, the task is to find its corresponding decimal value.

Example : 

Input: IX
Output: 9
Explanation: IX is a Roman symbol which represents 9

Input: XL
Output: 40
Explanation: XL is a Roman symbol which represents 40

Input: MCMIV
Output: 1904
Explanation: M is a thousand, CM is nine hundred and IV is four
*/

#include <iostream>
using namespace std;

//Time Complexity: O(n), where n is the length of the string. 
//Only one traversal of the string is required.
//Auxiliary Space: O(1), As no extra space is required.
int value(char r)
{
    if(r== 'I')
    {
        return 1;
    }
    if(r == 'V')
    {
        return 5;
    }
    if(r == 'X')
    {
        return 10;
    }
    if(r == 'L')
    {
        return 50;
    }
    if(r == 'C')
    {
        return 100;
    }
    if(r == 'D')
    {
        return 500;
    }
    if(r == 'M')
    {
        return 1000;
    }
    return -1;
}

int roman_to_int(string str)
{
    int res = 0;
    for(int i=0;i<str.length();i++)
    {
        int s1 = value(str[i]);
        if(i+1 < str.length())
        {
            int s2 = value(str[i+1]);
            if(s1 >= s2)
            {
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++;
            }
        }
        else
        {
            res = res + s1;
            i++;
        }
    }
    return res;
}

int main()
{
    string str;
    cout<<"Enter the Roman Number :"<<endl;
    getline(cin,str);
    cout<<"Roman to Int = "<<roman_to_int(str)<<endl;
}