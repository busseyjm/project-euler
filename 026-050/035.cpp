// Circular primes


// Problem 35

// The number, 197, is called a circular prime because all rotations of 
//  the digits: 197, 971, and 719, are themselves prime.

// There are thirteen such primes below 100: 
//  2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

// How many circular primes are there below one million?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include "../primecheck.hpp"
#include "../rotatenumbers.hpp"

bool circularprime(int a);

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  int count=0;

  for (int i=2; i<1000000; i=nextprime(i)) {
    if (circularprime(i)) {
      count++;
    }
  }

  cout << count << endl;


  t.printms();

  return 0;
}

bool circularprime(int a) {
  int len = intlength(a);

  if (!primecheck(a)) return false;

  for (int i=0; i<len; i++) {
    a = rotateright(a);
    if (!primecheck(a)) return false;
  }

  return true;
}