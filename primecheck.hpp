#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
bool primecheck(mp::cpp_int val) {
  //mp::cpp_int loopmax = mp::pow(val, 1/2);
  mp::cpp_int loopmax = mp::sqrt(val) + 1;

  if (val<1) return false;
  if (val==2) return true;
  if (val%2==0) return false;

  for (int i=3; i<loopmax; i+=2) {
    if (val%i==0) {
      return false;
    }
  }
  return true;
}

bool primecheck(int val) {
  //mp::cpp_int loopmax = mp::pow(val, 1/2);
  int loopmax = sqrt(val) + 1;

  if (val<=1) return false;
  if (val==2) return true;
  if (val%2==0) return false;

  for (int i=3; i<loopmax; i+=2) {
    if (val%i==0) {
      return false;
    }
  }
  return true;
}

int nextprime(int val) {
  if (!primecheck(val)) return -1;

  int plusone = val;

  //change to special case of val==2
  do {
    if (val != 2) {
      plusone += 2;
    } else {
      plusone += 1;
    }
  } while (!primecheck(plusone));

  return plusone;
}

mp::cpp_int nextprime(mp::cpp_int val) {
  if (!primecheck(val)) return -1;

  mp::cpp_int plusone = val;

  do {
    if (val != 2) {
      plusone += 2;
    } else {
      plusone += 1;
    }
  } while (!primecheck(plusone));

  return plusone;
}

mp::cpp_int prevprime(mp::cpp_int val) {
  if (!primecheck(val)) return -1;

  mp::cpp_int minustwo = val;

  do {
    minustwo -= 2;
  } while (!primecheck(minustwo));

  return minustwo;
}

int gcd(int a, int b) {
  if (a==0) return b;
  if (b==0) return a;
  int temp = 0;
  if (b>a) {
    temp=a;
    a=b;
    b=temp;
  }
  do {
    if (a%b == 0) return b;
    temp=a%b;
    a=b;
    b=temp;
  //hhhehehehehe
  } while (1);
}

bool coprime(int a, int b) {
  return (gcd(a,b) == 1);
}