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

/**
 * 练习9.7：为了索引int的vector中的元素，应该使用什么类型？
 */
void p9_07 () {
  // vector<int>::size_type
}

/**
 * 练习9.8：为了读取string的list中的元素，应该使用什么类型？
 * 如果写入list，又该使用什么类型？
 */
void p9_08 () {
  // list<string>::const_iterator
  // list<int>::iterator
}

/**
 * 练习9.8：为了读取string的list中的元素，应该使用什么类型？
 * 如果写入list，又该使用什么类型？
 */
void p9_09 () {
  // begin 是可写入的
  // cbegin const 成员，是只读的
}

/**
 * 练习9.10：下面4个对象分别是什么类型？
 */
void p9_10 () {
  vector<int> v1;
  const vector<int> v2;

  auto it1 = v1.begin(); // vector<int>::iterator
  auto it2 = v2.begin(); // vector<int>::const_iterator
  auto it3 = v1.cbegin(), it4 = v2.cbegin(); // vector<int>::const_iterator
}

/**
 * 练习9.11：对6种创建和初始化vector对象的方法，每一种都给出一个实例。解释每个vector包含什么值。
 */
void p9_11 () {
  // 默认构造函数。v1 为空
  vector<int> v1;

  // 列表初始化，v2 包含 1，2
  vector<int> v2_1{1, 2};
  vector<int> v2_2 = {1, 2};

  // 拷贝赋值，v3 包含 1，2
  vector<int> v3_1(v2_2);
  vector<int> v3_2 = v2_2;

  // 迭代器范围拷贝，v4 包含 1，2
  vector<int> v4(v2_2.begin(), v2_2.end());

  // v5 长度为 6，并对这些值进行了初始化
  vector<int> v5(6);

  // v6 长度为 6，并对这些值进行了初始为了 6
  vector<int> v6(6, 6);
}

/**
 * 练习9.12：对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。
 */
void p9_12 () {
  // 容器创建其拷贝：要求容器类型和元素类型都必须相同

  // 迭代器：容器类型不要求相同，元素类型也可以不同，会进行隐式转换
}

/**
 * 练习9.13：如何从一个list<int>初始化一个vector<double>？从一个vector<int>又该如何创建？编写代码验证你的答案。
 */
void p9_13 () {
  std::list<int> listInt = {1,2,3};
  vector<double> vecDouble(listInt.begin(), listInt.end());


  std::list<int> listInt2(vecDouble.begin(), vecDouble.end());
}

int main (int argc, char **argv) {
  p9_02();
  // p9_03();
  p9_04();
  p9_05();
  p9_06();
  // p9_07();
  // p9_08();
  // p9_09();
  // p9_10();
  p9_11();
  p9_12();
  p9_13();

  return 0;
}
