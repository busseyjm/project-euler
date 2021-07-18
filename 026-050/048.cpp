// Self powers

// Problem 48

// The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

// Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

int main() {

  Timer t;
  mp::cpp_int sum = 0;

  for (int i=1; i<=1000; i++)
    sum += mp::pow(mp::cpp_int(i),i);

  cout << sum << endl;

  t.printms();

  return 0;
}
