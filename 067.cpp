// Maximum path sum I

// Problem --18-- 67

// By starting at the top of the triangle below and moving to 
//  adjacent numbers on the row below, the maximum total from top to bottom is 23.

// 3
// 7 4
// 2 4 6
// 8 5 9 3

// That is, 3 + 7 + 4 + 9 = 23.

// Find the maximum total from top to bottom in triangle.txt 
//  (right click and 'Save Link/Target As...'), a 15K text file 
//  containing a triangle with one-hundred rows.


//algo:
//  starting on row n-1 loop though each entry
//  calculate the largest sum from entry i and the 2 value on the lower row i, i+1
//  repeat on row n-2... until row 0 using the calculated sums from row entries below it


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>
#include <algorithm>

namespace mp = boost::multiprecision;
using namespace std;

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();
const int ARRAY_SIZE = 100;

struct entry {
  int summed;
  int original;
};


int main() {
  entry tri[ARRAY_SIZE][ARRAY_SIZE];
  fstream problem;
  problem.open("067.txt");

  //row 1 has 1 value, row 2 has 2...
  //load in the file into 2d entry array
  for (int line=0; line<ARRAY_SIZE; line++) {
    for (int column=0; column<=line; column++) {
      problem >> tri[line][column].original;
      tri[line][column].summed = tri[line][column].original;
    }
  }

  // for (int line=0; line<ARRAY_SIZE; line++) {
  //   for (int column=0; column<=line; column++) {
  //     cout << tri[line][column].original << " ";
  //   }
  //   cout << endl;
  // }

  //and now the actual algorithm
  for (int line=ARRAY_SIZE-2; line>=0; line--) {
    for (int column=0; column<=line; column++) {
      tri[line][column].summed += 
        max(  tri[line+1][column].summed, 
              tri[line+1][column+1].summed);
    }
  }

  cout << tri[0][0].summed << endl;

  return 0;
}
