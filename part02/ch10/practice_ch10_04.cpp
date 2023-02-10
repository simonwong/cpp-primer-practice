#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <numeric>
#include <iterator>

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

int main () {
  // p10_26();
  p10_27();
  p10_28();

  return 0;
}
