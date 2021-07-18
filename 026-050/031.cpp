// Coin sums

// Problem 31

// In the United Kingdom the currency is made up of pound (£) and pence (p). 
//  There are eight coins in general circulation:

//     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

// It is possible to make £2 in the following way:

//     1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

// How many different ways can £2 be made using any number of coins?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  //start with the 2 dollar coin, one way
  int waystomaketwodollars = 1;

  //INCREDIBLY naive and lazy way to solve this problem
  for (int dollar=0; dollar<=2; dollar++) {
    for (int halfd=0; halfd<=4; halfd++) {
      for (int twentyp=0; twentyp<=10; twentyp++) {
        for (int dime=0; dime<=20; dime++) {
          for (int nickel=0; nickel<=40; nickel++) {
            for (int tuppence=0; tuppence<=100; tuppence++) {
              for (int penny=0; penny<=200; penny++) {
                if ( (dollar*100 + halfd*50 + twentyp*20 + dime*10 + nickel*5 + tuppence*2 + penny) == 200) {
                  waystomaketwodollars++;
                }
              }
            }
          }
        }
      }
    }
  }

  cout << "there are: " << waystomaketwodollars << " ways to make two dollars in the uk" << endl;



  t.printms();

  return 0;
}
