#include <iostream>

int p2_26 () {
  // const int buf; // 不合法：const 限定符需要初始化
  int cnt = 0;
  const int sz = cnt;
  ++cnt;
  // ++sz; // 不合法，const 限定符不能修改值
  return 0;
}

int main () {
  // p2_26();

  return 0;
}
