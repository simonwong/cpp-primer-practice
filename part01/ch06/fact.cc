#include <iostream>
#include "Chapter6.h"

using std::cout;
using std::endl;

void print (vector<int>::const_iterator beg, vector<int>::const_iterator end) {
  while (beg != end) {
    cout << *(beg++) << endl;
  }
}
