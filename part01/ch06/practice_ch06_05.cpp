#include <iostream>
#include <string>
#include <vector>
#include "Chapter6.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;
using std::initializer_list;

/**
 * 练习6.40：下面的哪个声明是错误的？为什么？
 */
void p6_40 () {
  // a ✅
  // int ff(int a, int b = 0, int c = 0);

  // b ❌ 默认实参必须定义为末尾
  // char *init(int ht = 24, int wd, char bckgrnd);
}

/**
 * 练习6.41：下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
 */
char *init(int ht, int wd = 80, char bckgrnd = ' ');
void p6_41 () {
  // a ❌ 没有传实参 ht
  // init();

  // b ✅
  // init(24, 10);

  // c  ❌ 不能省略前面的实参
  // init(14, '*');
}

/**
 * 练习6.42：给make_plural函数（参见6.3.2节，第201页）的第二个形参赋予默认实参's'，
 * 利用新版本的函数输出单词success和failure的单数和复数形式。
 */
string make_plural(size_t ctr, const string& word, const string& ending = "s") {

}
void p6_42 () {
  make_plural(10, "Hello");
}

/**
 * 练习6.43：你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
 */
// a
inline bool eq(const int&, const int&);
// b
void putValues(int *arr, int size);

void p6_43 () {
  // a , eq 放在
}

/**
 * 练习6.44：将6.2.2节（第189页）的isShorter函数改写成内联函数。
 */
inline bool isShorter(const string &lft, const string &rht) {
  return lft.size() < rht.size();
}

void p6_44 () {
  cout << isShorter("pezy", "moo") << endl;
}

/**
 * 练习6.45：回顾在前面的练习中你编写的那些函数，它们应该是内联函数吗？如果是，将它们改写成内联函数；如果不是，说明原因
 */
void p6_45 () {
}

/**
 * 练习6.46：能把isShorter函数定义成constexpr函数吗？如果能，将它改写成constexpr函数；如果不能，说明原因。
 */
void p6_46 () {
  // 不能，x < y 不是常量表达式
}

/**
 * 练习6.47：改写6.3.2节（第205页）练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。
 * 例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。
 */
void printVec(vector<int> &vec) {
  #ifndef NDEBUG
    cout << "vector size: " << vec.size() << endl;
  #endif

  if (!vec.empty()) {
    auto tmp = vec.back();
    vec.pop_back();
    printVec(vec);
    cout << tmp << " ";
  }
}
void p6_47 () {
  vector<int> vec = {1,2,3,4,5};
  printVec(vec);
  cout << endl;
}

/**
 * 练习6.48：说明下面这个循环的含义，它对assert的使用合理吗？
 */
void p6_48 () {
  string s;
  string sought = "ASD";

  while (cin >> s && s != sought) {

  }

  // 不合理， asset cin 没有意义
  assert(cin);
}

int main () {
  // p6_40();
  p6_41();
  p6_42();
  // p6_43()
  p6_44();
  // p6_45();
  p6_46();
  p6_47();
  p6_48();

  return 0;
}
