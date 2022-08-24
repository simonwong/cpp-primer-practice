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
 * 练习4.13：在下述语句中，当赋值完成后i和d的值分别是多少？
 */
int p4_13 () {
  int i;
  double d;
  // a
  d = i = 3.5;
  // i 是 3, d 是 3
  cout << i << ", " << d << endl;

  // b
  i = d = 3.5;
  // i 是 3，d 是 3.5
  cout << i << ", " << d << endl;
  return 0;
}

/**
 * 练习4.14：执行下述if语句后将发生什么情况？
 */
int p4_14 () {
  int i = 42;

  // if (42 = i) {} // 报错，赋值运算左侧必须是左值

  if (i = 42) {} // 必定 true
  return 0;
}

/**
 * 练习4.15：下面的赋值是非法的，为什么？应该如何修改？
 */
int p4_15 () {
  double dval; int ival; int *pi;

  // dval = ival = pi = 0;
  // 写成 *pi 就可以了。结果都为 0
  dval = ival = *pi = 0;

  cout << dval << ", " << ival << "，" << *pi << endl;
  return 0;
}

/**
 * 练习4.16：尽管下面的语句合法，但它们实际执行的行为可能和预期并不一样，为什么？应该如何修改？
 */
int p4_16 () {
  // (a)
  // if (p = getPtr() != 0) {}
  // 应该带上括号
  // if ((p = getPtr()) != 0) {}

  // (b)
  // if (i = 1024) {}
  // 上面是赋值，一般都是判断 =
  // if (i == 1024) {}
  return 0;
}

int main () {
  p4_13();
  p4_14();
  p4_15();
  p4_16();

  return 0;
}
