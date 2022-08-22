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
 * 练习4.4：在下面的表达式中添加括号，说明其求值的过程及最终结果。
 * 编写程序编译该（不加括号的）表达式并输出其结果验证之前的推断。
 */
int p4_04 () {
  cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;

  // 4 * 4 + 75 + 0 / 2
  // 91

  return 0;
}

/**
 * 练习4.5：写出下列表达式的求值结果。
 */
int p4_05 () {
  // a -86 小数点被省略了
  cout << -30 * 3 + 21 / 5 << endl;

  // b -18
  cout << -30 + 3 * 21 / 5 << endl;

  // c 0
  cout << 30 / 3 * 21 % 5 << endl;

  // d -2
  cout << -30 / 3 * 21 % 4 << endl;

  return 0;
}

int p4_06 () {
  int a = 23;

  if (a % 2 == 0) {
    cout << "偶数" << endl;
  } else {
    cout << "奇数" << endl;
  }

  return 0;
}

int p4_07 () {
  int a = 456 * 567 * 678 * 789 * 890;

  int b = 1 / 0;

  short c = 32767 + 1;

  return 0;
}

int main () {
  p4_04();
  p4_05();
  p4_06();
  p4_07();

  return 0;
}
