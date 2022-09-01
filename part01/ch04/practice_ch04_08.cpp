#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;

/**
 * 练习4.25：如果一台机器上int占32位、char占8位，用的是Latin-1字符集，
 * 其中字符'q'的二进制形式是01110001，那么表达式~'q'<<6的值是什么？
 */
int p4_25 () {
  // 首先 q 会被提升 0000 0000 0000 0000 0000 0000 0111 0001
  // ~取反          1111 1111 1111 1111 1111 1111 1000 1110
  // 左移 6 位      1111 1111 1111 1111 1110 0011 1000 0000
  cout << (~'q' << 6) << endl;
  return 0;
}

/**
 * 练习4.26：在本节关于测验成绩的例子中，如果使用 unsigned int 作为 quiz1 的类型会发生什么情况？
 */
int p4_26 () {
  // 有些环境的 unsigned int 是 16 位的，结果会为未定义
  return 0;
}

/**
 * 练习4.27：下列表达式的结果是什么？
 */
int p4_27 () {
  unsigned long ul1 = 3, ul2 = 7;
  // a
  cout << (ul1 & ul2) << endl; // 3
  // b
  cout << (ul1 | ul2) << endl; // 7
  // c
  cout << (ul1 && ul2) << endl; // true（1）
  // d
  cout << (ul1 || ul2) << endl; // true（1）
  return 0;
}

int main () {
  p4_25();
  p4_26();
  p4_27();

  return 0;
}
