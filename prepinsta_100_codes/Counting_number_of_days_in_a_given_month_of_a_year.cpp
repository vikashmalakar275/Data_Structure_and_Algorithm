/*
Number of days in a given month of a given year in C++
 
Number of days in any month of a year can vary specifically in February as the cycle of leap year repeats in every 4 years when the year is leap February gives the count to 29 days but the when the year is not leap it gives count to 28 days and so no of days in a year varies from 365 to 366. 
Rather than February every month gives the count of 30 or 31 days in any case whether the year is a leap or not.
*/

#include <iostream>
using namespace std;

int main()
{
    
    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month , year;
    cout<<"Enter the month : "<<endl;
    cin>>month;
    cout<<"Enter the month : "<<endl;
    cin>>year;
    
    //For checking leap year
    if(month==2 && ((year%400==0) || ((year%100!=0)&&(year%4==0))))
        cout<<"Number of days is "<< arr[month-1]+1<<endl;
    
    else cout<<"Number of days is "<<arr[month-1]<<endl;
   
    
    return 0;
}