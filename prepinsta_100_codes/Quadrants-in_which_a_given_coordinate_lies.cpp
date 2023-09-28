/*
Quadrants in which coordinate lies in C
Here, we will discuss the program for Quadrants In Which Coordinates Lie in C. The C program reads the coordinate point in a x-y coordinate system and identify the quadrant. The program takes X and Y. On the basis of x and y value, the program will identify on which quadrant the point lies.

Shortest Job First Scheduling Non Preemptive
While loop in C
Working :
According mathematics quadrants rules:

X  is positive integer as well as Y is also positive a integer it signifies first quadrant.
X  is negative integer but Y is positive integer it signifies second quadrant.
X  is negative integer as well as Y is also negative integer it signifies third quadrant.
X  is positive integer but Y is negative integer it signifies fourth quadrant.
Algorithm :
Get value of x & y
If ( x>0 and y>0 ) First Quadrant
If ( x<0 and y>0 ) Second Quadrant
If ( x<0 and y<0 ) Third Quadrant
If ( x>0 and y>0 ) Fourth Quadrant
If ( x=0 and y=0 ) Origin
If ( x!=0 and y=0 ) x-axis
If ( x>0 and y>0 ) y-axis
*/
#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout<<"Enter the X-Point : "<<endl;
    cin>>x;
    cout<<"Enter the Y-Point :"<<endl;
    cin>>y;
    if(x>0 && y>0)
    {
        cout<<"("<<x<<","<<y<<")"<<" lies in First Quadrant"<<endl;
    }
    else if(x<0 && y>0)
    {
        cout<<"("<<x<<","<<y<<")"<<" lies in Second Quadrant"<<endl;
    }
    else if(x<0 && y<0)
    {
        cout<<"("<<x<<","<<y<<")"<<" lies in Third Quadrant"<<endl;
    }
    else if(x>0 && y<0)
    {
        cout<<"("<<x<<","<<y<<")"<<" lies in Fourth Quadrant"<<endl;
    }
    else if(x!=0 && y==0)
    {
        cout<<"("<<x<<","<<y<<")"<<" lies on X-axis"<<endl;
    }
    else if(x==0 && y!=0)
    {
        cout<<"("<<x<<","<<y<<")"<<" lies on Y-axis"<<endl;
    }
    return 0;
}