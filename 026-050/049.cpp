// Prime permutations

// Problem 49

// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms 
//  increases by 3330, is unusual in two ways: (i) each of the three terms 
//  are prime, and, (ii) each of the 4-digit numbers are permutations of 
//  one another.

// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit 
//  primes, exhibiting this property, but there is one other 4-digit 
//  increasing sequence.

// What 12-digit number do you form by concatenating the three terms in 
//  this sequence?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include "../primecheck.hpp"
#include "../pandigitals.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  //first 4 digit prime is 1009
  //all 3 terms in the sequence need to be 4 digits
  for (int i=1009; i<10000; i=nextprime(i)) {
    for (int j=1; j<10000; j++) {
      if (!is_intpermutation(i, i+j)) continue;
      if (!is_intpermutation(i, i+2*j)) continue;
      if ((i+j)%2==0) continue;
      if ((i+2*j)%2==0) continue;
      if (!primecheck(i+j)) continue;
      if (!primecheck(i+2*j)) continue;
      cout << i << " " << i+j << " " << i+2*j << endl;
    }
  }


  t.printms();

  return 0;
}
