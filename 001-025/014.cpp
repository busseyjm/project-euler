// Longest Collatz sequence

// Problem 14

// The following iterative sequence is defined for the set of positive integers:

// n → n/2 (n is even)
// n → 3n + 1 (n is odd)

// Using the rule above and starting with 13, we generate the following sequence:
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

// It can be seen that this sequence (starting at 13 and finishing at 1) 
//  contains 10 terms. Although it has not been proved yet (Collatz Problem), 
//  it is thought that all starting numbers finish at 1.

// Which starting number, under one million, produces the longest chain?

// NOTE: Once the chain starts the terms are allowed to go above one million.

#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();
mp::cpp_int collatz(mp::cpp_int);

int main() {

  int sequencestart = 1;
  int sequencelegth = 1;

  for (int i=2; i<1000000; i++) {
    int curlength = 1;
    mp::cpp_int cur = i;
    // cout << "trying " << i << endl;
    while (cur!=1) {
      curlength++;
      // cout << cur << endl;
      cur = collatz(cur);
    }
    if (curlength>sequencelegth) {
      sequencestart = i;
      sequencelegth = curlength;
      cout << "newest start: " << sequencestart;
      cout << " len: " << sequencelegth << endl;
    }
  }


  return 0;
}

mp::cpp_int collatz(mp::cpp_int c) {
  if (c%2==0) {
    return (c/2);
  } else {
    return (3*c+1);
  }
}