// Truncatable primes

// Problem 37

// The number 3797 has an interesting property. Being prime itself, 
//  it is possible to continuously remove digits from left to right,
//  and remain prime at each stage: 3797, 797, 97, and 7. Similarly we 
//  can work from right to left: 3797, 379, 37, and 3.

// Find the sum of the only eleven primes that are both truncatable from 
//  left to right and right to left.

// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include "../rotatenumbers.hpp"
#include "../primecheck.hpp"

namespace mp = boost::multiprecision;
using namespace std;

bool truncatable(int a);

int main() {

  Timer t;

  int count = 0;
  int sum = 0;

  //2,3,5,7 are not considered truncatable, skip them
  int prime = 11;

  // there are only 11 truncatable primes from both directions
  while (count<11) {
    // cout << prime << endl;
    if (truncatable(prime)) {
      count++;
      sum+=prime;
      cout << "Found " << prime << " is truncatable from both directions." << endl;
    }
    prime = nextprime(prime);
  }

  // cout << truncatable(3797) << endl;

  cout << sum << endl;

  t.printms();

  return 0;
}

bool truncatable(int a) {
  if (!primecheck(a)) return false;
  int len = intlength(a);

  int l = a;
  int r = a;

  for (int i=0; i<len-1; i++) {
    l = truncleft(l);
    if (!primecheck(l)) return false;

    r = truncright(r);
    if (!primecheck(r)) return false;
  }

  return true;
}
