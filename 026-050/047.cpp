// Distinct primes factors

// Problem 47

// The first two consecutive numbers to have two distinct prime factors are:

// 14 = 2 × 7
// 15 = 3 × 5

// The first three consecutive numbers to have three distinct prime factors are:

// 644 = 2² × 7 × 23
// 645 = 3 × 5 × 43
// 646 = 2 × 17 × 19.

// Find the first four consecutive integers to have four distinct prime factors each.
//  What is the first of these numbers?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <algorithm>
#include "../timer.hpp"
#include "../primecheck.hpp"

namespace mp = boost::multiprecision;
using namespace std;

bool consecutiveuniquefactors(int i, int n);

int main() {

  Timer t;



  for (int i=6; i<1000000; i++) {
    // if (consecutiveuniquefactors(i,2)) {
    //   cout << i << " " << 2 << endl;
    //   break;
    // }    
    // if (consecutiveuniquefactors(i,3)) {
    //   cout << i << " " << 3 << endl;
    //   break;
    // }    
    if (consecutiveuniquefactors(i,4)) {
      cout << i << " " << 4 << endl;
      break;
    }
  }



  t.printms();

  return 0;
}

bool consecutiveuniquefactors(int start, int n) {
  vector<int> factors;
  int tempnum;
  int power;
  int factorcount;

  //only want consecutive composite numbers
  
  for (int i=0; i<n; i++) {
    if (primecheck(start+i)) {
      return false;
    }
  }

  //add factors of each number to a vector, if any already exist return false;
  for (int i=0; i<n; i++) {
    tempnum = start+i;
    factorcount = 0;
    for (int i=2; i<=tempnum; i=nextprime(i)) {
      power = 0;
      //if a number is divisible by the prime we're checking (i),
      //  divide out as many as possible to get the power of i
      //  then add the i^x to the table of unique factors (if it is unique)
      if (tempnum%i == 0) {
        if (factorcount==n) return false;
        while (tempnum%i == 0) {
          power++;
          tempnum/=i;
        }
        //if the factor doesn't exist, add it and increment factor counter
        //  if it does exist, not a good number and move on
        if (!binary_search(factors.begin(), factors.end(), pow(i,power))) {
          factors.push_back(pow(i,power));
          sort(factors.begin(), factors.end());
          factorcount++;
        } else {
          return false;
        }
      }
    }
    //if we didn't find exactly n factors, not a good number
    if (factorcount != n) return false;
  }

  return true;
}