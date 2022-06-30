#include <iostream>

int p2_1 () {
  // short、int、long、long long 区别
  // 都是带符号的，添加 unsigned 可以得到无符号类型
  short shortNum = 32767;
  int intNum = 2147483647;
  long longNum = 2147483647;
  long long longLongNum = 9223372036854775807;

  std::cout << "shortNum: " << shortNum << std::endl;
  std::cout << "intNum: " << intNum << std::endl;
  std::cout << "longNum: " << longNum << std::endl;
  std::cout << "longLongNum: " << longLongNum << std::endl;

  return 0;
}

int main () {
  p2_1();

  return 0;
}
