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
 * 练习4.17：说明前置递增运算符和后置递增运算符的区别。
 */
int p4_17 () {
  // 前置版本：得到递增后的值，即对象本身的左值（避免了不必要的工作）
  // 后置版本：得到递增前的值，即对象原始值的副本作为右值（如果不需要修改前的值，那后置操作比较浪费）
  return 0;
}

/**
 * 练习4.18：如果第132页那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？
 */
int p4_18 () {
  vector<int> v = { 1, 2, 3, 4, 5 };
  auto beg = v.begin();
  while (beg != v.end() && *beg >= 0) {
    cout << *beg++ << endl;
  }

  auto beg2 = v.begin();
  // 将会从第二个符合条件的开始一直到最后符合条件的下一位为止
  while (beg2 != v.end() && *beg2 >= 0) {
    cout << *++beg2 << endl;
  }

  return 0;
}

/**
 * 练习4.19：假设ptr的类型是指向int的指针、vec的类型是vector<int>、ival的类型是int，
 * 说明下面的表达式是何含义？如果有表达式不正确，为什么？应该如何修改？
 */
int p4_19 () {
  int ival = 2;
  vector<int> vec = {1, 2, 3, 4, 5};
  int *ptr = &ival;

  // a
  if (ptr != 0 && *ptr++) {
    // 判断指针是否为空，判断 ptr 指向的值是否为真
    cout << "a ok" << endl;
  }

  // b
  if (ival++ && ival) {
    // 判断 ival 以及 ival 递增后是否有值
    cout << "b ok" << endl;
  }

  // c
  if (vec[ival++] <= vec[ival]) {
    // 判断 vec 下标为 2 的值小于等于下标为 3 的值
    cout << "c ok" << endl;
  }

  return 0;
}

int main () {
  p4_17();
  p4_18();
  p4_19();

  return 0;
}
