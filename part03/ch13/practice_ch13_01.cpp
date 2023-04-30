#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
 * 练习13.1：拷贝构造函数是什么？什么时候使用它？
 */
void p13_01 () {
 // 构造函数的第一个参数是自身类型的引用，且额外参数都有默认值
}

/**
 * 练习13.2：解释为什么下面的声明是非法的：
 * Sales_data::Sales_data(Sales_data rhs);
 */
void p13_02 () {
  // 必须是引用类型
}

/**
 * 练习13.3：当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？
 */
void p13_03 () {
  // 拷贝 StrBlob 时，`shared_ptr` 的 `use_count` 会+1
  // 拷贝 StrBlobPtr 是，`weak_ptr` 的 `use_count` 不会改变
}

/**
 * 练习13.4：假定Point是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数
 */
void p13_04 () {
  // Point global;
  // Point foo_bar(Point arg) { // 1
  //   Point local = arg, *heap = new Point(global); // 2, 3
  //   *heap = local;
  //   Point pa[4] = { local, *heap }; // 4
  //   return *heap; // 5
  // }
}

/**
 * 练习13.5：给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。
 * 你的构造函数应该动态分配一个新的string（参见12.1.2节，第407页），
 * 并将对象拷贝到ps指向的位置，而不是ps本身的位置。
 */
class HasPtr {
public:
  HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}

  HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) ;
private:
  string *ps;
  int i;
};
void p13_05 () {

}

int main () {
  // p13_01();
  // p13_02();
  // p13_03();
  // p13_04();
  // p13_05();

  return 0;
}
