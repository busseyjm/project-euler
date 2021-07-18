// 1000-digit Fibonacci number

// Problem 25

// The Fibonacci sequence is defined by the recurrence relation:

//     Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

// Hence the first 12 terms will be:

//     F1 = 1
//     F2 = 1
//     F3 = 2
//     F4 = 3
//     F5 = 5
//     F6 = 8
//     F7 = 13
//     F8 = 21
//     F9 = 34
//     F10 = 55
//     F11 = 89
//     F12 = 144

// The 12th term, F12, is the first term to contain three digits.

// What is the index of the first term in the Fibonacci sequence 
//  to contain 1000 digits?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "../timer.hpp"
#include <future>

namespace mp = boost::multiprecision;
using namespace std;

mp::cpp_int fib(int n);

int main() {

  Timer t;

  mp::cpp_int fiba = 1;
  mp::cpp_int fibb = 1;
  mp::cpp_int fibc = 2;
  int index = 3;

  while(fibc.str().length() < 1000) {
    fiba = fibb;
    fibb = fibc;
    fibc = fiba+fibb;
    index++;
  }

  cout << fibc << endl;
  cout << "i: " << index << endl;


  t.printms();



  return 0;
}

//artifact of parallelization goofing around
mp::cpp_int fib(int n) {
  if (n<2) return n;
  mp::cpp_int a, b;
  // future<mp::cpp_int> c = async (fib, n-1);
  // future<mp::cpp_int> d = async (fib, n-2);
  a = fib(n-1);
  b = fib(n-2);
  // a = c.get();
  // b = d.get();
  return a+b;
}