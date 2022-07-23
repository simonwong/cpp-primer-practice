#include <iostream>

int p2_33_34 () {
  int i = 0, &r = i; // i 是 int，r 是 i 的别名
  auto a = r; // a 是 int

  const int ci = i, &cr = ci; // ci 是 顶层 const，cr 是 ci 的别名
  auto b = ci; // b 是 int，const 特性被忽略了
  auto c = cr; // c 是 int
  auto d = &i; // d 是 int 指针
  auto e = &ci; // e 是指向 int 常量的指针

  const auto f = ci; // f 是 const int
  auto &g = ci; // g 是 ci 的别名

  a = 42; // 合法
  b = 42; // 合法
  c = 42; // 合法
  // d = 42; // ❌ 不合法
  // e = 42; // ❌ 不合法
  // f = 42; // ❌ 不合法
  // g = 42; // ❌ 不合法

  return 0;
}

int p2_35 () {
  const int i = 42;

  auto j = i; // j 是 int，顶层 const 被忽略
  const auto &k = i; // k 是 int 常量引用
  auto *p = &i; // p 是 int 指针
  const auto j2 = i; // j2 是 int 常量
  const auto &k2 = i; // 同 k
  return 0;
}

int p2_36 () {
  int a = 3, b =4;
  decltype(a) c = a; // c 是 int
  decltype((b)) d = a; // d 是 a 的引用
  ++c; // 4
  ++d; // 4

  std::cout << "c: " << c << "; d: " << d << std::endl;
  return 0;
}

int p2_37 () {
  int a = 3, b = 4;
  decltype(a) c = a; // c 是 int，值为 3
  decltype(a = b) d = a; // d 是 a 的引用，值为 3

  return 0;
}

int p2_38 () {
  // decltype 和 auto 指定类型区别

  int i= 1, &r = i;
  // 相同
  auto a = i;
  decltype(i) b = i;

  // 不同, c 是 int，d 是 int&
  auto c = r;
  decltype(r) d = i;

  return 0;
}

int main () {
  // p2_33_34();
  // p2_35();
  p2_36();
  // p2_37();
  // p2_38();

  return 0;
}
