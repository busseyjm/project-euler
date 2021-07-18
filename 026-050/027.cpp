//https://projecteuler.net/problem=27
//Lots of math symbols that will not copy easily.

#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include "../primecheck.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  int maxprimes = 0;
  int maxa = 0;
  int maxb = 0;

  //brute force
  //1+a+b must be odd, and b must be odd (since b must be prime), so a must be odd
  //  (b=2's sequences are not long enough to be consequential)
  for (int a=-999; a<1000; a+=2) {

    //primes can't be negative and since the first term
    //  begins at n=0; b MUST be prime;
    for (int b=2; b<=1000; b=nextprime(b)) {
      //if n=1 is prime then we have the beginning of a sequence
      if (primecheck(1+a+b)) {
        int seqlen = 2;
        int n = 2;

        while (primecheck( (pow(n,2) + (n*a) + b) )) {
          seqlen++;
          n++;
        }

        if(seqlen > maxprimes) {
          maxprimes = seqlen;
          maxa = a;
          maxb = b;
          cout << "new max length sequence: " << maxprimes;
          cout << " a: " << a;
          cout << " b: " << b;
          cout << endl;
        }
      }

    }
  }






  t.printms();

  return 0;
}
