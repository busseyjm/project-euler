// Pandigital multiples

// Problem 38

// Take the number 192 and multiply it by each of 1, 2, and 3:

//     192 × 1 = 192
//     192 × 2 = 384
//     192 × 3 = 576

// By concatenating each product we get the 1 to 9 pandigital, 192384576. 
//  We will call 192384576 the concatenated product of 192 and (1,2,3)

// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5,
//  giving the pandigital, 918273645, which is the concatenated product of 
//  9 and (1,2,3,4,5).

// What is the largest 1 to 9 pandigital 9-digit number that can be formed 
//  as the concatenated product of an integer with (1,2, ... , n) where n > 1?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

bool pandigital_onetonine(string a);

int main() {

  Timer t;

  string concatenated = "";
  mp::cpp_int largestbase = 9;
  mp::cpp_int largestmult = 6;
  mp::cpp_int largest = 0;

  for (mp::cpp_int i=9; i<10000; i++) {
    concatenated = "";
    int n = 1;

    while (concatenated.length() < 9) {
      concatenated += mp::cpp_int(i*n++).str();
    }
    if (pandigital_onetonine(concatenated)) {
      cout << "pandigital: " << concatenated << " = " << i << "*1-" << n-1 << endl;
      if (stoi(concatenated) > largest) {
        largest = stoi(concatenated);
        largestbase = i;
        largestmult = n-1;
      }
    } else {
      continue;
    }

  }

  cout << "largest pandigital multiple: " << largest << " = ";
  cout << largestbase << "*1-" << largestmult << endl;

  t.printms();

  return 0;
}

bool pandigital_onetonine(string a) {
  if (a.length() != 9)  return false;

  bool pand[10] = {0,0,0,0,0,0,0,0,0,0};

  for (int i=0; i<a.length(); i++) {
    pand[int(a[i])-48] = 1;
  }

  for (int i=1; i<10; i++) {
    if (pand[0] == 1) return false;
    if (pand[i]==0) {
      return false;
    }
  }

  return true;
}