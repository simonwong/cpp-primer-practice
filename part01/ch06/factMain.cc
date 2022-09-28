#include <iostream>
#include "Chapter6.h"

using std::cout;
using std::endl;

int main () {
  vector<int> v = {1, 2, 3, 4, 5};
  print(v.begin(), v.end());

  return 0;
}
