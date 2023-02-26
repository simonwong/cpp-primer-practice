#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <typeinfo>
#include <stdexcept>
#include "../../part01/ch07/Sales_data_21.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::string;

/**
 * 练习11.15：对一个int到vector<int>的map，其mapped_type、key_type和value_type分别是什么？
 */
void p11_15 () {
  using mapVec = std::map<int, vector<int>>;
  mapVec::mapped_type; // vector<int>
  mapVec::key_type; // int
  mapVec::value_type; // pair<const int, vector<int>>
}

/**
 * 练习11.16：使用一个map迭代器编写一个表达式，将一个值赋予一个元素。
 */
void p11_16 () {
  std::map<string, int> mStrInt;

  mStrInt["apple"] = 10;
  mStrInt.begin()->second = 12;
}

/**
 * 练习11.17：假定c是一个string的multiset，v是一个string的vector，解释下面的调用。指出每个调用是否合法：
 */
void p11_17 () {
  std::multiset<string> c;
  vector<string> v;

  std::copy(v.begin(), v.end(), std::inserter(c, c.end())); // 合法
  // std::copy(v.begin(), v.end(), std::back_inserter(c)); // 不合法 ❌ set 没有 push_back
  std::copy(c.begin(), c.end(), std::inserter(v, v.end())); // 合法
  std::copy(c.begin(), c.end(), std::back_inserter(v)); // 合法
}

/**
 * 练习11.18：写出第382页循环中map_it的类型，不要使用auto或decltype。
 */
void p11_18 () {
  std::map<string, int> word_count;

  std::map<string, int>::const_iterator map_it = word_count.begin();
}

/**
 * 练习11.19：定义一个变量，通过对11.2.2节（第378页）中的名为bookstore的multiset调用begin（）来初始化这个变量。
 * 写出变量的类型，不要使用auto或decltype。
 */
void p11_19 () {
  // using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
  // std::multiset<Sales_data, compareType> bookstore(compareIsbn);
  // std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
}

/**
 * 练习11.20：重写11.1节练习（第376页）的单词计数程序，使用insert代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。
 */
void p11_20 () {
  std::map<string, size_t> word_count;

  string word;

  while (cin >> word) {
    auto ret = word_count.insert({ word, 1 });

    if (!ret.second) {
      ++word_count[word];
    }
  }

  for (const auto &w : word_count) {
    cout << w.first << " 出现 " << w.second << (w.second > 1 ? " times" : " time") << endl;
  }
}

/**
 * 练习11.21：假定word_count是一个string到size_t的map，word是一个string，解释下面循环的作用:
 */
void p11_21 () {
  std::map<string, size_t> word_count;

  string word;

  while (cin >> word) {
    ++word_count.insert({ word, 0 }).first->second;
    // ++(((word_count.insert({ word, 0 })).first)->second);
    // 如果有，那么 直接 +=1
    // 如果没有，那么 插入一个 0，然后 += 1
  }
}

/**
 * 练习11.22：给定一个map<string，vector<int>>，对此容器的插入一个元素的insert版本，写出其参数类型和返回类型。
 */
void p11_22 () {
  std::map<string, vector<int>> mStrVec;

  // std::pair<std::string, std::vector<int>> // 参数类型
  std::pair<std::map<string, vector<int>>::iterator, bool> ret = mStrVec.insert({ "some", { 1, 2, 3 } });
}

/**
 * 练习11.23：11.2.1节练习（第378页）中的map以孩子的姓为关键字，保存他们的名的vector，用multimap重写此map。
 */
void p11_23 () {
  std::multimap<string, vector<std::pair<string, string>>> familyMap = {
    {"Xiao", {{"ming", "1001-01-02"}, {"hong", "1002-04-03"}, {"dai", "1001-22-03"}}},
    {"Lao", {{"b", "0009-12-12"}, {"a", "1003-01-01"}}},
  };

  familyMap.insert({ "La", { {"Zxc", "1005-02-15"}, {"vbn", "1004-12-14"} } });

  familyMap.insert({ "Lao", { {"d", "1003-04-21"} } });

  for (const auto &family : familyMap) {
    cout << family.first << ": ";

    for (auto name : family.second) {
      cout << name.first << ": " << name.second << ", ";
    }
    cout << endl;
  }
}

/**
 * 练习11.24：下面的程序完成什么功能？
 */
void p11_24 () {
  std::map<int, int> m;
  m[0] = 1;
  // m 增加了 0 关键字，值为 1
}

/**
 * 练习11.25：对比下面程序与上一题程序
 */
void p11_25 () {
  vector<int> v;
  v[0] = 1;

  // v 的 下标 0 的值为 1
}

/**
 * 练习11.26：可以用什么类型来对一个map进行下标操作？下标运算符返回的类型是什么？
 * 请给出一个具体例子——即，定义一个map，然后写出一个可以用来对map进行下标操作的类型以及下标运算符将会返回的类型。
 */
void p11_26 () {
  std::map<string, int> m;
  using KeyType = std::map<string, int>::key_type;
  cout << "type to subscript: " << typeid(KeyType).name() << endl;
  std::cout << "returned from the subscript operator: " << typeid(decltype(m["asd"])).name() << std::endl;
}

/**
 * 练习11.27：对于什么问题你会使用count来解决？什么时候你又会选择find呢？
 */
void p11_27 () {
  // count 获取元素数量
  // find 获取元素的位置
}

/**
 * 练习11.28：对一个string到int的vector的map，定义并初始化一个变量来保存在其上调用find所返回的结果。
 */
void p11_28 () {
  std::map<string, vector<int>> mStrVec({
    {"Hello", { 12, 435, 890 } },
    {"World", { 45, 577, 7899 } },
  });

  std::map<string, vector<int>>::iterator helloFind = mStrVec.find("Hello");
}

/**
 * 练习11.29：如果给定的关键字不在容器中，upper_bound、lower_bound和equal_range分别会返回什么？
 */
void p11_29 () {
  // upper_bound = lower_bound = 指向给定关键字的插入点
  // qual_range 返回 pair ，都指向给定关键字的插入点
}

/**
 * 练习11.30：对于本节最后一个程序中的输出表达式，解释运算对象pos.first->second的含义。
 */
void p11_30 () {
  // qual_range 返回一个 pair
  // first 指向找到位置的起始元素
  // second 指向上述的值
}

/**
 * 练习11.31：编写程序，定义一个作者及其作品的multimap。
 * 使用find在multimap中查找一个元素并用erase删除它。确保你的程序在元素不在map中时也能正常运行。
 */
void printAuthors (std::multimap<string, string> authors) {
  auto beg = authors.begin();
  string curAuth;

  while (beg != authors.end()) {
    if (beg->first != curAuth) {
      curAuth = beg->first;
      cout << endl;
      cout << beg->first << ": ";
    }
    cout << beg->second << ", ";
    ++beg;
  }
  cout << endl;
}
void p11_31_32 () {
  std::multimap<string, string> authors({
    { "Simon", "asd" },
    { "Jay", "qwe" },
    { "Simon", "zxc" },
    { "Jay", "tyu" },
  });
  printAuthors(authors);
  auto ret = authors.find("Jay");
  while (ret != authors.end()) {
    authors.erase(ret);

    ret = authors.find("Jay");
  }
  printAuthors(authors);
}

/**
 * 练习11.33：实现你自己版本的单词转换程序。
 */
std::map<string, string> buildMap(std::ifstream &map_file) {
  std::map<string, string> trans_map;
  string key;
  string value;

  while (map_file >> key && getline(map_file, value)) {
    if (value.size() > 1) {
      trans_map[key] = value.substr(1);
    } else {
      throw std::runtime_error("no rule for " + key);
    }
  }
  return trans_map;
}
const string &transform(const string &s, const std::map<string, string> &m) {
  auto map_it = m.find(s);
  if (map_it != m.end()) {
    return map_it->second;
  }
  return s;
}
void word_transform(std::ifstream &map_file, std::ifstream &input) {
  auto trans_map = buildMap(map_file);
  string text;
  while (getline(input, text)) {
    std::istringstream stream(text);
    string word;
    bool first_word = true;

    while (stream >> word) {
      if (first_word) {
        first_word = false;
      } else {
        cout << " ";
      }
      cout << transform(word, trans_map);
    }
    cout << endl;
  }

}
void p11_33 () {
  std::ifstream map_file_stream("./word_map_file.txt");
  std::ifstream input_file_stream("./word_input.txt");
  word_transform(map_file_stream, input_file_stream);
}

/**
 * 练习11.34：如果你将transform函数中的find替换为下标运算符，会发生什么情况？
 */
void p11_34 () {
  // map 就会多出对应下标的关键字
}

/**
 * 练习11.35：在buildMap中，如果进行如下改写，会有什么效果？
 */
void p11_35 () {
  // 使用下标，重复出现的单词会一直被覆盖
  // 使用 insert 不会覆盖
}

/**
 * 练习11.36：我们的程序并没有检查输入文件的合法性。
 * 特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？
 * 预测程序的行为并进行验证，再与你的程序进行比较。
 */
void p11_36 () {
  // map 的映射值将会是 ""， 就不会被替换
}

int main () {
  // p11_15();
  // p11_16();
  // p11_17();
  // p11_18();
  // p11_19();
  p11_20();
  p11_21();
  p11_22();
  p11_23();
  p11_24();
  p11_25();
  p11_26();
  // p11_27();
  // p11_28();
  // p11_29();
  // p11_30();
  p11_31_32();
  p11_33();
  // p11_34();
  // p11_35();
  // p11_36();

  return 0;
}
