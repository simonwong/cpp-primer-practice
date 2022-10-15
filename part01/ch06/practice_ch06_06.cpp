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
using std::initializer_list;

/**
 * 练习6.49：什么是候选函数？什么是可行函数？
 */
void p6_49 () {
  // 候选函数：
  // 与被调用的函数同名
  // 声明在调用点可见

  // 可行函数：
  // 形参数量和提供实参数量相等
  // 类型一一相等，或能转换
}

/**
 * 练习6.50：已知有第217页对函数f的声明，对于下面的每一个调用列出可行函数。
 * 其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？
 *
 * 练习6.51：编写函数f的4个版本，令其各输出一条可以区分的消息。验证上一个练习的答案，如果你回答错了，反复研究本节的内容直到你弄清自己错在何处。
 */
void f () {}
void f (int) {}
void f (int, int) {}
void f (double, double) {}
void p6_50_51 () {
  // a 不合法
  // f(2.56, 42);
  // b 合法
  f(42);
  // c 合法
  f(42, 0);
  // d 合法
  f(2.56, 3.14);
}

/**
 * 练习6.52：已知有如下声明，
 * 请指出下列调用中每个类型转换的等级（参见6.6.1节，第219页）。
 */
void manip(int, int);
double dobj;

void p6_52 () {
  // a 类型转换
  manip('a', 'z');
  // b 算数类型转换
  manip(55.4, dobj);
}

/**
 * 练习6.53：说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法（如果有的话）。
 */
void p6_53 () {
  // a 合法
  // int calc(int&, int&);
  // int calc(const int&, const int&);
  // b 合法
  // int calc(char*, char*);
  // int calc(const char*, const char*);
  // c ❌ 不合法，二义性
  // int calc(char*, char*);
  // int calc(char* const, char* const);
}

int main () {
  p6_49();
  p6_50_51();
  p6_52();
  p6_53();

  return 0;
}
