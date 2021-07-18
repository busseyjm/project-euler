// Lexicographic permutations

// Problem 24

// A permutation is an ordered arrangement of objects. For example,
//  3124 is one possible permutation of the digits 1, 2, 3 and 4. 
//  If all of the permutations are listed numerically or alphabetically,
//  we call it lexicographic order. The lexicographic permutations of 
//  0, 1 and 2 are:

// 012   021   102   120   201   210

// What is the millionth lexicographic permutation of the digits 
//  0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <algorithm>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();

int main() {

  int digits[] = {0,1,2,3,4,5,6,7,8,9};

  Timer t;

  
  //https://www.cplusplus.com/reference/algorithm/next_permutation/
  for (int i=0; i<999999; i++) {
    next_permutation(digits,digits+10);
  }

  for (int i=0; i<10; i++) {
    cout << digits[i];
  }
  cout << endl;

  t.stop();
  t.printms();

  return 0;
}
