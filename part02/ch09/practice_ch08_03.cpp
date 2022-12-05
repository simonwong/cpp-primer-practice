#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

/**
 * 练习9.2：定义一个list对象，其元素类型是int的deque。
 */
void p9_02 () {
  std::deque<int> intDeque;
}

/**
 * 练习9.3：构成迭代器范围的迭代器有何限制？
 */
void p9_03 () {
  // [begin, end)
}

/**
 * 练习9.4：编写函数，接受一对指向vector<int>的迭代器和一个int值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
 */
bool p9_04 () {
  vector<int> vec = {3, 4, 5, 67, 45, 34};
  int val = 67;
  auto beg = vec.begin();
  auto end = vec.end();

  while (beg != end) {
    if (*beg == val) {
      cout << "Find：" << val << endl;
      return true;
    }
    beg++;
  }
  return false;
}

/**
 * 练习9.5：重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。
 */
vector<int>::iterator p9_05 () {
  vector<int> vec = {3, 4, 5, 67, 45, 34};
  int val = 67;
  auto beg = vec.begin();
  auto end = vec.end();

  while (beg != end) {
    if (*beg == val) {
      cout << "Find：" << val << endl;
      return beg;
    }
    beg++;
  }
  std::cerr << "Not Found" << val << endl;
  return end;
}

/**
 * 练习9.6：下面程序有何错误？你应该如何修改它？
 */
void p9_06 () {
  std::list<int> lst1;
  std::list<int>::iterator iter1 = lst1.begin(),
                           iter2 = lst1.end();

  while (iter1 != iter2) {

  }
}

int main (int argc, char **argv) {
  p9_02();
  // p9_03();
  p9_04();
  p9_05();
  p9_06();

  return 0;
}
