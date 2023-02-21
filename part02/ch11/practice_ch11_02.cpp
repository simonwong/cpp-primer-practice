#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/**
 * 练习11.5：解释map和set的区别。你如何选择使用哪个？
 */
void p11_5 () {
  // map 存储 统计，字段映射
  // set 存储 不重复的数据
}

/**
 * 练习11.6：解释set和list的区别。你如何选择使用哪个？
 */
void p11_6 () {
  // set 不重复的集合
  // list 可重复的，有序的，链表
}

/**
 * 练习11.7：定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
 */
void p11_7 () {
  std::map<string, vector<string>> familyMap = {
    {"Xiao", {"ming", "hong", "dai"}},
    {"Lao", {"b", "a", "c"}},
  };

  familyMap.insert({ "La", { "Zxc", "vbn" } });

  familyMap["Lao"].push_back("d");

  for (const auto &family : familyMap) {
    cout << family.first << ": ";

    for (auto name : family.second) {
      cout << name << ", ";
    }
    cout << endl;
  }
}

/**
 * 练习11.8：编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set的优点是什么？
 */
void p11_8 () {
  vector<string> words = {"hello", "hi", "get", "hi", "ok", "ok", "foo"};
  vector<string> wordSet;

  for (auto w : words) {
    if (std::find(wordSet.begin(), wordSet.end(), w) == wordSet.end()) {
      wordSet.push_back(w);
    }
  }

  for (auto w : wordSet) {
    cout << w << ",";
  }
  cout << endl;
}

int main () {
  // p11_5();
  // p11_6();
  p11_7();
  p11_8();

  return 0;
}
