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
 * 练习4.21：编写一段程序，使用条件运算符从vector<int>中找到哪些元素的值是奇数，然后将这些奇数值翻倍。
 */
int p4_21 () {
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
  auto beg = vec.begin();

  while (beg != vec.end()) {
    *beg = *beg % 2 == 1 ? *beg * 2 : *beg;
    beg++;
  }

  for (auto el : vec) {
    cout << el << endl;
  }

  return 0;
}

/**
 * 练习4.22：本节的示例程序将成绩划分成high pass、pass和fail三种，
 * 扩展该程序使其进一步将60分到75分之间的成绩设定为low pass。
 * 要求程序包含两个版本：一个版本只使用条件运算符；另外一个版本使用1个或多个if语句。哪个版本的程序更容易理解呢？为什么？
 */
int p4_22 () {
  int grade = 74;
  string judge;

  judge = (grade > 90)
    ? "high pass"
    : (grade < 60)
      ? "fail"
      : (grade < 75)
        ? "low pass"
        : "pass";

  cout << judge << endl;

  // 当有复杂的条件判断时，使用 if 语句更加清晰

  if (grade > 90) {
    judge = "high pass";
  } else if (grade > 75) {
    judge = "pass";
  } else if (grade > 60) {
    judge = "low pass";
  } else {
    judge = "fail";
  }

  cout << judge << endl;
  return 0;
}

/**
 * 练习4.23：因为运算符的优先级问题，下面这条表达式无法通过编译。
 * 根据4.12节中的表（第147页）指出它的问题在哪里？应该如何修改？
 */
int p4_23 () {
  string s = "word";
  string pl = s + ((s[s.size() - 1] == 's') ? "" : "s");

  cout << pl << endl;
  return 0;
}

/**
 * 练习4.24：本节的示例程序将成绩划分成high pass、pass和fail三种，它的依据是条件运算符满足右结合律。
 * 假如条件运算符满足的是左结合律，求值过程将是怎样的？
 */
int p4_24 () {
  // 如果满足左结合律，那判断条件就会有问题。
  // 第一个条件就返回了 "high pass"，必是真
  return 0;
}

int main () {
  p4_21();
  p4_22();
  p4_23();
  p4_24();

  return 0;
}
