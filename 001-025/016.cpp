// Power digit sum

// Problem 16

// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

// What is the sum of the digits of the number 2^1000?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();

int main() {
  mp::cpp_int largepower = mp::pow(mp::cpp_int(2), 1000);
  mp::cpp_int digitsums = 0;

  for (int i=0; i<1000; i++) {
    digitsums += largepower%10;
    largepower/=10;
  }

  cout << digitsums << endl;

  return 0;
}
