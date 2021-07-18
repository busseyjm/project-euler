// Lattice paths
 
// Problem 15

// Starting in the top left corner of a 2×2 grid, 
//  and only being able to move to the right and down, 
//  there are exactly 6 routes to the bottom right corner.

// How many such routes are there through a 20×20 grid?

// this problem is just orderings of strings,
// treat right movements as one letter, down movements as another
// 2x2: AABB orderings -> 6 orderings = 4! / (2!*2!)
// 20x20 AAAA...ABBBB...B (20xA, 20xB) = 40! / (20!*20!)

#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/special_functions/factorials.hpp>

namespace mp = boost::multiprecision;
using namespace std;

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();
mp::cpp_int fact(int);

int main() {
  mp::cpp_int fac1 = fact(40);
  mp::cpp_int fac2 = fact(20);

  mp::cpp_int result = fac1 / (fac2*fac2);

  cout << result << endl;

  return 0;
}

mp::cpp_int fact(int i) {
  mp::cpp_int result = i;
  while (i>1) {
    result *= --i;
  }
  return result;
}