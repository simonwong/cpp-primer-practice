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
 * 练习4.34：根据本节给出的变量定义，说明在下面的表达式中将发生什么样的类型转换
 */
int p4_34 () {
  // a
  // float 类型转 布尔类型
  // if (fval)

  // b
  // float 转 double，int 转 double
  // dval = fval + ival

  // c
  // chat 转 int，得到乘的结果，int 转 double
  // dval + ival * cval
  return 0;
}

/**
 * 练习4.35：假设有如下的定义
 */
int p4_35 () {
  char cval;
  int ival;
  unsigned int ui;
  float fval;
  double dval;

  // a
  cval = 'a' + 3; // 'a' 转 int，相加后转 char
  // b
  fval = ui - ival * 1.0; // int 转 double，相乘结果转 double，unsigned int 转 double，结果转 float
  // c
  dval = ui * fval; // unsigned int 转 float ，结果转 double
  // d
  cval = ival + fval + dval; // int 转 float，结果转 double，最后转为 char
  return 0;
}

int main () {
  p4_34();
  p4_35();

  return 0;
}
