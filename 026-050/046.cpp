// Goldbach's other conjecture

// Problem 46

// It was proposed by Christian Goldbach that every odd composite number can 
//  be written as the sum of a prime and twice a square.

// 9 = 7 + 2×1^2
// 15 = 7 + 2×2^2
// 21 = 3 + 2×3^2
// 25 = 7 + 2×3^2
// 27 = 19 + 2×2^2
// 33 = 31 + 2×1^2

// It turns out that the conjecture was false.

// What is the smallest odd composite that cannot be written as the sum of a 
//  prime and twice a square?

#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include "../primecheck.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  for (int i=35; i<10000; i+=2) {
    if (primecheck(i)) continue;

    // cout << i << endl;
    bool conjholds = 0;

    for (int p=2; p<i; p=nextprime(p)) {

      for (int s=1; p+2*pow(s,2)<=i; s++) {
        if (p+2*pow(s,2) == i) {
          //cout << i << " holds for p=" << p << " s=" << s << endl;
          conjholds = 1;
        }
        if (conjholds) break;
      }
    if (conjholds) break;
    }
    

    if (!conjholds) {
      cout << "conjecture does not hold for " << i << endl;
      //break;
    }
  }



  t.printms();

  return 0;
}
