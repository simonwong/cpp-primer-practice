#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <map>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/**
 * 练习12.23：编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的char数组中。
 * 重写这个程序，连接两个标准库string对象。
 */
void mergeChar (const char* a, const char* b) {
  char* res = new char[strlen(a) + strlen(b) + 1];
  strcpy(res, a);
  strcat(res, b);
  cout << res << endl;
  delete [] res;
}
void mergeString (const string a, const string b) {
  cout << a + b << endl;
}
void p12_23 () {
  mergeChar("Hello ", "Word");
  mergeString("Hello ", "Word");
}

/**
 * 练习12.24：编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。
 * 描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。
 */
void p12_24 () {
  auto *p = new string[10];
  string word;
  int i = 0;
  while (cin >> word) {
    *(p + i) = word;
    ++i;
  }

  delete [] p;
}

/**
 * 练习12.25：给定下面的new表达式，你应该如何释放pa？
 */
void p12_25 () {
  int *pa = new int[10];

  delete [] pa;
}

/**
 * 练习12.26：用allocator重写第427页中的程序。
 */
void p12_26 () {
  int n = 5;
  std::allocator<string> alloc;
  auto const p = alloc.allocate(n);
  string s;
  auto q = p;
  while (q != p + n && cin >> s) {
    alloc.construct(q++, s);
  }
  while (q != p) {
    cout << *--q << " ";
    alloc.destroy(q);
  }
  alloc.deallocate(p, n);
}

int main () {
  p12_23();
  p12_24();
  p12_25();
  p12_26();

  return 0;
}
