#include <iostream>

using std::string;

// 有符号和无符号一起运算，回转成无符号类型。

int main () {
  string hel = "hello world";


  for (auto ct : hel) {
    std::cout << ct << std::endl;
  }

  std::cout << hel << std::endl;

  return 0;
}
