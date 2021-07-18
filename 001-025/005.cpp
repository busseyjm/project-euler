// Smallest multiple 
// Problem 5
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../primecheck.hpp"

using namespace std;
//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();


int main() {
  namespace mp = boost::multiprecision;

  //largest powers of prime factorizations of factors of 20
  for (mp::cpp_int i=232792560; i<1000000000; i++) {
    
    bool divisible = true;
    for (int j=1; j<21; j++) {
      if (i%j!=0) {
        divisible = false;
        break;
      }
    }
    if (divisible) {
      cout << "Smallest number divisible is: " << i << endl;
      break;
    }
  }


  return 0;
}
