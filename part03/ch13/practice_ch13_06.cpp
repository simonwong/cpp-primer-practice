#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "String.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/**
 * 练习13.45：解释右值引用和左值引用的区别。
 */
void p13_45 () {
  // 右值引用的重要性质：只能绑定到一个将要销毁的对象。
  // 左值持久，右值短暂
}

/**
 * 练习13.46：什么类型的引用可以绑定到下面的初始化器上？
 */
void p13_46 () {
  int f();
  vector<int> vi(100);
  int&& r1 = f();
  int& r2 = vi[0];
  int& r3 = r1;
  int&& r4 = vi[0] * f();
}

/**
 * 练习13.47：对你在练习13.44（13.5节，第470页）中定义的String类，
 * 为它的拷贝构造函数和拷贝赋值运算符添加一条语句，在每次函数执行时打印一条信息。
 */
void p13_47 () {
}

/**
 * 练习13.48：定义一个vector<String>并在其上多次调用push_back。
 * 运行你的程序，并观察String被拷贝了多少次。
 */
void p13_48 () {
  vector<String> vstr;
  String s0;
  String s1("hello");
  String s2(s0);
  String s3 = s1;

  vstr.push_back(s0);
  vstr.push_back(s1);
  vstr.push_back(s2);
  vstr.push_back(s3);
}

/**
 * 练习13.49：为你的StrVec、String和Message类添加一个移动构造函数和一个移动赋值运算符。
 */
void p13_49 () {
}

/**
 * 练习13.50：在你的String类的移动操作中添加打印语句，并重新运行13.6.1节（第473页）的练习13.48中的程序，它使用了一个vector<String>，观察什么时候会避免拷贝。
 */
void p13_50 () {
}

/**
 * 练习13.51：虽然unique_ptr不能拷贝，但我们在12.1.5节（第418页）中编写了一个clone函数，
 * 它以值方式返回一个unique_ptr。解释为什么函数是合法的，以及为什么它能正确工作。
 */
void p13_51 () {
  // 他是移动操作
}

/**
 * 练习13.52：详细解释第478页中的HasPtr对象的赋值发生了什么？
 * 特别是，一步一步描述hp、hp2以及HasPtr的赋值运算符中的参数rhs的值发生了什么变化。
 */
void p13_52 () {
  // 左指是被复制，右值是被移动
}

/**
 * 练习13.53：从底层效率的角度看，HasPtr的赋值运算符并不理想，解释为什么。
 * 为HasPtr实现一个拷贝赋值运算符和一个移动赋值运算符，并比较你的新的移动赋值运算符中执行的操作和拷贝并交换版本中执行的操作。
 */
void p13_53 () {
  // 见 https://stackoverflow.com/questions/21010371/why-is-it-not-efficient-to-use-a-single-assignment-operator-handling-both-copy-a
}

/**
 * 练习13.54：如果我们为HasPtr定义了移动赋值运算符，
 * 但未改变拷贝并交换运算符，会发生什么？编写代码验证你的答案。
 */
void p13_54 () {
  // error: ambiguous overload for 'operator='
}

/**
 * 练习13.55：为你的StrBlob添加一个右值引用版本的push_back。
 */
void p13_55 () {
  // void push_back(string &&s) { data->push_back(std::move(s)); }
}

/**
 * 练习13.56：如果sorted定义如下，会发生什么：
 */
void p13_56 () {
  // 堆栈溢出
}

/**
 * 练习13.57：如果sorted定义如下，会发生什么：
 */
void p13_57 () {
  // Foo Foo::sorted() const & { return Foo(*this).sorted(); }
}

/**
 * 练习13.58：编写新版本的Foo类，其sorted函数中有打印语句，测试这个类，来验证你对前两题的答案是否正确。
 */

class Foo {
public:
  Foo sorted() &&;
  Foo sorted() const &;
private:
  vector<int> data;
};

Foo Foo::sorted() && {
  sort(data.begin(), data.end());
  std::cout << "&&" << std::endl; // debug
  return *this;
}

Foo Foo::sorted() const & {
  std::cout << "const &" << std::endl;
  return Foo(*this).sorted();
}
void p13_58 () {
}

int main () {
  // p13_45();
  // p13_46();
  // p13_47();
  // p13_48();
  // p13_49();
  // p13_50();
  // p13_51();
  // p13_52();
  // p13_53();
  // p13_54();
  // p13_55();
  // p13_56();
  // p13_57();
  // p13_58();

  return 0;
}
