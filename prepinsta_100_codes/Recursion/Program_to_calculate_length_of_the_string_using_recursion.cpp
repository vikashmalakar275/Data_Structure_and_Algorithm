/*

*/

#include <iostream>

using namespace std;

int lengthString(string str)
{
    if(str.empty())
    {
        return 0;
    }
    return 1 +lengthString(str.substr(1));
}

int main()
{
    string str;
    cout<<"enter the string :"<<endl;
    getline(cin,str);
    cout<<"String = "<<str<<endl;
    int length = lengthString(str);
    cout<<"Length of String = "<<length<<endl;
    return 0;
}