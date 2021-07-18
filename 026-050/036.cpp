#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "../timer.hpp"

namespace mp = boost::multiprecision;
using namespace std;

mp::cpp_int inttobin(mp::cpp_int a);
bool palindrome(mp::cpp_int a);

int main() {

  Timer t;

  int sum = 0;

  for (int i=1; i<1000000; i++) {
    if (palindrome(i)) {
      if (palindrome(inttobin(i))) {
        sum+=i;
      }
    }
  }

  cout << sum << endl;

  t.printms();

  return 0;
}


bool palindrome(mp::cpp_int a) {
  //if the first digit is 0 it just won't be a palindrome
  if (a.str()[0] == '0') return false;

  //compare first and last, then first+1, last-1, and so on
  for (int i=0; i<a.str().length(); i++) {
    if (a.str()[i] != a.str()[a.str().length()-i-1]) return false;
  }

  return true;
}

mp::cpp_int inttobin(mp::cpp_int a) {
  mp::cpp_int bin = 0;
  mp::cpp_int multiplier = 1;

  while (a>0) {
    bin += (a%2)*multiplier;
    a/=2;
    multiplier*=10;
  }

  return bin;
}

