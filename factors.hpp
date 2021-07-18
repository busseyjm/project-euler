#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;

void printfactors(mp::cpp_int num) {
  cout << "1 ";
  if (num==0) {
    return;
  }
  for (int i=2; i<sqrt(num)+1; i++) {
    if (num%i == 0) {
      //if the number isn't square 
      //  add both of the factor pair
      cout << i << " ";
      if ((num/i) != i) {
        cout << num/i << " ";
      }
    }
  }
  cout << num << endl;
}