// Non-abundant sums

// Problem 23

// A perfect number is a number for which the sum of its 
//  proper divisors is exactly equal to the number. For example, 
//  the sum of the proper divisors of 28 would be 
//  1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

// A number n is called deficient if the sum of its proper divisors 
//  is less than n and it is called abundant if this sum exceeds n.

// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, 
//  the smallest number that can be written as the sum of two 
//  abundant numbers is 24. By mathematical analysis, 
//  it can be shown that all integers greater than 28123 can be 
//  written as the sum of two abundant numbers. However, this 
//  upper limit cannot be reduced any further by analysis even 
//  though it is known that the greatest number that cannot be 
//  expressed as the sum of two abundant numbers is less than this 
//  limit.

// Find the sum of all the positive integers which cannot be written 
//  as the sum of two abundant numbers.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <algorithm>

namespace mp = boost::multiprecision;
using namespace std;

mp::cpp_int factorsum(mp::cpp_int num);

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();

int main() {

  // first im going to find a few abundant numbers to get an idea of
  //  how many there are and what they look like

  // for (int i=1; i<100; i++) {
  //   if (factorsum(i) > i) {
  //     cout << i << " ";
  //   }
  // }
  // cout << endl;

  // naive approach: add all numbers 1-28123 to a list, and all
  //  abundant numbers to another list
  // remove all sums of abundant numbers from the list
  // sum the remaining numbers

  vector<int> alln;
  vector<int> abundants;

  //this took about 4 seconds to run on my machine
  cout << "populating vectors" << endl;

  for (int i=1; i<=28123; i++) {
  // for (int i=1; i<=200; i++) {
    if (factorsum(i) > i) {
      abundants.push_back(i);
    }
    alln.push_back(i);
  }

  cout << "done" << endl;

  //O(n^2) find all possible sums of all abundants (<28123)
  //  remove them from alln

  //this takes a very long time to run. it is naive.

  vector<int>::iterator it;

  for (int i=0; i<abundants.size(); i++) {
    cout << "i: " << i << " of " << abundants.size() << " val: " << abundants[i] << endl;
    for (int j=i; j<abundants.size(); j++) {
    int tempsum = abundants[i]+abundants[j];
    if (tempsum>28123) break;
    it = find(alln.begin(), alln.end(), abundants[i]+abundants[j]);
      if (it != alln.end()) {
        alln.erase(it);
      }
    }
  }


  cout << alln.size() << " numbers remain that cannot be a sum of 2 abundant numbers" << endl;
  cout << "sum of remaining numbers: ";

  // sum the numbers that remain in alln
  mp::cpp_int asum = 0;
  for (int i=0; i<alln.size(); i++) {
    asum+=alln[i];
  }

  cout << asum << endl;

  // it = find(alln.begin(), alln.end(), 3);
  // if (it != alln.end())
  // alln.erase(it);

  return 0;
}

//"proper" divisors sum, num is not included
mp::cpp_int factorsum(mp::cpp_int num) {
  if (num==0) return 1;
  mp::cpp_int sum = 1;
  for (int i=2; i<sqrt(num)+1; i++) {
    if (num%i == 0) {
      //if the number isn't square 
      //  add both of the factor pair
      if ((num/i) != i) {
      sum+=(num/i);
      }
      sum+=i;
    }
  }
  return sum;
}