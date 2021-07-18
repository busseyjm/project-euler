// Pandigital prime

// Problem 41

// We shall say that an n-digit number is pandigital if it makes 
//  use of all the digits 1 to n exactly once. For example, 2143 is a 
//  4-digit pandigital and is also prime.

// What is the largest n-digit pandigital prime that exists?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include "../primecheck.hpp"

namespace mp = boost::multiprecision;
using namespace std;

bool pandigital_oneton(string a, int n);

int main() {

  Timer t;

  mp::cpp_int largest = 0;


  //a number is divisible by 3 if the sum of its digits are
  //  -> pandigital primes of len 9 or 8 don't exist
  //  1+2+3+4+5+6+7+8+9=45
  //  45-9 = 36
  //  36-8 = 28
  for (mp::cpp_int i=7654337; i>7000000; i=prevprime(i)) {
    if (pandigital_oneton(i.str(), i.str().length())) {
      largest = i;
      break;
    }
  }

  cout << largest << endl;


  t.printms();

  return 0;
}

bool pandigital_oneton(string a, int n) {
  if (a.length() != n)  return false;

  bool pand[n+1];
  for (int i=0; i<=n; i++) {
    pand[i] = 0;
  }

  for (int i=0; i<n; i++) {
    pand[int(a[i])-48] = 1;
  }

  for (int i=1; i<=n; i++) {
    if (pand[0] == 1) return false;
    if (pand[i]==0) {
      return false;
    }
  }

  return true;
}