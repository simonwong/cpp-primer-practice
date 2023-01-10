#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

/**
 * 练习9.41：编写程序，从一个vector<char>初始化一个string。
 */
void p9_41 () {
  vector<char> vc = {'H', 'E', 'L', 'L', 'O'};

  string str(vc.cbegin(), vc.cend());

  cout << str << endl;
}

/**
 * 练习9.42：假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？
 */
void p9_42 () {
  // 使用 reserve(120)
}

int main (int argc, char **argv) {
  p9_41();
  // p9_42();

  return 0;
}
