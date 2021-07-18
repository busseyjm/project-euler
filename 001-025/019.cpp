// Counting Sundays

// Problem 19

// You are given the following information, but you may prefer to do some research 
//  for yourself.

//     1 Jan 1900 was a Monday.
//     Thirty days has September,
//     April, June and November.
//     All the rest have thirty-one,
//     Saving February alone,
//     Which has twenty-eight, rain or shine.
//     And on leap years, twenty-nine.
//     A leap year occurs on any year evenly divisible by 4, 
//      but not on a century unless it is divisible by 400.

// How many Sundays fell on the first of the month during the twentieth century 
//  (1 Jan 1901 to 31 Dec 2000)?


#include <string>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

//mp::cpp_int a = mp::pow(mp::cpp_int(2),i);
//string stra = a.str();




int main() {
  int days = 0;
  int sundays = 0;

  // there are 366 days in 1900, meaning 1901 starts on a tuesday
  //  days count % 7
  //    0 - tuesday
  //    1 - wed
  //    2 - th
  //    3 - fri
  //    4 - sat
  //    5 - sun
  //    6 - mon
  for (int i=1901; i<=2000; i++) {
    for (int m=1; m<=12; m++) {
      if (days%7==5) sundays++;
      switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
          days+=31;
          break;
        case 4:
        case 6:
        case 9:
        case 11:
          days+=30;
          break;
        case 2:
          if (i%4==0) {
            if(i%100==0 && i%400!=0){
              days+=28;
              break;
            }
            days+=29;
          } else {
            days+=28;
          }
          break;
      }
    }
  }

  cout << sundays << endl;
  return 0;
}
