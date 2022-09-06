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
 * 练习4.31：本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。
 * 要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。
 */
int p4_31 () {
  // 前置版本可以减少不必要的一步操作。
  // 后置版本不许要改动。

  vector<int> ivec = {1,1,1,1,1,1,1,1,1,1};
  vector<int>::size_type cnt = ivec.size();

  for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++,cnt--) {
    ivec[ix] = cnt;

    cout << cnt << endl;
  }

  return 0;
}

/**
 * 练习4.32：解释下面这个循环的含义。
 */
int p4_32 () {
  constexpr int size = 5;
  int ia[size] = {1, 2, 3, 4, 5};
  for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr) {
    // ptr 指向 ia数组的第一个元素，即 1
    // ix 是 0，为 ia 的下标
    // 当不超过 ia 范围，且 ptr 的值不等于下标+size，怎么跑完整个数组
  }

  return 0;
}

/**
 * 练习4.33：根据4.12节中的表（第147页）说明下面这条表达式的含义。
 */
int p4_33 () {
  // someValue ? ++x, ++y : --x, --y;
  // 如果为 true，x 和 y 递增，返回 y
  // 如果为 false，x 和 y 递减，返回 y
  return 0;
}

int main () {
  p4_31();
  p4_32();
  p4_33();

  return 0;
}
