// Factorial digit sum

// Problem 20

// n! means n × (n − 1) × ... × 3 × 2 × 1

// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

// Find the sum of the digits in the number 100!


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/special_functions/factorials.hpp>

namespace mp = boost::multiprecision;
using namespace std;

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();
mp::cpp_int fact(int);

int main() {
  mp::cpp_int fac = fact(100);
  mp::cpp_int digsum = 0;

  cout << fac << endl;

  while (fac>0) {
    digsum += fac%10;
    fac /= 10;
  }


  cout << digsum << endl;

  return 0;
}

mp::cpp_int fact(int i) {
  mp::cpp_int result = i;
  while (i>1) {
    result *= --i;
  }
  return result;
}