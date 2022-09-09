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
 * 练习5.1：什么是空语句？什么时候会用到空语句？
 */
int p5_01 () {
  // 空语句是
  // 语法上需要语句，但逻辑上不需要，那么可以使用空语句
  return 0;
}

/**
 * 练习5.2：什么是块？什么时候会用到块？
 */
int p5_02 () {
  // 块是 {} 花括号括起来的语句
  //
  return 0;
}

/**
 * 练习5.3：使用逗号运算符（参见4.10节，第140页）重写1.4.1节（第10页）的while循环，
 * 使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。
 */
int p5_03 () {
  // 代码可读性降低
  int sum = 0;
  int val = 1;
  while (val <= 10)
    sum += val, ++val;
  return 0;
}

int main () {
  p5_01();
  p5_02();
  p5_03();

  return 0;
}
