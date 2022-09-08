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

/**
 * 练习4.36：假设i是int类型，d是double类型，书写表达式i＊=d使其执行整数类型的乘法而非浮点类型的乘法。
 */
int p4_36 () {
  int i = 1;
  double d = 2.4;
  i *= static_cast<int>(d);

  cout << i << endl;
  return 0;
}

/**
 * 练习4.37：用命名的强制类型转换改写下列旧式的转换语句。
 */
int p4_37 () {
  int i; double d; const string *ps; char *pc; void *pv;

  // a
  // pv = (void*)ps;
  pv = static_cast<void*>(const_cast<string*>(ps));
  // b
  // i = int(*pc);
  i = static_cast<int>(*pc);
  // c
  // pv = &d;
  pv = static_cast<void*>(&d);
  // d
  // pc = (char*) pv;
  pc = static_cast<char*>(pv);
  return 0;
}

/**
 * 练习4.38：说明下面这条表达式的含义。
 */
int p4_38 () {
  int j = 3;
  int i = 2;
  // j / i 的结果强制类型转为 double 类型
  double slope = static_cast<double>(j / i);
  return 0;
}

int main () {
  p4_34();
  p4_35();
  p4_36();
  p4_37();
  p4_38();

  return 0;
}
