#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

bool pandigital_oneton(string a, int n) {
  if (a.length() != n)  return false;

  bool pand[n+1];
  for (int i=0; i<=n; i++) {
    pand[i] = 0;
  }

  for (int i=0; i<n; i++) {
    pand[int(a[i])-48] = 1;
  }

  for (int i=1; i<=n; i++) {
    if (pand[0] == 1) return false;
    if (pand[i]==0) {
      return false;
    }
  }

  return true;
}

bool pandigital_zeroton(string a, int n) {
  if (a.length() != n)  return false;

  bool pand[n+1];
  for (int i=0; i<=n; i++) {
    pand[i] = 0;
  }

  for (int i=0; i<n; i++) {
    pand[int(a[i])-48] = 1;
  }

  for (int i=0; i<=n; i++) {
    if (pand[i]==0) {
      return false;
    }
  }

  return true;
}

bool is_intpermutation(int a, int b) {
  int acount[10] = {0,0,0,0,0,0,0,0,0,0};
  int bcount[10] = {0,0,0,0,0,0,0,0,0,0};

  while (a>=1) {
    acount[a%10]++;
    a/=10;
  }  
  while (b>=1) {
    bcount[b%10]++;
    b/=10;
  }

  for (int i=0; i<10; i++) {
    if (acount[i] != bcount[i]) return false;
  }

  return true;
}