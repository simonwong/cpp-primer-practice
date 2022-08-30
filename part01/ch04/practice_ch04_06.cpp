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
 * 练习4.20：假设iter的类型是vector<string>：：iterator，说明下面的表达式是否合法。
 * 如果合法，表达式的含义是什么？如果不合法，错在何处？
 */
int p4_20 () {
  vector<string> strVec = { "H", "E", "L", "L", "O" };
  vector<string>::iterator iter = strVec.begin();

  // a
  cout << *iter++ << endl; // 得到 "H"

  // b
  // cout << (*iter)++ << endl; // ❌ 不合法，string 没有 ++ 操作

  // c
  // cout << *iter.empty() << endl; ❌ 不合法，点操作优先于 *，iter 没有 empty 成员

  // d
  cout << iter->empty() << endl; // 合法，判断 "E" 是否为空

  // e
  // cout << ++*iter << endl; // ❌ 不合法，string 没有 ++ 操作，应该 *++iter

  // f
  cout << iter++->empty() << endl; // 合法，判断 "E" 是否为空，然后递增

  return 0;
}

int main () {
  p4_20();

  return 0;
}
