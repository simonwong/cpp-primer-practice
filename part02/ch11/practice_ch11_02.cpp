#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include "../../part01/ch07/Sales_data_21.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
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

/**
 * 练习11.9：定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号。
 */
void p11_9 () {
  std::map<string, list<int>> wordLine = {
    { "hello", {10, 40, 56, 78} },
    { "world", {10, 40, 56, 79} },
  };
}

/**
 * 练习11.10：可以定义一个vector<int>：：iterator到int的map吗？list<int>：：iterator到int的map呢？
 * 对于两种情况，如果不能，解释为什么。
 */
void p11_10 () {
  std::map<vector<int>::iterator, int> mapVecInt;
  std::map<list<int>::iterator, int> mapListInt;
}

/**
 * 练习11.11：不使用decltype重新定义bookstore。
 */
auto less(Sales_data_21 const& lhs, Sales_data_21 const& rhs) {
  return lhs.isbn() < rhs.isbn();
}
void p11_11 () {
  using Less = bool (*)(Sales_data_21 const&, Sales_data_21 const&);
  std::multiset<Sales_data_21, Less> bookStore(less);
}

/**
 * 练习11.12：编写程序，读入string和int的序列，将每个string和int存入一个pair中，pair保存在一个vector中。
 */
void p11_12 () {
  vector<std::pair<string, int>> pairVec;

  vector<string> vecStr = {"123", "456", "789"};
  vector<int> vecInt = {1, 4, 7};

  for (size_t i = 0; i < vecStr.size(); i++) {
    pairVec.push_back(std::pair<string, int>(vecStr[i], vecInt[i]));
  }

  for (auto pa : pairVec) {
    cout << pa.first << ": " << pa.second << endl;
  }
}

/**
 * 练习11.13：在上一题的程序中，至少有三种创建pair的方法。
 * 编写此程序的三个版本，分别采用不同的方法创建pair。解释你认为哪种形式最易于编写和理解，为什么？
 */
void p11_13 () {
  // pairVec.push_back(std::pair<string, int>(key, value));
  // pairVec.push_back(std::make_pair(key, value));
  // pairVec.push_back({key, value});
  // pairVec.emplace_back(key, value);
}

/**
 * 练习11.14：扩展你在11.2.1节练习（第378页）中编写的孩子姓到名的map，
 * 添加一个pair的vector，保存孩子的名和生日。
 */
void p11_14 () {
  std::map<string, vector<std::pair<string, string>>> familyMap = {
    {"Xiao", {{"ming", "1001-01-02"}, {"hong", "1002-04-03"}, {"dai", "1001-22-03"}}},
    {"Lao", {{"b", "0009-12-12"}, {"a", "1003-01-01"}}},
  };

  familyMap.insert({ "La", { {"Zxc", "1005-02-15"}, {"vbn", "1004-12-14"} } });

  familyMap["Lao"].push_back({"d", "1003-04-21"});

  for (const auto &family : familyMap) {
    cout << family.first << ": ";

    for (auto name : family.second) {
      cout << name.first << ": " << name.second << ", ";
    }
    cout << endl;
  }
}

int main () {
  // p11_5();
  // p11_6();
  p11_7();
  p11_8();
  p11_9();
  p11_10();
  p11_11();
  p11_12();
  p11_13();
  p11_14();

  return 0;
}
