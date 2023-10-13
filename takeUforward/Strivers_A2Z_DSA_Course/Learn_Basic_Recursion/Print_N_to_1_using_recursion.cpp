/*
Problem: Print from N to 1 using Recursion

Since in this problem, there is no global variable that can be decremented each time we call a function, how can we keep a track of the number of integers being printed on the output screen?

For this problem, we’re going to be using a function along with parameters that get decremented with each function call through which we can keep track of the integer count while printing. To understand this problem better, let us see the pseudocode below for this : 

void func( i, n )
{
   if(i<1) return;
 print(i);
   f( i-1,N );
}
main()
{
  int n;
  input(n);
  f(n,n);
}


Alternate Approach for printing integers from N to 1 (using Backtracking)

This is an alternative approach for printing the integers from N to 1 using recursion. In the previous approach, we used forward recursion but in this approach, we will be using backward recursion. The only change from the previous approach here will be that the print line would be kept after the function call inside the recursive function contrary to the previous approach. The function would be called for printing (i+1) integers and the ith integer would be printed.

To get a clear understanding of what this approach is like let’s see the pseudocode for this : 

void func( i, n )
{
   if(i>n) return;
 f( i+1,N );
print(i);

}
main()
{
  int n;
  input(n);
  f(1,n);
}
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
    cout<<n<<" ";
    print(n-1);
}

int main()
{
    int number;
    cout<<"Enter the number :"<<endl;
    cin>>number;
    print(number);
}