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

/**
 * 练习6.10：编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。
 */
void switchValue (int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}
void p6_10 () {
  int a = 10;
  int b = 16;
  cout << "before: " << "a: " << a << ", " << &a << ", b: " << b  << ", " << &b << endl;
  switchValue(&a, &b);
  cout << "then: " << "a: " << a << ", " << &a << ", b: " << b  << ", " << &b << endl;
}

/**
 * 练习6.11：编写并验证你自己的reset函数，使其作用于引用类型的参数。
 */
void reset (int &i) {
  i = 0;
}
void p6_11 () {
  int i = 12;
  cout << "before i: " << i << endl;
  reset(i);
  cout << "then i: " << i << endl;
}

/**
 * 练习6.12：改写6.2.1节中练习6.10（第188页）的程序，使用引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？
 */
void switchValueByReference (int &a, int &b) {
  int temp = b;
  b = a;
  a = temp;
}
void p6_12 () {
  int a = 10;
  int b = 16;
  cout << "before: " << "a: " << a << ", " << &a << ", b: " << b  << ", " << &b << endl;
  switchValueByReference(a, b);
  cout << "then: " << "a: " << a << ", " << &a << ", b: " << b  << ", " << &b << endl;
}

/**
 * 练习6.13：假设T是某种类型的名字，说明以下两个函数声明的区别：一个是void f（T），另一个是void f（&T）。
 */
void p6_13 () {
  // void f（T） 表示 传值参数
  // void f（&T）表示 传引用参数
}

/**
 * 练习6.14：举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。
 */
void p6_14 () {
  // 形参应该是引用类型：如上的 switchValue 函数
  // 形参不能是引用类型：实参是右值不行
}

/**
 * 练习6.15：说明find_char函数中的三个形参为什么是现在的类型，
 * 特别说明为什么s是常量引用而occurs是普通引用？
 * 为什么s和occurs是引用类型而c不是？
 * 如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？
 */
string::size_type find_char(const string &s, char c, string::size_type &occurs) {
  auto ret = s.size();
  occurs = 0;

  for (decltype(ret) i = 0; i != s.size(); ++i) {
    if (s[i] == c) {
      if (ret == s.size()) {
        ret = i;
      }
      ++occurs;
    }
  }
  return ret;
}
void p6_15 () {
  // s 不能被修改（字符串可能很长，尽可能使用引用避免拷贝），occurs 可以被修改
  // 只需要 c 的值，实参可能会是右值
  // 不会发生什么情况（但可能会意外改变字符串内容）
  // occurs 就不能被修改，函数失去意义
}

/**
 * 练习6.16：下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
 */
bool is_empty (const string &s) {
  return s.empty();
}
void p6_16 () {
  // 常量字符串和字符串字面值无法作为该函数的实参
  // 加个 const
  const string str;
  bool strIsEmpty = is_empty(str);
  bool asdIsEmpty = is_empty("asd");
}

/**
 * 练习6.17：编写一个函数，判断string对象中是否含有大写字母。
 * 编写另一个函数，把string对象全都改成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？
 */
bool str_has_upper (const string &s) {
  for (size_t i = 0; i < s.size(); i++) {
    if (std::isupper(s[i])) {
      return true;
    }
  }
  return false;
}
bool str_to_lower (string &s) {
  for (size_t i = 0; i < s.size(); i++) {
    if (std::isupper(s[i])) {
      s[i] = std::tolower(s[i]);
    }
  }
  return false;
}

void p6_17 () {
  string str = "abcEFg";
  if (str_has_upper(str)) {
    cout << str << "存在大写" << endl;
    str_to_lower(str);
    cout << str << "已全部转为小写" << endl;
  }
}

/**
 * 练习6.18：为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。
 */
struct matrix {};
// a
bool compare(const matrix &m1, const matrix &m2);
// b
vector<int> change_val(int i, vector<int>::iterator iter);

void p6_18 () {
  // 如上
}

/**
 * 练习6.19：假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
 */
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
void p6_19 () {
  vector<int> vec(10);
  // // a
  // calc(24.4 /**, 55.1*/); // ❌ 多传了参数
  // // b
  // count("abcda", 'a'); // 没问题
  // // c
  // calc(66); // 没问题
  // // d
  // sum(vec.begin(), vec.end(), 3.8); // double 会被转为 int
}

/**
 * 练习6.20：引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？
 */
void p6_20 () {
  // 不被修改，允许使用字符串字面值时使用常量引用
  // 可能会被修改
}

/**
 * 练习6.21：编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。
 * 函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？
 */
int compareNum(int a, int *b) {
  if (a > *b) {
    return a;
  }
  return *b;
}
void p6_21 () {
  int a = 5;
  int b = 6;

  cout << "比较大值结果：" << compareNum(a, &b) << endl;
}

/**
 * 练习6.22：编写一个函数，令其交换两个int指针。
 */
void switchIntPoint(int *&a, int *&b) {
  auto temp = a;
  a = b;
  b = temp;
}
void p6_22 () {
  int a = 5;
  int b = 6;
  int *ap = &a;
  int *bp = &b;

  switchIntPoint(ap, bp);
  cout << "ap：" << *ap << "; bp：" << *bp << endl;
  cout << "a：" << a << "; b：" << b << endl;
}

/**
 * 练习6.23：参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j：
 * int i = 0, j[2] = {0, 1};
 */
void print(const int *beg, const int *end) {
  while (beg != end) {
    cout << *beg << endl;
    beg++;
  }
}
void print(int (&arr)[2]) {
  for (auto i : arr) {
    cout << i << endl;
  }
}
void print(const int arr[], const size_t size) {
  for (size_t i = 0; i < size; ++i) {
    cout << arr[i] << endl;
  }
}
void print(const int *n) {
  cout << *n << endl;
}
void p6_23 () {
  int i = 0, j[2] = {0, 1};
  print(std::begin(j), std::end(j));
  print(j);
  print(j, std::size(j));
  print(&i);
}

/**
 * 练习6.24：描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
 */
void print (const int (&ia)[10]) {
  for (size_t i = 0; i != 10; ++i) {
    cout << ia[i] << endl;
  }
}
void p6_24 () {
  // 形参 ia 加上一个 &。
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  print(arr);
}

int main () {
  p6_10();
  p6_11();
  p6_12();
  p6_13();
  p6_14();
  p6_15();
  p6_16();
  p6_17();
  p6_18();
  p6_19();
  p6_20();
  p6_21();
  p6_22();
  p6_23();
  p6_24();

  return 0;
}
