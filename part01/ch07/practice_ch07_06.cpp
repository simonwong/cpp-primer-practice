#include <iostream>
#include <string>
#include <vector>
#include "Sales_data_41.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;
using std::initializer_list;


/**
 * 练习7.56：什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？
 */
void p7_56 () {
  // 静态成员与类本身直接相关，而不是与类的各个对象保持关系

  // 优点：
  // 每个对象不需要存储公共数据，如果数据发生改变，每个对象都可以使用新值。

  // 区别：
  // 静态数据成员可以具有不完整的类型
  // 可以使用静态数据成员作为默认参数
}

/**
 * 练习7.57：编写你自己的Account类。
 */
class Account {
public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double);
private:
  string owner;
  double amount;
  static double interestRate;
  static double initRate();
  static constexpr int period = 30;
  double daily_tbl[period];
};

void Account::rate(double newRate) {
  interestRate = newRate;
};
double Account::initRate() {
  return interestRate;
};
double Account::interestRate = initRate();

void p7_57 () {
}

/**
 * 练习7.58：下面的静态数据成员的声明和定义有错误吗？请解释原因。
 */
class Example {
public:
  static constexpr double rate = 6.5;
  static const int vecSize = 20;
  static vector<double> vec;
};

constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
void p7_58 () {
  // rate 应该是常量表达式

  // vec 不能直接设置类型初始值
}


int main () {
  // p7_56();
  p7_57();
  // p7_58();

  return 0;
}
