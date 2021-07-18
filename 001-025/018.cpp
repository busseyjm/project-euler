// Maximum path sum I

// Problem 18

// By starting at the top of the triangle below and moving to 
//  adjacent numbers on the row below, the maximum total from top to bottom is 23.

// 3
// 7 4
// 2 4 6
// 8 5 9 3

// That is, 3 + 7 + 4 + 9 = 23.

// Find the maximum total from top to bottom of the triangle below:

// 75
// 95 64
// 17 47 82
// 18 35 87 10
// 20 04 82 47 65
// 19 01 23 75 03 34
// 88 02 77 73 07 63 67
// 99 65 04 28 06 16 70 92
// 41 41 26 56 83 40 80 70 33
// 41 48 72 33 47 32 37 16 94 29
// 53 71 44 65 25 43 91 52 97 51 14
// 70 11 33 28 77 73 17 78 39 68 17 57
// 91 71 52 38 17 14 91 43 58 50 27 29 48
// 63 66 04 68 89 53 67 30 73 16 69 87 40 31
// 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

// NOTE: As there are only 16384 routes, it is possible to solve this problem 
//   by trying every route. However, Problem 67, is the same challenge with a 
//   triangle containing one-hundred rows; it cannot be solved by brute force, 
//   and requires a clever method! ;o)

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
const int ARRAY_SIZE = 15;

struct entry {
  int summed;
  int original;
};


int main() {
  entry tri[ARRAY_SIZE][ARRAY_SIZE];
  fstream problem;
  problem.open("018.txt");

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
