#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;

/**
 * 练习5.4：说明下列例子的含义，如果存在问题，试着修改它。
 */
int p5_04 () {
  // a
  string s = "Hello";
  string::iterator iter = s.begin();
  while (iter != s.end()) {
    /* code */
    iter++;
  }

  // b
  // bool status;
  // while (status = find(word)) {
  // }
  // if (!status) {
  // }
  return 0;
}

int main () {
  p5_04();

  return 0;
}
