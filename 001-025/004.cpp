// Largest palindrome product
// Problem 4
// A palindromic number reads the same both ways. 
//  The largest palindrome made from the product of 
//  two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product 
//  of two 3-digit numbers.

//n^2 loop 999 down to 100, then 998 to 100
//display only palindromic products (helper function)

#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../primecheck.hpp"

using namespace std;

bool palindromic(string in);

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();


int main() {
  namespace mp = boost::multiprecision;

  // mp::cpp_int palindromes[7] = { 1, 123, 321, 12321, 1221, 9000009, 131 };

  // for (int i=0; i<7; i++) {
  //   cout << "palindromic(" << palindromes[i] << ")" << endl;
  //   cout << palindromic(palindromes[i].str()) << endl;
  // }

  mp::cpp_int i = 999;
  mp::cpp_int j = 999;
  mp::cpp_int result = 0;

  while (i>700) {
    j=999;
    while (j>700) {
      result = i*j;
      if (palindromic(result.str())) {
        cout << i << "*" << j << "= " << result << endl;
      }
      j--;
    };
    i--;
  };

  cout << "done." << endl;

  return 0;
}


bool palindromic(string in) {
  for (int i=0; i<in.length()/2; i++) {
    if (in[i] != in[in.length()-i-1]) {
      // cout << "str: " << in << endl;
      // cout << "i: " << i << endl;
      // cout << "in[i]: " << in[i] << " ";
      // cout << "in.length()-i-1: " << in.length()-i-1 << endl;
      return false;
    }
  }
  return true;
}