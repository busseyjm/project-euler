// Special Pythagorean triplet
// Problem 9

// A Pythagorean triplet is a set of three natural numbers, 
//  a < b < c, for which a^2 + b^2 = c^2

// For example, 32 + 42 = 9 + 16 = 25 = 52.

// There exists exactly one Pythagorean triplet for which 
//  a + b + c = 1000.
// Find the product abc.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();


int main() {
  namespace mp = boost::multiprecision;

  //zug zug no thinking brute force solution
  for (int c=1; c<1000; c++) {
    for (int b=1; b<c; b++) {
      for (int a=1; a<b; a++) {
        if ((pow(a,2)+pow(b,2))==pow(c,2)) {
          if (a+b+c==1000) {
            cout << a << "^2+" << b << "^2=" << c <<"^2" << endl;
            // 200^2+375^2=425^2
          }
        }
      }
    }
  }



  return 0;
}
