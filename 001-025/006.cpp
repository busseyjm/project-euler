// Sum square difference

// Problem 6

// The sum of the squares of the first ten natural numbers is,
//  1^2 + 2^2 + ... + 10^2 = 385

// The square of the sum of the first ten natural numbers is,
//  (1 + 2 + ... + 10)^2 = 55^2 = 3025

// Hence the difference between the sum of the squares 
//  of the first ten natural numbers and the square of 
//  the sum is 3025-385=2640

// Find the difference between the sum of the 
//  squares of the first one hundred natural numbers 
//  and the square of the sum.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();


int main() {
  namespace mp = boost::multiprecision;

  mp::cpp_int sumofsquared = 0;
  mp::cpp_int squaredsums = 0;

  for (int i=0; i<101; i++) {
    sumofsquared += mp::pow(mp::cpp_int(i),2);
    squaredsums += i;
  }
  squaredsums = mp::pow(squaredsums, 2);

  cout << (squaredsums - sumofsquared) << endl;

  return 0;
}
