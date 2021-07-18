// Summation of primes 
// Problem 10

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

// Find the sum of all the primes below two million.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../primecheck.hpp"

using namespace std;
//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();


int main() {
  namespace mp = boost::multiprecision;

  mp::cpp_int prime = 2;
  mp::cpp_int sum = 0;

  while (prime<2000000) {
    sum += prime;
    prime = nextprime(prime);
  }

  cout << sum << endl;

  return 0;
}
