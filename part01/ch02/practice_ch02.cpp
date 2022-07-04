#include <iostream>

int p2_1 () {
  // short、int、long、long long 区别
  // 都是带符号的，添加 unsigned 可以得到无符号类型
  short shortNum = 32767;
  int intNum = 2147483647;
  long longNum = 2147483647L;
  long long longLongNum = 9223372036854775807LL;

  std::cout << "[short] max: " << shortNum << std::endl;
  std::cout << "[int] max: " << intNum << std::endl;
  std::cout << "[long] max: " << longNum << std::endl;
  std::cout << "[long long] max: " << longLongNum << std::endl;

  // 0 到 65,535
  unsigned short unsignedShortNum = 65535;
  std::cout << "[unsigned short] max: " << unsignedShortNum << std::endl;

  // 0 到 4,294,967,295
  unsigned int unsignedIntNum = 4294967295U;
  std::cout << "[unsigned int] max: " << unsignedIntNum << std::endl;

  // 0 到 4,294,967,295
  unsigned long unsignedLongNum = 4294967295UL;
  std::cout << "[unsigned long] max: " << unsignedLongNum << std::endl;

  // 0 到 18,446,744,073,709,551,615
  unsigned long long unsignedLongLongNum = 18446744073709551615ULL;
  std::cout << "[unsigned long long] max: " << unsignedLongLongNum << std::endl;

  float floatNum = 3.4E+38; // 单精度浮点数
  std::cout << "[float] max: " << floatNum << std::endl;

  double doubleNum = 1.7E+308; // 双精度浮点数
  std::cout << "[double] max: " << doubleNum << std::endl;

  return 0;
}

int p2_2 () {
  // 利率、本金、付款：使用 double
  return 0;
}

int p2_3_4 () {
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl; // 32
  // 超出 unsigned 表示范围
  std::cout << u - u2 << std::endl; // 4294967264 (-32 对 4294967296 取余数)

  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl; // 32
  std::cout << i - i2 << std::endl; // -32
  std::cout << i - u << std::endl; // 0
  std::cout << u - i << std::endl; // 0

  return 0;
}

int p2_5 () {
  std::cout
    << 'a' << std::endl // char
    << L'a' << std::endl // 宽字符
    << "a" << std::endl // 字符串由 'a' 和 '/0' 组成
    << L"a" << std::endl; // 宽字符串

  std::cout
    << 10 << std::endl // int
    << 10u << std::endl // unsigned int
    << 10L << std::endl // long
    << 10UL << std::endl // unsigned long
    << 012 << std::endl // 八进制
    << 0xc << std::endl; // 十六进制

  std::cout
    << 3.14 << std::endl // double
    << 3.14f << std::endl // float
    << 3.14L << std::endl; // long double

    std::cout
      << 10 << std::endl // int
      << 10u << std::endl // unsigned int
      << 10. << std::endl // double
      << 10e-2 << std::endl; // double 科学表达

  return 0;
}

int p2_6 () {
  int month = 9, day = 7;
  // int month2 = 09, day2 = 07;
  // 09 是无效的八进制，07 是八进制，结果为 7
  return 0;
}

int p2_7 () {
  std::cout << "Who goes with F\145rgus?\012" << std::endl; // \145 转义为 e， \012 转义为换行符
  std::cout << 3.14e1L << std::endl; // 0.314 long double
  // std::cout << 1024f << std::endl; // 错误的表示， f 前面只能用于浮点字面量
  std::cout << 3.14L << std::endl; // 3,14 long double
  return 0;
}

int p2_8 () {
  std::cout << "2\115\012";
  std::cout << "2\t\115\012";
  return 0;
}

int p2_9 () {
  // std::cin >> int input_value; // 不合法：input_value 需要先初始化
  // int i = { 3.14 }; // 不合法：花括号初始化对于可能丢失信息时会报错
  // double salary = wage = 9999.99; // 不合法：wage 未定义
  int i = 3.14; // warning，小数位会被截断
  return 0;
}



int p2_10 () {
  // 假设这里是在全局环境
  // std::string global_str; // 空字符串
  // int global_int; // 0
  // int main () {
  //   int local_int; // 没有初始化，未定义
  //   std::string local_str; // 没有初始化，值由类确定，为空字符串
  // }
  return 0;
}

int main () {
  p2_1();
  p2_2();
  p2_3_4();
  p2_5();
  p2_6();
  p2_7();
  p2_8();
  p2_9();
  p2_10();

  return 0;
}
