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
 * 练习6.39：说明在下面的每组声明中第二条声明语句是何含义。如果有非法的声明，请指出来。
 */
void p6_39 () {
  // a ❌ 重复声明，下面两种声明是一样的
  // int calc(int, int);
  // int calc(const int, const int);

  // b ❌ 必须通过形参来区分重载函数，会产生二义性调用
  // int get();
  // double get();

  // c ✅ 没有问题
  // int *reset(int *);
  // double *reset(double *);
}


int main () {
  // p6_39();

  return 0;
}
