// Largest prime factor
// Problem 3
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?



#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../primecheck.hpp"

using namespace std;
//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();


//600851475143


int main() {
  namespace mp = boost::multiprecision;

  // for (mp::cpp_int i = 3; i<(600851475143/2); i++) {
  //   if (600851475143 % i == 0) {
  //     cout << (i);
  //     if (primecheck(i)) cout << " p";
  //     cout << endl;
  //   }
  // }

  mp::cpp_int beginningnum = 600851475143;
  mp::cpp_int factored = beginningnum;
  mp::cpp_int prime = 2;
  mp::cpp_int factorpower = 0;

  cout << "factorizing " << beginningnum << endl;

  while(1) {
    factorpower = 0;
    if (primecheck(factored)) {
      cout << factored << "^" << 1 << endl;
      break;
    }
    while (factored%prime == 0) {
      factorpower++;
      factored = factored / prime;
      //cout << factored << endl;
    }


    if (factorpower > 0) {
      cout << prime << "^" << factorpower << "  *  ";
    }

    prime = nextprime(prime);
    // if (prime > mp::sqrt(beginningnum)) break;
    if (prime > beginningnum) break;
  }


  return 0;
}
