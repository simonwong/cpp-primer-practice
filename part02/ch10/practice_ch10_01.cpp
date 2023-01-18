#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

/**
 * 练习10.1：头文件algorithm中定义了一个名为count的函数，它类似find，接受一对迭代器和一个值作为参数。
 * count返回给定值在序列中出现的次数。
 * 编写程序，读取int序列存入vector中，打印有多少个元素的值等于给定值。
 */
void p10_1 () {
  vector<int> vi = {1,2,2,2,54,6,46,56,6,43,2,3,3,34,5,22,2};

  auto twoTimes = std::count(vi.begin(), vi.end(), 2);

  cout << twoTimes << endl;
}

/**
 * 练习10.2：重做上一题，但读取string序列存入list中。
 */
void p10_2 () {
  vector<string> vStr = { "1","2","2","2","54","6","46","56","6","43","2","3","3","34","5","22","2" };

  auto twoTimes = std::count(vStr.begin(), vStr.end(), "2");

  cout << twoTimes << endl;
}

int main () {
  p10_1();
  p10_2();

  return 0;
}
