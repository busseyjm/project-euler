// Sub-string divisibility
 
// Problem 43

// The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

// Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

//     d2d3d4=406 is divisible by 2
//     d3d4d5=063 is divisible by 3
//     d4d5d6=635 is divisible by 5
//     d5d6d7=357 is divisible by 7
//     d6d7d8=572 is divisible by 11
//     d7d8d9=728 is divisible by 13
//     d8d9d10=289 is divisible by 17

// Find the sum of all 0 to 9 pandigital numbers with this property.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include <algorithm>

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  mp::cpp_int p[] = {0,1,2,3,4,5,6,7,8,9};
  sort(p, p+10);
  mp::cpp_int pandsums = 0;

  do {
    if (p[0] == 0) continue;
    if ((p[1]*100+p[2]*10+p[3])%2  !=0) continue;
    if ((p[2]*100+p[3]*10+p[4])%3  !=0) continue;
    if ((p[3]*100+p[4]*10+p[5])%5  !=0) continue;
    if ((p[4]*100+p[5]*10+p[6])%7  !=0) continue;
    if ((p[5]*100+p[6]*10+p[7])%11 !=0) continue;
    if ((p[6]*100+p[7]*10+p[8])%13 !=0) continue;
    if ((p[7]*100+p[8]*10+p[9])%17 !=0) continue;

    //create the number that matches all these properties
    mp::cpp_int num = 0;
    for (int i=0; i<10; i++) {
      num += p[9-i]*mp::pow(mp::cpp_int(10),i);
    }
    cout << num << endl;
    pandsums += num;

  } while (next_permutation(p, p+10));
  

  cout << pandsums << endl;

  t.printms();

  return 0;
}
