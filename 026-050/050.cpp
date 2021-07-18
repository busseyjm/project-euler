// Consecutive prime sum

// Problem 50

// The prime 41, can be written as the sum of six consecutive primes:
// 41 = 2 + 3 + 5 + 7 + 11 + 13

// This is the longest sum of consecutive primes that adds to a prime 
//  below one-hundred.

// The longest sum of consecutive primes below one-thousand that adds 
//  to a prime, contains 21 terms, and is equal to 953.

// Which prime, below one-million, can be written as the sum of the 
//  most consecutive primes?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include "../primecheck.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  vector<int> primetable;

  //table all the primes from 2 to 1m
  for (int i=2; i<1000000; i=nextprime(i)) {
    primetable.push_back(i);
  }

  mp::cpp_int largest = 0;
  int len = 0;
  int longest = 0;
  mp::cpp_int sum = 0;

  //sum primes in a moving window from 1 to n
  //if the sum is larger than we want just move on
  //keep track of the longest prime every loop
  for (int i=0; i<primetable.size(); i++) {
    for (int j=i+1; j<primetable.size(); j++) {
      sum = 0;
      len = j-i+1;
      if (len < longest) continue;
      for (int k=i; k<=j; k++) {
        sum += primetable[k];
      }
      if (primecheck(sum) && (len > longest)) {
      // if (primecheck(sum)) {
        if (sum<1000000) {
          cout << "i: " << i << " j: " << j << " ";
          cout << sum <<" j-i+1:" << j-i+1 << " longest: " << longest << endl;
          longest = len;
          largest = sum;
        } else {
          break;
        }
      }
    cout << "i: " << i << "j: " << j << endl;
    }
  }


  cout << largest << " " << longest << endl;

  t.printms();

  return 0;
}
