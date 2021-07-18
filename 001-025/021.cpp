// Amicable numbers
 
// Problem 21

// Let d(n) be defined as the sum of proper divisors of n 
//  (numbers less than n which divide evenly into n).

// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an 
//  amicable pair and each of a and b are called amicable numbers.

// For example, the proper divisors of 220 are 
//  1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 
//  therefore d(220) = 284. The proper divisors of 284 are 
//  1, 2, 4, 71 and 142; so d(284) = 220.

// Evaluate the sum of all the amicable numbers under 10000.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

mp::cpp_int factorsum(mp::cpp_int num);

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();

int main() {

  mp::cpp_int amicablesum = 0;

  // naive, VERY slow!

  // for (int i=1; i<10000; i++) {
  //   for (int j=1; j<10000; j++) {
  //     cout << i << " " << j << endl;
  //     if ((factorsum(i)==j) && (factorsum(j)==i)) {
  //       amicablesum+= factorsum(i);
  //       amicablesum+= factorsum(j);
  //     }
  //   }
  // }

  mp::cpp_int sumtable[10000];

  for (int i=1; i<10000; i++) {
    sumtable[i] = factorsum(i);
  }


  //amicable pair: d(a) = b, d(b) = a; 
  //  therefore if d(d(a)) = a then d(a), aka b is its pair

  for (int i=1; i<10000; i++) {
    //no out of bounds
    if (sumtable[i]>=10000) continue;
    //no d(a) = a
    if (i==sumtable[i]) continue;

    //if d(d(a)) = a, add it to the sum
    if (i==sumtable[int(sumtable[i])]) {
      amicablesum+=i;
      cout << i << "\t" << sumtable[i] << endl;
    }
  }

  cout << amicablesum << endl;

  return 0;
}

//"proper" divisors sum, num is not included
mp::cpp_int factorsum(mp::cpp_int num) {
  if (num==0) return 1;
  mp::cpp_int sum = 1;
  for (int i=2; i<sqrt(num)+1; i++) {
    cout << "i: " << i << endl;
    if (num%i == 0) {
      //prevents double factors for square numbers
      if ((num/i) != i) {
      sum+=(num/i);
      }
      sum+=i;
    }
  }
  return sum;
}