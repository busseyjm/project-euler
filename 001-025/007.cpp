// 10001st prime

// Problem 7

// By listing the first six prime numbers: 
//  2, 3, 5, 7, 11, and 13, 
//  we can see that the 6th prime is 13.

// What is the 10001st prime number?


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

  for (int i=0; i<10000; i++) {
    prime = nextprime(prime);
  }

  cout << prime;

  return 0;
}
