// Digit cancelling fractions

// Problem 33

// The fraction 49/98 is a curious fraction, as an inexperienced mathematician 
//  in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which 
//  is correct, is obtained by cancelling the 9s.

// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

// There are exactly four non-trivial examples of this type of fraction, 
//  less than one in value, and containing two digits in the numerator and
//  denominator.

// If the product of these four fractions is given in its lowest common terms, 
//  find the value of the denominator.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  for (int den=12; den<=99; den++) {
    //skip denominators with equal digits
    if ((den%10)==(den/10)) continue;
    for (int num=10; num<den; num++) {
      //skip numerators with equal digits
      if ((num%10)==(num/10)) continue;

      //skip numerators that don't have a digit that exists in the denominator
      //is the first numerator digit in either the denominator first or second digit
      // and second numerator digit in either den first or second digit?
      if ((((num%10)!=(den%10)) && ((num%10)!=(den/10))) && 
          (((num/10)!=(den%10)) && ((num/10)!=(den/10))))
      continue;

      float original = float(num)/float(den);
      float factored;

      //find the matching digits, work out the fraction without those digits
      //all four combinations...
      if (num%10==den%10) {
        //these continues prevent dividing by zero and trivial examples
        //  which are multiples of 10 as denominator or numerator
        if (den%10 == 0) continue;
        if (den/10 == 0) continue;
        factored = (float(num/10)/float(den/10));
      }
      if (num/10==den%10) {
        if (den%10 == 0) continue;
        if (den/10 == 0) continue;
        factored = (float(num%10)/float(den/10));
      } 
      if (num/10==den/10) {
        if (den%10 == 0) continue;
        if (den/10 == 0) continue;
        factored = (float(num%10)/float(den%10));
      } 
      if (num%10==den/10) {
        if (den%10 == 0) continue;
        if (den/10 == 0) continue;
        factored = (float(num/10)/float(den%10));
      } 

      if (original==factored) {
        cout << num << "/" << den << " = " << original;
        cout << " reduced = " << factored << endl;
      }
    }
  }

  //final fractions are 
  //  16/64
  //  26/65
  //  19/95
  //  49/98

  //reduced product of these 4 fractions is just arithmetic

  t.printms();

  return 0;
}
