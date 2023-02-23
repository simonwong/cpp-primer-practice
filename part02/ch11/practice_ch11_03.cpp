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

int main () {
  // p11_15();
  // p11_16();
  // p11_17();
  // p11_18();
  // p11_19();

  return 0;
}
