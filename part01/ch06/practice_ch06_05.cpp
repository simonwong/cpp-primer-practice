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
 * 练习6.40：下面的哪个声明是错误的？为什么？
 */
void p6_40 () {
  // a ✅
  // int ff(int a, int b = 0, int c = 0);

  // b ❌ 默认实参必须定义为末尾
  // char *init(int ht = 24, int wd, char bckgrnd);
}

/**
 * 练习6.41：下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
 */
char *init(int ht, int wd = 80, char bckgrnd = ' ');
void p6_41 () {
  // a ❌ 没有传实参 ht
  // init();

  // b ✅
  init(24, 10);

  // c  ❌ 不能省略前面的实参
  // init(14, '*');
}

/**
 * 练习6.42：给make_plural函数（参见6.3.2节，第201页）的第二个形参赋予默认实参's'，
 * 利用新版本的函数输出单词success和failure的单数和复数形式。
 */
string make_plural(size_t ctr, const string& word, const string& ending = "s") {

}
void p6_42 () {
  make_plural(10, "Hello");
}


int main () {
  // p6_40();
  p6_41();
  p6_42();

  return 0;
}
