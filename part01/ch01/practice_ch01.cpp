#include <iostream>

using std::string;

int p1_1 () {
  return 0;
}

int p1_2 () {
  return -1;
}

int p1_3_hello_world () {
  std::cout << "Hello World!" << std::endl;

  return 0;
}

int p1_4 () {
  std::cout << "2 3 相加：" << 2 + 3 << std::endl;
  std::cout << "3 6 相乘：" << 3 * 6 << std::endl;

  return 0;
}

int p1_5 () {
  std::cout << "5 3 相减：" << 5 - 3 << std::endl
  << "9 3 相除：" << 9 / 3 << std::endl;

  return 0;
}

int p1_6 () {
  int v1 = 66;
  int v2 = 88;
  // 原题不合法，不应该加封号
  std::cout << "The Sum of " << v1
            << " and " << v2
            << " is " << v1 + v2 << std::endl;
  return 0;
}

int main () {
  p1_1();
  p1_2();
  p1_3_hello_world();
  p1_4();
  p1_5();
  p1_6();

  return 0;
}
