#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <numeric>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::string;

/**
 * 练习10.42：使用list代替vector重新实现10.2.3节（第343页）中的去除重复单词的程序。
 */
void elimDups (list<string>& lst) {
  lst.sort();
  lst.unique();
}

void p10_42 () {
  list<string> strList = {"asd", "zxc", "asd", "vbn", "a", "c", "vbn", "jkl", "cx", "jkl"};
  elimDups(strList);

  for (auto item : strList) {
    cout << item << endl;
  }
  cout << endl;
}

int main () {
  p10_42();

  return 0;
}
