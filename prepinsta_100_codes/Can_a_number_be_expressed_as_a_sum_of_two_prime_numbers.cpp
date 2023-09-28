/*
C++ Program to check whether a number be expressed as a sum of two prime numbers
Number be expressed as a sum of two prime numbers in C++
Program to check whether a number be expressed as a sum of two prime numbers
Prime number is a number which only have two divisors i.e. a number which can not be divided by any other number other than 1 or itself is a prime number. Here we will check for all the numbers if they can be expressed as sum of two primes or not.

Theory
 There are many theories which express numbers as a sum of two primes like Goldbach’s Conjecture which states that any even number greater than 2 can be   expressed as a sum of two primes.

 Prime number is a number which only have two divisors i.e. a number which can not be divided by any other number other than 1 or itself is a prime number.

 Here we will check for all the numbers if they can be expressed as sum of two primes or not.

Algorithm
Take number as input from user.
Input is stored in an int type variable say num 
A loop is started from i = 1 and will work till  i <= num/2
Every value of i is checked for being a prime number.
If i is a prime number then num – i is checked for being a prime.
If both are prime then print the result
Otherwise num cannot be expressed as a sum of two prime numbers.
*/
#include <iostream>
using namespace std;
bool prime_or_not(int a);
int main() {
  int a, i;
  bool flag = false;
  cout << "Enter a positive  integer: ";
  cin >> a;
  for(i = 2; i <= a/2; ++i) {
    if (prime_or_not(i)) {
      if (prime_or_not(a - i)) {
        cout << a << " = " << i << " + " << a-i << endl;
        flag = true;
      }
    }
  }
  if (!flag)
    cout << a << " can't be expressed as sum of two prime numbers.";
  return 0;
}
bool prime_or_not(int a) {
  int i;
  bool is_prime = true;
  if (a == 0 || a == 1) {
    is_prime = false;
  }
  for(i = 2; i <= a/2; ++i) {
    if(a % i == 0) {
      is_prime = false;
      break;
    }
  }
  return is_prime;
}