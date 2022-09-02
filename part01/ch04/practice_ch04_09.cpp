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
 * 练习4.28：编写一段程序，输出每一种内置类型所占空间的大小。
 */
int p4_28 () {
  char cv = 2;
  int iv = 12;
  long lv = 56;
  bool bv = true;
  string sv1 = "H";
  string sv2 = "Hello";

  cout << sizeof cv << endl;
  cout << sizeof iv << endl;
  cout << sizeof lv << endl;
  cout << sizeof bv << endl;
  cout << sizeof sv1 << endl;
  cout << sizeof sv2 << endl;
  return 0;
}

/**
 * 练习4.29：推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如果不一样，为什么？
 */
int p4_29 () {
  int x[10]; int *p = x;

  cout << sizeof(x) / sizeof(*x) << endl; // 40 / 4 = 10
  cout << sizeof(p) / sizeof(*p) << endl; // 8 / 4 = 2
  return 0;
}

/**
 * 练习4.30：根据4.12节中的表（第147页），在下述表达式的适当位置加上括号，
 * 使得加上括号之后表达式的含义与原来的含义相同。
 */
int p4_30 () {
  // a
  // sizeof x + y;
  // b
  // sizeof (p->mem[i]);
  // c
  // sizeof(a) < b;
  // d
  // sizeof (f())
  return 0;
}

int main () {
  p4_28();
  p4_29();
  p4_30();

  return 0;
}
