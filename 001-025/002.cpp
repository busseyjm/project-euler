#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>


using namespace std;
//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();


int main() {
  namespace mp = boost::multiprecision;

  mp::cpp_int fiba = 1;
  mp::cpp_int fibb = 1;
  mp::cpp_int fibnext = 0;
  mp::cpp_int evensum = 0;

  do {
    fibnext = fiba + fibb;
    if (fibnext%2==0) evensum += fibnext;
    fiba = fibb;
    fibb = fibnext;
  } while (fibnext<4000000);



  cout << evensum << endl;
  return 0;
}
