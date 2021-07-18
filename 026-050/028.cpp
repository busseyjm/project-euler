// Number spiral diagonals
 
// Problem 28

// Starting with the number 1 and moving to the right in a clockwise 
//  direction a 5 by 5 spiral is formed as follows:

// 21 22 23 24 25
// 20  7  8  9 10
// 19  6  1  2 11
// 18  5  4  3 12
// 17 16 15 14 13

// It can be verified that the sum of the numbers on the diagonals is 101.

// What is the sum of the numbers on the diagonals in a 1001 by 1001 
//  spiral formed in the same way?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  int index = 1;
  int sum = 1;
  int layer = 1;

  //grid size = layer*2+1

  while (layer*2+1 <= 1001) {
    for (int i=0; i<4; i++) {
      sum+=(index+layer*2);
      index+=layer*2;
    }
    layer++;
  }
  
  cout << sum << endl;


  t.printms();

  return 0;
}
