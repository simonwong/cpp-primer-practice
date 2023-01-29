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
 * 练习10.3：用accumulate求一个vector<int>中的元素之和。
 */
void p10_3 () {
  vector<int> vi = {1,2,2,2,54,6,46,56,6,43,2,3,3,34,5,22,2};

  auto sumRes = std::accumulate(vi.cbegin(), vi.cend(), 0);

  cout << sumRes << endl;
}

/**
 * 练习10.4：假定v是一个vector<double>，那么调用accumulate（v.cbegin（），v.cend（），0）有何错误（如果存在的话）？
 */
void p10_4 () {
  vector<double> vd = {1.2, 3.4, 5.6};

  auto sumRes = std::accumulate(vd.cbegin(), vd.cend(), 0);

  cout << sumRes << endl;

  // 由于第三个入参是 int，vd 的元素都会被转为 int 。
}

/**
 * 练习10.5：在本节对名册（roster）调用equal的例子中，
 * 如果两个名册中保存的都是C风格字符串而不是string，会发生什么？
 */
void p10_5 () {
  // 将会进行地址对比，而不是字符串本身，跟 string 比可能会得到不同的结果。
}

/**
 * 练习10.6：编写程序，使用fill_n将一个序列中的int值都设置为0。
 */
void p10_6 () {
  vector<int> iv = {1,2,3,4,5,6,7,8,9};
  std::fill_n(iv.begin(), iv.size(), 0);

  for (auto i : iv) {
    cout << i;
  }
  cout << endl;
}

/**
 * 练习10.7：下面程序是否有错误？如果有，请改正。
 */
void p10_7 () {
  // a
  vector<int> vec; list<int> lst; int i;
  while (cin >> i) {
    lst.push_back(i);
  }
  std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));

  // b
  vector<int> vec;
  vec.reserve(10);
  std::fill_n(std::back_inserter(vec), 10, 0);
}

/**
 * 练习10.8：本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？
 */
void p10_8 () {
  // back_inserter 是 迭代器的功能，而不是算法
}

int main () {
  p10_3();
  p10_4();
  p10_5();
  p10_6();
  p10_7();
  p10_8();

  return 0;
}
