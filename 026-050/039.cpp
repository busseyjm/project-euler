// Integer right triangles

// Problem 39

// If p is the perimeter of a right angle triangle with integral length sides,
//   {a,b,c}, there are exactly three solutions for p = 120.

// {20,48,52}, {24,45,51}, {30,40,50}

// For which value of p ≤ 1000, is the number of solutions maximised?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"
#include "../primecheck.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;

  //pythagorean triples:
  // generate every pythagorean triple up to the sum of the triple<1000
  // find the perimeter with the most solutions

  //  {a,b,c}
  //  a = k*(m^2-n^2)
  //  b = k*(2mn)
  //  c = k*(m^2+n^2)
  //  p = a+b+c

  //  where m, n, and k are positive integers with m > n, 
  //  and with m and n coprime and not both odd. 

  int a,b,c,k,per = 0;

  //track how many triples add to a perimeter
  int p[1001];
  for (int i=0; i<1001; i++) p[i] = 0;

  for (int m=1; m<=1000; m++) {
    for (int n=1; n<m; n++) {
      if (!coprime(m,n)) continue;
      if (m%2 == 1 && n%2 == 1) continue;

      a = (m*m)-(n*n);
      b = 2*m*n;
      c = (m*m)+(n*n);
      k = 1;

      per = k*a+k*b+k*c;
      while (per <= 1000) {
        p[per]++;
        k++;
        per = k*a+k*b+k*c;
      }
    }
  }

  int largesti = 0;
  int largest = 0;


  for (int i=0; i<1001; i++) {
    if (p[i] > largest) {
      largest = p[i];
      largesti = i;
    }
  }

  cout << largesti << " -> " << largest << endl;

  t.printms();

  return 0;
}
