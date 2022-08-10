#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;

int p3_21_22 () {
  // 21 没看懂，不过都是使用迭代器遍历罢了
  string str = "hello iterator";
  auto start = str.begin();

  while (!isspace(*start) && start != str.end()) {
    *start = toupper(*start);
    start++;
  }

  cout << str << endl;

  return 0;
}

int p3_23 () {
  vector<int> intVec = {12, 123, 23, 54, 4, 78, 3, 56, 90, 10};

  auto start = intVec.begin();
  while (start != intVec.end()) {
    *start = *start * 2;
    cout << *start << endl;
    start++;
  }

  return 0;
}

int main () {
  p3_21_22();
  p3_23();

  return 0;
}
