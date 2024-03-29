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
 * 练习6.30：编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。
 */
// bool str_subrange (const string &str1, const string &str2) {
//   if (str1.size() == str2.size()) {
//     return str1 == str2;
//   }
//   auto size = str1.size() < str2.size()
//     ? str1.size()
//     : str2.size();

//   for (decltype(size) i = 0; i != size; ++i) {
//     if (str1[i] != str2[i]) {
//       return;
//     }
//   }
// }
void p6_30 () {
  // error: non-void function 'str_subrange' should return a value [-Wreturn-type]
  // auto res = str_subrange("asd", "zxcd");
  // cout << res << endl;
}

/**
 * 练习6.31：什么情况下返回的引用无效？什么情况下返回常量的引用无效？
 */
const string &return_invalid_value () {
  return "asd";
}
void p6_31 () {
  // 如上，试图返回局部对象的引用
  // warning: returning reference to local temporary object [-Wreturn-stack-address]
  auto res = return_invalid_value();
  cout << res << endl;
}

/**
 * 练习6.32：下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
 */
// int &get (int *array, int index) {
//   return array[index];
// }
// int main () {
//   int ia[10];
//   for (size_t i = 0; i != 10; ++i) {
//     get(ia, i) = i;
//   }
// }
void p6_32 () {
  // get 函数合法
  // ❌ main 函数不合法，没有 return 值
}

/**
 * 练习6.33：编写一个递归函数，输出vector对象的内容。
 */
void printVector (vector<int>::const_iterator beg, vector<int>::const_iterator end) {
  if (beg != end) {
    cout << *beg << endl;
    printVector(++beg, end);
  }
}
void p6_33 () {
  vector<int> vec = {6,5,4,3,2,1};
  printVector(vec.begin(), vec.end());
}

/**
 * 练习6.34：如果factorial函数的停止条件如下所示，将发生什么情况？
 * if (val != 0)
 *
 * 练习6.35：在调用factorial函数时，为什么我们传入的值是val-1而非val--？
 */
void p6_34_35 () {
  // 当 val 为 负数时，递归将不会终止

  // val-- 会改变 val 的值
}

/**
 * 练习6.36：编写一个函数的声明，使其返回数组的引用并且该数组包含10个string对象。
 * 不要使用尾置返回类型、decltype或者类型别名。
 *
 * 练习6.37：为上一题的函数再写三个声明，
 * 一个使用类型别名，
 * 另一个使用尾置返回类型，
 * 最后一个使用decltype关键字。你觉得哪种形式最好？为什么？
 */
string (*getStringArr(int i))[10];

// typedef
typedef string StringArr[10];
StringArr *getStringArr(int i);

// 尾置
auto getStringArr(int i) -> string(*)[10];

// decltype
string myStrArr[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
decltype(myStrArr) *getStringArr(int i);

void p6_36_37 () {
  // empty
}

/**
 * 练习6.38：修改arrPtr函数，使其返回数组的引用。
 */
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype(odd) &arrPtr(int i) {
  return (i % 2) ? odd : even;
}

void p6_38 () {
  auto res = arrPtr(5);
  cout << *res << endl;
}


int main () {
  // p6_30();
  // p6_31();
  p6_32();
  p6_33();
  p6_34_35();
  // p6_36_37()
  p6_38();

  return 0;
}
