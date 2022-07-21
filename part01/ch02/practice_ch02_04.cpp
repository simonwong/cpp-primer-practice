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
  const int *p1 = &i2; // 合法，p1 是一个指向 i2 的常量
  // (f)
  // const int &const r2; // ❌ 不合法，必须要有一个初始化值
  // (g)
  const int ig = i, &rg = i; // 合法，i2 是一个常量，rg 是一个常量引用。
  return 0;
}

int p2_28 () {
  // (a)
  // int i, *const cp; //  ❌ 不合法，cp 是一个指针常量必须要初始化
  // (b)
  // int *p1, *const p2; // p1 是一个 int 类型指针； ❌ 不合法，p2 是一个指针常量必须要初始化
  // (c)
  // const int ic, &r = ic; // ❌ 不合法，ic 是 int 类型常量必须要初始化
  // (d)
  // const int *const p3; // ❌ 不合法，p3 必须要初始化
  // (e)
  const int *p; // 合法，p 是一个要指向 const int 的指针
}

int p2_29 () {
  // (a)
  int i;
  const int ic = 123;
  i = ic; // 合法，常量赋值给普通常量
  // (b)
  int *p1 = &i;
  const int *const p3 = &i;
  // p1 = p3; // ❌ 不合法 p3 是 const 指针不能赋值给普通指针
  // (c)
  // p1 = &ic; // ❌ 不合法，普通指针不能指向常量
  // (d)
  // p3 = &ic; // ❌ 不合法，p3 是 const 指针，不能重新赋值
  // (e)
  int *p1;
  int *const p2 = &i;
  // p2 = p1 // ❌ 不合法，p2 是常量不能修改
  // (f)
  // ic = *p3 // ❌ 不合法，ic 是常量不能修改
}

int main () {
  // p2_26();
  p2_27();
  // p2_28();
  // p2_29();

  return 0;
}
