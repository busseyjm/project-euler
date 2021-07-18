// Reciprocal cycles

// Problem 26

// A unit fraction contains 1 in the numerator. The decimal 
//  representation of the unit fractions with denominators 
//  2 to 10 are given:

//     1/2	= 	0.5
//     1/3	= 	0.(3)
//     1/4	= 	0.25
//     1/5	= 	0.2
//     1/6	= 	0.1(6)
//     1/7	= 	0.(142857)
//     1/8	= 	0.125
//     1/9	= 	0.(1)
//     1/10	= 	0.1 

// Where 0.1(6) means 0.166666..., and has a 1-digit recurring 
//  cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

// Find the value of d < 1000 for which 1/d contains the longest 
//  recurring cycle in its decimal fraction part.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "../timer.hpp"
#include "../primecheck.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int decperiod(int n);
int recipperiodlength(int den);

int main() {

  Timer t;

  int maxperiod = 1;
  int maxindex = 0;

  for (int i=1; i<1000; i++) {
    if (recipperiodlength(i)>maxperiod) {
      maxperiod = recipperiodlength(i);
      maxindex = i;
      cout << i << " " << recipperiodlength(i) << endl;
    }
  }


  t.printms();

  return 0;
}


//a repeatend of a repeating decimal is repeating when
//  the remainders of any given step of long division reoccurs

//i store all the remainders from each step of long division, when one
//  reoccurs, the length of the remainder list is the length of the
//  repeatend

//this function is VERY focused, ONLY works for reciprocals.
int recipperiodlength(int den) {
  int num = 1;

  vector<int> remainders;
  vector<int>::iterator it;

  //all rational numbers either repeat or terminate
  while(1) {
    if (num < den) num*=10;
    if (num%den==0) return 0; //terminates

    //if we have seen a remainder before, then the repeatend is repeating
    it = find(remainders.begin(), remainders.end(), num%den);
    if (it != remainders.end()) {
      return remainders.size();
    }

    //if we reach this point then we haven't seen the remainder before
    //  track it and move forward in the division
    remainders.push_back(num%den);
    num = num%den;
  }
}

