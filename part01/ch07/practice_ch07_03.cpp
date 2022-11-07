#include <iostream>
#include <string>
#include <vector>
#include "Screen_23_24.h"
#include "Screen_27.h"

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

/**
 * 练习7.27：给你自己的Screen类添加move、set和display函数，通过执行下面的代码检验你的类是否正确。
 */
void p7_27 () {
  Screen_27 myScreen(5, 5, 'x');
  myScreen.move(4, 0).set('#').display(cout);
  cout << endl;
  myScreen.display(cout);
}
/**
 * 练习7.28：如果move、set和display函数的返回类型不是Screen&而是Screen，则在上一个练习中将会发生什么情况？
 *
 * 练习7.29：修改你的Screen类，令move、set和display函数返回Screen并检查程序的运行结果，在上一个练习中你的推测正确吗？
 */
void p7_28_29 () {
  // 将仅是对 myScreen 的拷贝进行修改，所以 myScreen 不会有任何修改
}
/**
 * 练习7.30：通过this指针使用成员的做法虽然合法，但是有点多余。讨论显式地使用指针访问成员的优缺点。
 */
void p7_30 () {
  // 优点：
  // 更加明确
  // 避免误读
  // 可以使用与形参相同的成员

  // 缺点：
  // 阅读代码更多
  // 比较冗余
}

/**
 * 练习7.31：定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。
 */
class X {
  Y *yp = nullptr;
};
class Y {
  X x;
};
void p7_31 () {
}

/**
 * 练习7.32：定义你自己的Screen和Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。
 */
void p7_32 () {
}

/**
 * 练习7.33：如果我们给Screen添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。
 */
// Screen_32::pos Screen_32::size() const {
//   return height * width;
// }
void p7_33 () {
  // 如上，需要添加 Screen_32::，pos 是定义在 Screen_32 内的类型
}



int main () {
  p7_23_24();
  // p7_25();
  // p7_26();
  p7_27();
  // p7_28_29();
  // p7_30();
  // p7_31();
  p7_32();
  // p7_33();

  return 0;
}
