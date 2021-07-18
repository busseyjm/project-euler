// Champernowne's constant


// Problem 40

// An irrational decimal fraction is created by concatenating the positive integers:

// 0.123456789101112131415161718192021...

// It can be seen that the 12th digit of the fractional part is 1.

// If dn represents the nth digit of the fractional part, find the value of 
//  the following expression.

// d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  string bstr = "";
  //200000 generates a string of length 1088890, close enough
  for (mp::cpp_int i=0; i<200000; i++) {
    bstr += i.str();
  }

  // cout << "length: " << bstr.length() << "\n";

  int out = 1;
  for (int i=0; i<=6; i++) {
    out*= (bstr[int(pow(10,i))]-48);
  }

  cout << out << endl;

  t.printms();

  return 0;
}
