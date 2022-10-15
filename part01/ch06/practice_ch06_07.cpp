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
 * 练习6.54：编写函数的声明，令其接受两个int形参并且返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。
 * 练习6.55：编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。
 * 练习6.56：调用上述vector对象中的每个元素并输出其结果。
 */
int mathFn (int, int);

int addFn (int a, int b) {
  return a + b;
}

int sudFn (int a, int b) {
  return a - b;
}

int multiFn (int a, int b) {
  return a * b;
}

int divideFn (int a, int b) {
  return a / b;
}

void p6_54_55_56 () {
  vector<decltype(mathFn) *> intFnVec;
  intFnVec.push_back(&addFn);
  intFnVec.push_back(&sudFn);
  intFnVec.push_back(&multiFn);
  intFnVec.push_back(&divideFn);

  for (auto mathFn : intFnVec) {
    cout << mathFn(4, 2) << endl;
  }

}

int main () {
  p6_54_55_56();

  return 0;
}
