#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <numeric>
#include <iterator>
#include "../../part01/ch01/Sales_item.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::string;

/**
 * 练习10.26：解释三种插入迭代器的不同之处。
 */
void p10_26 () {
  // `back_inserter` 创建一个使用 push_back 的迭代器
  // `front_inserter` 创建一个使用 push_front 的迭代器
  // `inserter` 创建一个 insert 的迭代器。元素会被插入到给定迭代器的元素之前
}

/**
 * 练习10.27：除了unique（参见10.2.3节，第343页）之外，
 * 标准库还定义了名为unique_copy的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。
 * 编写一个程序，使用unique_copy将一个vector中不重复的元素拷贝到一个初始为空的list中。
 */
void p10_27 () {
  vector<int> vi = {1,2,3,3,4,4,5,6,7,7};
  list<int> li;

  std::unique_copy(vi.begin(), vi.end(), std::back_inserter(li));

  for (auto i : li) {
    cout << i << ",";
  }
  cout << endl;
}

/**
 * 练习10.28：一个vector中保存1到9，将其拷贝到三个其他容器中。
 * 分别使用inserter、back_inserter和front_inserter将元素添加到三个容器中。
 * 对每种inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。
 */
void p10_28 () {
  vector<int> vi = {1,2,3,4,5,6,7,8,9};
  list<int> vi_inserter;
  list<int> vi_back_inserter;
  list<int> vi_front_inserter;
  auto ist = std::inserter(vi_inserter, vi_inserter.begin());
  auto back_ist = std::back_inserter(vi_back_inserter);
  auto front_ist = std::front_inserter(vi_front_inserter);

  for (auto i : vi) {
    *ist = i;
    *back_ist = i;
    *front_ist = i;
  }

  cout << "inserter: ";
  for (auto i : vi_inserter) {
    cout << i << ",";
  }
  cout << endl;

  cout << "back_inserter: ";
  for (auto i : vi_back_inserter) {
    cout << i << ",";
  }
  cout << endl;

  cout << "front_inserter: ";
  for (auto i : vi_front_inserter) {
    cout << i << ",";
  }
  cout << endl;

}

/**
 * 练习10.29：编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里。
 */
void p10_29 () {
  std::ifstream ifs("./book.txt");
  std::istream_iterator<string> int_iter(ifs), eof;
  vector<string> vStr;
  std::copy(int_iter, eof, std::back_inserter(vStr));

  std::copy(vStr.begin(), vStr.end(), std::ostream_iterator<string>(std::cout, "\n"));
}

/**
 * 练习10.30：使用流迭代器、sort和copy从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。
 */
void p10_30 () {
  std::istream_iterator<int> in_iter(std::cin), in_eof;
  vector<int> vec(in_iter, in_eof);
  std::sort(vec.begin(), vec.end());
  std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
}

/**
 * 练习10.31：修改前一题的程序，使其只打印不重复的元素。
 * 你的程序应使用unique_copy（参见10.4.1节，第359页）。
 */
void p10_31 () {
  std::istream_iterator<int> in_iter(std::cin), in_eof;
  vector<int> vec(in_iter, in_eof);
  std::sort(vec.begin(), vec.end());
  std::unique_copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
}

/**
 * 练习10.32：重写1.6节（第21页）中的书店程序，使用一个vector保存交易记录，使用不同算法完成处理。
 * 使用sort和10.3.1节（第345页）中的compareIsbn函数来排序交易记录，然后使用find和accumulate求和。
 */
void p10_32 () {
  std::istream_iterator<Sales_item> in_iter(std::cin), in_eof;
  vector<Sales_item> vec;

  while (in_iter != in_eof) {
    vec.push_back(*in_iter++);
  }
  std::sort(vec.begin(), vec.end(), compareIsbn);
  for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
    end = std::find_if(beg, vec.cend(), [beg](const Sales_item &item) { return item.isbn() != beg->isbn(); });
    cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << endl;
  }
}

/**
 * 练习10.33：编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。
 * 输入文件保存的应该是整数。使用istream_iterator读取输入文件。
 * 使用ostream_iterator将奇数写入第一个输出文件，每个值之后都跟一个空格。
 * 将偶数写入第二个输出文件，每个值都独占一行。
 */
void p10_33 () {

}

/**
 * 练习10.34：使用reverse_iterator逆序打印一个vector。
 */
void p10_34 () {
  vector<int> vi = {1,2,3,4,5,6,7,8,9};
  auto crb = vi.crbegin();
  auto cre = vi.crend();
  while (crb != cre) {
    cout << *crb << endl;
    ++crb;
  }
}

/**
 * 练习10.35：使用普通迭代器逆序打印一个vector。
 */
void p10_35 () {
  vector<int> vi = {1,2,3,4,5,6,7,8,9};
  auto crb = vi.cbegin();
  auto cre = vi.cend();
  do {
    --cre;
    cout << *cre << endl;
  } while (crb != cre);
}

/**
 * 练习10.36：使用find在一个int的list中查找最后一个值为0的元素。
 */
void p10_36 () {
  std::list<int> li = {4,5,0,0,5,43,4,2245,0,5};

  auto el = std::find(li.crbegin(), li.crend(), 0);

  cout << std::distance(el, li.crend()) << endl;
}

/**
 * 练习10.37：给定一个包含10个元素的vector，将位置3到7之间的元素按逆序拷贝到一个list中。
 */
void p10_37 () {
  vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
  list<int> li(5);

  std::copy(vi.cbegin() + 3, vi.cbegin() + 8, li.rbegin());

  for (auto i : li) {
    cout << i << endl;
  }
}

int main () {
  // p10_26();
  p10_27();
  p10_28();
  p10_29();
  p10_30();
  p10_31();
  p10_32();
  p10_33();
  p10_34();
  p10_35();
  p10_36();
  p10_37();

  return 0;
}
