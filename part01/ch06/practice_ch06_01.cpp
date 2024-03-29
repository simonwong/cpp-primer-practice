#include <iostream>
#include <string>
#include <vector>
#include "Chapter6.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;

/**
 * 练习6.1：实参和形参的区别是什么？
 */
int p6_01 () {
  // 形参 是定义函数时的参数定义
  // 实参 是调用函数是的参数
  return 0;
}

/**
 * 练习6.2：请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
 */
int p6_02 () {
  // a
  // ❌ 函数定义的返回值和实际返回值不符
  // string f () {
  //   string s;
  //   return s;
  // }

  // b
  // ❌ 没有定义返回类型
  // int f2(int i) {}

  // c
  // ❌ 形参名不能一样
  // int calc(int v1, int v2) {}

  // d
  // ✅
  // double square(double x) return x * x;
  return 0;
}

/**
 * 练习6.3：编写你自己的fact函数，上机检查是否正确。
 */
int fact (int v) {
  int res = v;
  while (v > 1) {
    res *= --v;
  }
  return res;
}
void p6_03 (void) {
  int factRes = fact(5);
  cout << "5 的阶乘结果" << factRes << endl;
}


/**
 * 练习6.4：编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。
 */

void user_interactive_fact () {
  int i;

  while (cin >> i) {
    cout << i << "的阶乘结果" << fact(i) << endl;
  }
}
void p6_04 (void) {
  user_interactive_fact();
}

/**
 * 练习6.5：编写一个函数输出其实参的绝对值。
 */
int absolute (int v) {
  return v < 0 ? -v : v;
}
void p6_05 (void) {
  int ar1 = absolute(5);
  cout << "5 的绝对值为" << ar1 << endl;

  int ar2 = absolute(-8);
  cout << "-8 的绝对值为" << ar2 << endl;
}

/**
 * 练习6.6：说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。
 */
int more_params (int v) {
  int a = 6;
  static int b = 7;
  cout << "形参 v：" << v << endl;
  cout << "局部变量 a：" << a << endl;
  cout << "局部静态变量 b：" << b << endl;

  return b;
}
void p6_06 () {
  int res = more_params(2);
  cout << "res + 1 (局部静态变量 b + 1)：" << ++res << endl;
}

/**
 * 练习6.6：说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。
 */
int static_test () {
  static int count = 0;

  cout << "局部静态变量 count：" << ++count << endl;

  return count;
}
void p6_07 () {
  static_test();
  static_test();
  static_test();
}

/**
 * 练习6.6：说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。
 */
void print (vector<int>::const_iterator beg, vector<int>::const_iterator end) {
  while (beg != end) {
    cout << *(beg++) << endl;
  }
}
void p6_08 () {
  vector<int> v = {1,2,3,4,5};

  print(v.begin(), v.end());
}

/**
 * 练习6.9：编写你自己的 fact.cc 和 factMain.cc，
 * 这两个文件都应该包含上一小节的练习中编写的Chapter6.h头文件。
 * 通过这些文件，理解你的编译器是如何支持分离式编译的。
 */
void p6_09 () {
  // 见同目录下的 fact.cc 和 factMain.cc
  // 执行 clang++ -std=c++17 factMain.cc fact.cc
}


int main () {
  // p6_01();
  // p6_02();
  p6_03();
  p6_04();
  p6_05();
  p6_06();
  p6_07();
  p6_08();
  // p6_09();

  return 0;
}
