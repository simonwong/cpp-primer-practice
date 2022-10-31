#include <iostream>
#include <string>
#include <vector>
#include "Screen_23_24.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;
using std::initializer_list;

/**
 * 练习7.23：编写你自己的Screen类。
 *
 * 练习7.24：给你的Screen类添加三个构造函数：
 * 一个默认构造函数；
 * 另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；
 * 第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容;
 */
int p7_23_24 () {
  Screen_23_24 screen(3, 4, 'H');

  cout << screen.get() << endl;
}
/**
 * 练习7.25：Screen能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能，为什么？
 */
int p7_25 () {
  // Screen 仅使用了内置类型和 string
}
/**
 * 练习7.26：将Sales_data：：avg_price定义成内联函数。
 */
// 见 Sales_data_21.h
int p7_26 () {
}

int main () {
  p7_23_24();
  // p7_25();
  // p7_26();

  return 0;
}
