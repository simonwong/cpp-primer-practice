#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using std::cout;
using std::endl;
using std::vector;
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

int main () {
  p10_3();
  p10_4();
  p10_5();

  return 0;
}
