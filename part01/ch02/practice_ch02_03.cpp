#include <iostream>

int p2_15 () {
  int iVal = 1.01; // warning：会丢失精度
  // int &rVal1 = 1.01; // 错误，必须绑定对象
  int &rVal2 = iVal;
  // int &rVal3; // 错误，必须初始化
  return 0;
}

int p2_16 () {
  int i = 0, &r1 = i;
  double d = 0, &r2 = d;

  r1 = 3.14159; // 合法：类型转换，将会丢失精度，值为 3，同是 i 的值也成了 3；
  r2 = r1; // 合法：类型转换
  i = r2; // 合法：类型转换
  r1 = d; // 合法：类型转换

  return 0;
}

int p2_17 () {
  int i, &ri = i;
  i = 5; ri = 10; // 因为 ri 是 i 的引用，所以都是 10

  std::cout << i << " " << ri << std::endl;
  return 0;
}

int main () {
  // p2_15();
  // p2_16();
  p2_17();

  return 0;
}
