// Digit fifth powers

// Problem 30

// Surprisingly there are only three numbers that can be written as the 
//  sum of fourth powers of their digits:

//     1634 = 1^4 + 6^4 + 3^4 + 4^4
//     8208 = 8^4 + 2^4 + 0^4 + 8^4
//     9474 = 9^4 + 4^4 + 7^4 + 4^4

// As 1 = 1^4 is not a sum it is not included.

// The sum of these numbers is 1634 + 8208 + 9474 = 19316.

// Find the sum of all the numbers that can be written as the sum of fifth powers 
//  of their digits.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  int sum = 0;

  //there are only 10 digits that can be x for x^5, put them in a table
  int dpow[10];
  for (int i=0; i<10; i++) {
    dpow[i] = pow(i,5);
  }

  //upper bound is 354294, 9^5*6, 9^5*7 (7 digits) is only 6 digits long.
  for (int i=2; i<=354294; i++) {
    int powsum = 0;
    int temp = i;
    do {
      powsum+=dpow[temp%10];
      temp/=10;
    } while (temp > 0);
    if (i == powsum) {
      cout << "found: " << i << endl;
      sum+= i;
    }
  }

  cout << "sum of all possible numbers: " << sum << endl;


  t.printms();

  return 0;
}
