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
 * 练习4.8：说明在逻辑与、逻辑或及相等性运算符中运算对象求值的顺序。
 */
int p4_08 () {
  // 相等 > 逻辑与 > 逻辑或
  return 0;
}

/**
 * 练习4.9：解释在下面的if语句中条件部分的判断过程。
 */
int p4_09 () {
  const char *cp = "Hello World";
  // 如果存在指针 cp，且指针指向的地址值不为 0
  if (cp && *cp) {
    cout << *cp << endl;
  }
  return 0;
}

/**
 * 练习4.10：为 while 循环写一个条件，使其从标准输入中读取整数，遇到42时停止。
 */
int p4_10 () {
  int val;
  while (cin >> val && val != 42) {
    cout << val << endl;
  }

  return 0;
}

/**
 * 练习4.11：书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。
 */
int p4_11 () {
  int a = 5;
  int b = 4;
  int c = 3;
  int d = 2;

  if (a > b && b > c && c > d) {
    cout << "验证正确" << endl;
  }

  return 0;
}

/**
 * 练习4.12：假设i、j和k是三个整数，说明表达式i！=j<k的含义。
 */
int p4_12 () {
  int i = 1;
  int j = 3;
  int k = 4;

  // 相当于 i != (j < k)
  // < 的优先级大于 !=，所以先得到 j < k 的结果
  // j < k 的结果是布尔值
  // i 与布尔值比较，布尔值会被转为 1 或 0，i 只有是 1 时才为真
  if (i != j < k) {
    cout << "验证正确" << endl;
  }

  return 0;
}

int main () {
  p4_08();
  p4_09();
  p4_10();
  p4_11();
  p4_12();

  return 0;
}
