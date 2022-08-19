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
 * 练习4.1：表达式 5+10＊20/2 的求值结果是多少？
 */
int p4_01 () {
  cout << 5 + 10 * 20 / 2 << endl;

  // 105
  return 0;
}
/**
 * 练习4.2：根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。
 */
int p4_02 () {
  vector<int> vec = {1, 2, 3};
  // (a)
  *(vec.begin());
  // (b)
  *(vec.begin()) + 1;
  return 0;
}

/**
 * 练习4.3：C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。
 * 这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡，你认为这可以接受吗？请说出你的理由。
 */
int p4_03 () {
  // 不能接受不可预测的代码，对于没有规定的，自己手动加上括号来强制
  return 0;
}

int main () {
  p4_01();
  p4_02();
  // p4_03();

  return 0;
}
