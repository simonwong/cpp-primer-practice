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

int p2_18 () {
  int i = 20;
  int *ip = &i;
  std::cout << "初始：" << "i: " << i << ", *ip: " << *ip << std::endl;
  *ip = 10;
  std::cout << "通过指针改变值：" << "i: " << i << ", *ip: " << *ip << std::endl;
  int i2 = 15;
  ip = &i2;
  std::cout << "改变指针：" << "i: " << i << ", *ip: " << *ip << std::endl;

  return 0;
}

int p2_19 () {
  // 指针和引用的区别：
  // 指针：存放的是对象的地址，可以修改，可以不初始化值
  // 引用：可以理解为是对象的另一个名字，会跟对象绑定，必须要初始化

  return 0;
}

int p2_20 () {
  int i = 42;
  int *p1 = &i; // 赋值 p1指针为 i 的地址
  *p1 = *p1 * *p1; // *p1 就是指针指向地址的值，就是 42，42 * 42 = 1764，最后改变了地址的值，i 也变成了 1764
  std::cout << "*p1: " << *p1 << ", i: " << i << std::endl;

  return 0;
}

int p2_21 () {
  int i = 0;
  // a
  // double *dp = &i; // 不合法，指针类型必须要一样
  // b
  // int *ip = i; // 不合法，必须是个地址
  // c
  int *p = &i; // 可以
  return 0;
}

int p2_22 () {
  int *p0 = nullptr;

  if (p0) {
    // 没有指针地址，所以不会进来 ❌
    std::cout << "p0: " << p0 << std::endl;
  }
  // if (*p0) { // 空指针
  //   // 为 0 ，所以不会进来 ❌
  //   std::cout << "*p0: " << *p0 << std::endl;
  // }

  int i1 = 0;
  int *p1 = &i1;

  if (p1) {
    // 有地址值，所以可以 ✅
    std::cout << "p1: " << p1 << std::endl;
  }
  if (*p1) {
    // 为 0 ，所以不会进来 ❌
    std::cout << "*p1: " << *p1 << std::endl;
  }


  int i2 = 1;
  int *p2 = &i2;

  if (p2) {
    // 有地址值，所以可以 ✅
    std::cout << "p2: " << p2 << std::endl;
  }
  if (*p2) {
    // 为 1 ，所以可以 ✅
    std::cout << "*p2: " << *p2 << std::endl;
  }

  return 0;
}

int p2_23 () {
  // 给定指针p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因
  // 不能，首先要确定指针是否合法。
  // 只要指针拥有一个合法值，就能用在条件表达式中，来判断。
  // 指针值是 0 ，则为 false
  // 指针值是 非0，则为 true
  return 0;
}

int p2_24 () {
  // 在下面这段代码中为什么p合法而lp非法
  int i = 42;
  void *p = &i; // void * 可以存放任意类型的指针
  // long *lp = &i; // 不合法因为类型不对
  return 0;
}

int p2_25 () {
  // ip 是 int 类型指针，没有指向任何地址
  // i 是 int 对象，没有初始值
  // r 是对象 i 的引用
  int *ip, i, &r = i;

  // i 是 int 对象，没有初始值
  // ip 是一个空指针
  int i, *ip = 0;

  // ip 是 int 类型指针，没有指向任何地址
  // ip2 是 int 对象，没有初始值
  int *ip, ip2;

  return 0;
}

int main () {
  // p2_15();
  // p2_16();
  p2_17();
  p2_18();
  // p2_19();
  p2_20();
  // p2_21();
  p2_22();
  // p2_23();
  // p2_24();
  // p2_25();

  return 0;
}
