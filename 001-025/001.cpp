#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();


int main() {
  namespace mp = boost::multiprecision;

  int sum = 0;

  for (int i=1; i<1000; i++) {
    if (i%3==0) {
      sum+=i;
    } else if (i%5==0) {
      sum+=i;
    }
  }

  cout << sum;
  return 0;
}
