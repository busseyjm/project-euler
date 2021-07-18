// Digit factorials

// Problem 34

// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

// Find the sum of all numbers which are equal to the sum of the factorial 
//  of their digits.

// Note: As 1! = 1 and 2! = 2 are not sums they are not included.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

bool digitsarefactorialsum(int a);

int factorials[10] = {
  1,
  1,
  2,
  6,
  24,
  120,
  720,
  5040,
  40320,
  362880
};

int main() {

  Timer t;

  //no idea how to get the upper bound for this problem :(
  for (int i=3; i<100000000; i++) {
    if (digitsarefactorialsum(i)) {
      cout << i << endl;
    }
  }

  // cout << digitsarefactorialsum(145) << endl;


  t.printms();

  return 0;
}

bool digitsarefactorialsum(int a) {
  int original = a;
  int sum = 0;
  while (a>0) {
    sum+=factorials[a%10];
    a/=10;
    if (sum>original) return false;
  }
}