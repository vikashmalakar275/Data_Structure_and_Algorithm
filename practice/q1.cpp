#include <iostream>
using namespace std;

bool isPrime(int n)
{
  int count = 0; 
  for(int i=1;i<=n;i++)
  {
    if(n%i==0)
    {
     count++;
    }
  }
  if(count==2)
  {
   return true;
  }
  return false;
} 

int main()
{
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    cout<<"prime numbers are ";
    for(int i=1;i<=n;i++)
    {
        if(isPrime(i))
        {
            cout<<i<<" ";
        }
    }
}