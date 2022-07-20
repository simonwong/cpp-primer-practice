#include <iostream>

int p2_26 () {
  // (a)
  // const int buf; // ❌ 不合法：const 限定符需要初始化
  // (b)
  int cnt = 0;
  // (c)
  const int sz = cnt;
  // (d)
  ++cnt;
  // (e)
  // ++sz; // ❌ 不合法，const 限定符不能修改值
  return 0;
}

int p2_27 () {
  // (a)
  // int i = -1, &r = 0; // ❌ 不合法，引用 r 必须引用一个对象
  int i2 = 12;
  // (b)
  int *const p2 = &i2; // 合法，p2 是一个常量指针
  // (c)
  const int i = -1, &r = 0; // 合法，i 是一个常量，r 是一个常量引用
  // (d)
  const int *const p3 = &i2; // 合法，p3 是一个指向常量对象的常量指针
  // (e)
  const int *p1 = &i2; // 合法，p1 是一个指向
  // (f)
  // const int &const r2; // ❌ 不合法，必须要有一个初始化值
  // (g)
  const int ig = i, &rg = i; // 合法，i2 是一个常量，rg 是一个常量引用。
  return 0;
}

int main () {
  // p2_26();
  p2_27();

  return 0;
}
