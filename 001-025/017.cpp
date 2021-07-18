// Number letter counts
 
// Problem 17

// If the numbers 1 to 5 are written out in words: 
//  one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 
//  letters used in total.

// If all the numbers from 1 to 1000 (one thousand) inclusive were 
//  written out in words, how many letters would be used?

// NOTE: Do not count spaces or hyphens. For example, 
//  342 (three hundred and forty-two) contains 23 letters 
//  and 115 (one hundred and fifteen) contains 20 letters. 
//  The use of "and" when writing out numbers is in compliance with British usage.

#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();
int lettercount(int);

int main() {

  // cout << "three hundred and sixty-five: " << lettercount(365) << endl;
  // cout << "three hundred and forty-two" << lettercount(342) << endl;
  // cout << "one thousand" << lettercount(1000) << endl;
  // cout << "one hundred and one" << lettercount(101) << endl;
  // cout << "sixty-five" << lettercount(65) << endl;

  int totalletters = 0;

  for (int i=1; i<=1000; i++) {
    totalletters += lettercount(i);
  }

  cout << "letters: " << totalletters << endl;

  return 0;
}

//this is a pretty focused function, only for 1-1000
int lettercount(int n) {
  if (n==1000) return string("onethousand").length();
  int wordlength = 0;
  switch (n) {
    case 1:
      return string("one").length();
      break;
    case 2:
      return string("two").length();
      break;
    case 3:
      return string("three").length();
      break;
    case 4:
      return string("four").length();
      break;
    case 5:
      return string("five").length();
      break;
    case 6:
      return string("six").length();
      break;
    case 7:
      return string("seven").length();
      break;
    case 8:
      return string("eight").length();
      break;
    case 9:
      return string("nine").length();
      break;
    case 10:
      return string("ten").length();
      break;
    case 11:
      return string("eleven").length();
      break;
    case 12:
      return string("twelve").length();
      break;
    case 13:
      return string("thirteen").length();
      break;
    case 14:
      return string("fourteen").length();
      break;
    case 15:
      return string("fifteen").length();
      break;
    case 16:
      return string("sixteen").length();
      break;
    case 17:
      return string("seventeen").length();
      break;
    case 18:
      return string("eighteen").length();
      break;
    case 19:
      return string("nineteen").length();
      break;
    case 20 ... 29:
      wordlength+= string("twenty").length();
      return wordlength+= lettercount(n%10);
      break;
    case 30 ... 39:
      wordlength+= string("thirty").length();
      return wordlength+= lettercount(n%10);
      break;
    case 40 ... 49:
      wordlength+= string("forty").length();
      return wordlength+= lettercount(n%10);
      break;
    case 50 ... 59:
      wordlength+= string("fifty").length();
      return wordlength+= lettercount(n%10);
      break;
    case 60 ... 69:
      wordlength+= string("sixty").length();
      return wordlength+= lettercount(n%10);
      break;
    case 70 ... 79:
      wordlength+= string("seventy").length();
      return wordlength+= lettercount(n%10);
      break;
    case 80 ... 89:
      wordlength+= string("eighty").length();
      return wordlength+= lettercount(n%10);
      break;
    case 90 ... 99:
      wordlength+= string("ninety").length();
      return wordlength+= lettercount(n%10);
      break;
    default:
      break;
  }
  if (n>=100) {
    //how many hundreds
    wordlength+= lettercount(n/100);
    //"hundred"
    wordlength+= string("hundred").length();
    //"and"?
    if (n%100!=0) {
      wordlength+= string("and").length();
    }
  }
  if (n%100!=0) {
    return wordlength+= lettercount(n%100);
  }

  return wordlength;
}
