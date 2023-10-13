/*
Problem: Print from 1 to N using Recursion

Since in this problem, there is no global variable that can be incremented each time we call a function, how can we keep a track of the number of integers being printed on the output screen?

For this problem, we’re going to be using a function along with parameters that get incremented with each function call through which we can keep track of the integer count while printing. To understand this problem better, let us see the pseudocode below for this : 

void func( i, n )
{
   if(i>n) return;
 print(i);
   f( i+1,N );
}
main()
{
  int n;
  input(n);
  f(1,n);
}
We can clearly see in this pseudocode that we first call the function when the value of i is 1 and then print the value of i and increment i by 1 inside the parameter of the function and make a call again. But, we know that this will go on forever as i will be increasing continuously after every function call. So, to avoid this we put a base condition that if i exceeds n, then simply terminate the current recursive call and return to the previous call.

In this way, all the integers from 1 to N would get printed and as soon as we exceed the count of printing by n, the function terminates.
Alternate Approach for printing integers from 1 to N (using Backtracking)

This is an alternative approach for printing the integers from 1 to N using recursion. In the previous approach, we used forward recursion but in this approach, we will be using backward recursion. The only change from the previous approach here will be that the print line would be kept after the function call inside the recursive function contrary to the previous approach. The function would be called for printing (i-1) integers and the nth integer would be printed.

To get a clear understanding of what this approach is like let’s see the pseudocode for this :

void func( i, n )
{
   if(i<1) return;
 f( i-1,N );
print(i);

}
main()
{
  int n;
  input(n);
  f(n,n);
}
We can clearly see in this pseudocode that we first call the function when the value of i is N and then make a call again inside this function for printing (n-1) integers and after this we print N. But, we know that this will go on forever as i will be decreasing continuously after every function call. So, to avoid this we put a base condition that if i is less than n, then simply terminate the current recursive call and return to the previous call.

In this way, all the integers from 1 to N would get printed and as soon as i becomes less than n, the function call terminates.
*/

#include <iostream>
using namespace std;

//TC = O(n)
//SC = O(1)
void print(int n)
{
    if(n<1)
    {
        return;
    }
    print(n-1);
    cout<<n<<" ";
}

int main()
{
    int number;
    cout<<"Enter the number :"<<endl;
    cin>>number;
    print(number);
}