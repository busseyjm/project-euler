#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>


int intlength(int a) {
  //find length of a number with floor(log10(n))+1
  // (not ceil log10(n) since log10(10)=1 :) )
  if (a == 0) return 1;
  return floor(log10(a)) + 1;
}

int rotateright(int a) {
  //rotating a number is easy with its length
  int length = intlength(a);

  //take the first digit (n%10), and put it on the front: n/10+((n%10)*10^(length-1))
  int rotated = a/10 + ((a%10)*pow(10, length-1));
  return rotated;
}

int rotateleft(int a) {
  //rotating a number is easy with its length
  int length = intlength(a);

  //remove the first digit with mod to get remaining digits: a%10^(length-1)
  // append removed digit (n/10^(length-1)) to the end: (a%10^(length-1))*10 + n/10^(length-1);
  int rotated = a%(int(pow(10,length-1)))*10 + a/(pow(10,length-1));
  return rotated;
}


int truncright(int a) {
  //truncate rightmost digit by just dividing by 10
  int truncated = a/10;
  return truncated;
}

int truncleft(int a) {
  int length = intlength(a);

  //truncate the leftmost digit with mod to get remaining digits: a%10^(length-1)
  int truncated = a%(int(pow(10,length-1)));
  return truncated;
}