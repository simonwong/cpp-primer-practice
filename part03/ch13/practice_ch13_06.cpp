#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "String.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/**
 * 练习13.45：解释右值引用和左值引用的区别。
 */
void p13_45 () {
  // 右值引用的重要性质：只能绑定到一个将要销毁的对象。
  // 左值持久，右值短暂
}

/**
 * 练习13.46：什么类型的引用可以绑定到下面的初始化器上？
 */
void p13_46 () {
  int f();
  vector<int> vi(100);
  int&& r1 = f();
  int& r2 = vi[0];
  int& r3 = r1;
  int&& r4 = vi[0] * f();
}

/**
 * 练习13.47：对你在练习13.44（13.5节，第470页）中定义的String类，
 * 为它的拷贝构造函数和拷贝赋值运算符添加一条语句，在每次函数执行时打印一条信息。
 */
void p13_47 () {
}

/**
 * 练习13.48：定义一个vector<String>并在其上多次调用push_back。
 * 运行你的程序，并观察String被拷贝了多少次。
 */
void p13_48 () {
  vector<String> vstr;
  String s0;
  String s1("hello");
  String s2(s0);
  String s3 = s1;

  vstr.push_back(s0);
  vstr.push_back(s1);
  vstr.push_back(s2);
  vstr.push_back(s3);
}

int main () {
  // p13_45();
  // p13_46();
  // p13_47();
  // p13_48();

  return 0;
}
