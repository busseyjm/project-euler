// Pandigital products
 
// Problem 32

// We shall say that an n-digit number is pandigital if it makes use of all the 
//  digits 1 to n exactly once; for example, the 5-digit number, 15234, 
//  is 1 through 5 pandigital.

// The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing 
//  multiplicand, multiplier, and product is 1 through 9 pandigital.

// Find the sum of all products whose multiplicand/multiplier/product identity 
//  can be written as a 1 through 9 pandigital.

// HINT: Some products can be obtained in more than one way so be sure to only 
//  include it once in your sum.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

bool pandigital(int a, int b, int c);

int main() {

  Timer t;


  // cout << pandigital(39,186,7254) << endl;

  vector<int> products;
  vector<int>::iterator it;

  for (int i=1; i<1000; i++) {
    for (int j=10; j<10000; j++) {
      if (pandigital(i,j,i*j)) {
        it = find(products.begin(), products.end(), i*j);
        if (it == products.end()) {
          products.push_back(i*j);
          cout << i << "*" << j << "=" << i*j << endl;
        }
      }
    }
  }

  int sum = 0;
  for (int i=0; i<products.size(); i++) {
    sum+=products[i];
  }

  cout << sum << endl;


  t.printms();

  return 0;
}

bool pandigital(int a, int b, int c) {
  bool pand[10] = {0,0,0,0,0,0,0,0,0,0};

  while (a>0) {
    if (pand[a%10]==0) {
      pand[a%10] = 1;
      a /= 10;
    } else {
      return false;
    }
  }

  while (b>0) {
    if (pand[b%10]==0) {
      pand[b%10] = 1;
      b /= 10;
    } else {
      return false;
    }
  }

  while (c>0) {
    if (pand[c%10]==0) {
      pand[c%10] = 1;
      c /= 10;
    } else {
      return false;
    }
  }

  for (int i=1; i<10; i++) {
    if (pand[0] == 1) return false;
    if (pand[i]==0) {
      return false;
    }
  }
  return true;
}
