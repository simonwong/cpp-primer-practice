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

  HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {};
private:
  string *ps;
  int i;
};
void p13_05 () {

}

/**
 * 练习13.6：拷贝赋值运算符是什么？什么时候使用它？
 * 合成拷贝赋值运算符完成什么工作？什么时候会生成合成拷贝赋值运算符？
 */
void p13_06 () {
  // 拷贝赋值运算符是用来控制对象如何赋值的，使用 operation= 运算符，当进行赋值时就会使用
  // 合成拷贝赋值运算符会将右侧的每个非 static 成员赋予左侧对象的对应成员。
  //
}

/**
 * 练习13.7：当我们将一个StrBlob赋值给另一个StrBlob时，会发生什么？赋值StrBlobPtr呢？
 */
void p13_07 () {
  // 会发生浅层复制
}

/**
 * 练习13.8：为13.1.1节（第443页）练习13.5中的HasPtr类编写赋值运算符。
 * 类似拷贝构造函数，你的赋值运算符应该将对象拷贝到ps指向的位置。
 */
class HasPtr2 {
public:
  HasPtr2(const string& s = string()) : ps(new string(s)), i(0) {}

  HasPtr2& operator=(const HasPtr2&);
private:
  string *ps;
  int i;
};
void p13_08 () {
}

int main () {
  // p13_01();
  // p13_02();
  // p13_03();
  // p13_04();
  // p13_05();
  // p13_06();
  // p13_07();
  // p13_08();

  return 0;
}
