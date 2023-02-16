#include <iostream>
#include <fstream>
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
 * 练习10.38：列出5个迭代器类别，以及每类迭代器所支持的操作。
 */
void p10_38 () {
  // 输入迭代器
  // 输出迭代器
  // 前向迭代器
  // 双向迭代器
  // 随机访问迭代器
}

/**
 * 练习10.39：list上的迭代器属于哪类？vector呢？
 */
void p10_39 () {
  // list: 双向迭代器
  // vector: 随机访问迭代器
}

/**
 * 练习10.40：你认为copy要求哪类迭代器？reverse和unique呢？
 */
void p10_40 () {
  // copy: 输入，输入，输出
  // reverse: 双向
  // unique: 前向
}

/**
 * 练习10.41：仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：
 */
void p10_41 () {
  // replace(beg, end, old_val, new_val);

  // replace_if(beg, end, pred, new_val);

  // replace_copy(beg, end, dest, old_val, new_val);
  // 结果将会拷贝到 dest

  // replace_copy_if(beg, end, dest, pred, new_val);
  // 符合 pred 的结果将会拷贝到 dest
}

int main () {
  // p10_38();
  // p10_39();
  // p10_40();
  // p10_41();

  return 0;
}
