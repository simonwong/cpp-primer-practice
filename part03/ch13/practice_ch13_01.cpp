#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

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

/**
 * 练习13.9：析构函数是什么？合成析构函数完成什么工作？什么时候会生成合成析构函数？
 */
void p13_09 () {
  // 析构函数释放对象的资源，并销毁对象的非 static 数据成员。
  // 未定义自己的析构函数，编译器会为它定义一个析构函数。
}

/**
 * 练习13.10：当一个StrBlob对象销毁时会发生什么？一个StrBlobPtr对象销毁时呢？
 */
void p13_10 () {
  // use_count 减去 1
  // 动态对象不会被释放
}

/**
 * 练习13.11：为前面练习中的HasPtr类添加一个析构函数。
 */
class HasPtr3 {
public:
  HasPtr3(const string& s = string()) : ps(new string(s)), i(0) {}
  HasPtr3(const HasPtr3& hp) : ps(new string(*hp.ps)), i(hp.i) {};
  HasPtr3& operator=(const HasPtr3&);
  ~HasPtr3() { };
private:
  string *ps;
  int i;
};
void p13_11 () {
}

/**
 * 练习13.12：在下面的代码片段中会发生几次析构函数调用？
 */
void p13_12 () {
  // bool fcn(const Sales_data *trans, Sales_data accum) {
  //   Sales_data item1(*trans), item2(accum);
  //   return item1.isbn() != item2.isbn(); // item1、item2、accum 会被调用
  // }
}

/**
 * 练习13.13：理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，
 * 为该类定义这些成员，每个成员都打印出自己的名字：
 *
 * 给X添加拷贝赋值运算符和析构函数，并编写一个程序以不同方式使用X的对象：
 * 将它们作为非引用和引用参数传递；
 * 动态分配它们；
 * 将它们存放于容器中；
 * 诸如此类。
 * 观察程序的输出，直到你确认理解了什么时候会使用拷贝控制成员，以及为什么会使用它们。
 * 当你观察程序输出时，记住编译器可以略过对拷贝构造函数的调用。
 */
struct X
{
  X() {
    cout << "X()" << endl;
  }
  X(const X&) {
    cout << "X(const X&)" << endl;
  }
  X& operator=(const X&) {
    cout << "X& operator=(const X&)" << endl;
    return *this;
  }
  ~X() {
    cout << "~X()" << endl;
  }
};

void p13_13 () {
  X x1;
  X x2 = x1;

  X *px = new X;

  vector<X> vec;
  vec.push_back(*px);

  delete px;
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
  // p13_09();
  // p13_10();
  // p13_11();
  // p13_12();
  p13_13();

  return 0;
}
