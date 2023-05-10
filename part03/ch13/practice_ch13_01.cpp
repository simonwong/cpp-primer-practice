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

/**
 * 练习13.14：假定numbered是一个类，它有一个默认构造函数，能为每个对象生成一个唯一的序号，保存在名为mysn的数据成员中。
 * 假定numbered使用合成的拷贝控制成员，并给定如下函数
 * void f (numbered s) { cout << s.mysn << endl };
 * 则下面代码输出什么内容？
 * numbered a, b = a, c = b;
 * f(a); f(b); f(c);
 */
class numbered_14 {
public:
  numbered_14 () {
    mysn = unique++;
  }
  int mysn;
  static int unique;
};
int numbered_14::unique = 1;

void f_14 (numbered_14 s) { cout << s.mysn << endl; };

void p13_14 () {
  // 输出相同的 mysn，都是 1
  numbered_14 a, b = a, c = b;
  f_14(a); f_14(b); f_14(c);
}

/**
 * 练习13.15：假定numbered定义了一个拷贝构造函数，能生成一个新的序号。
 * 这会改变上一题中调用的输出结果吗？如果会改变，为什么？新的输出结果是什么？
 */
class numbered_15 {
public:
  numbered_15 () {
    mysn = unique++;
  }
  numbered_15 (const numbered_15&) {
    mysn = unique++;
  }
  int mysn;
  static int unique;
};

int numbered_15::unique = 10;

void f_15 (numbered_15 s) { cout << s.mysn << endl; };
void p13_15 () {
  // f_15 发生了复制操作将会输出三个不同的序号，原始是 10，11，12，输出了 13，14，15
  numbered_15 a, b = a, c = b;
  f_15(a); f_15(b); f_15(c);
}

/**
 * 练习13.16：如果f中的参数是const numbered&，将会怎样？
 * 这会改变输出结果吗？如果会改变，为什么？新的输出结果是什么？
 */
void f_16 (const numbered_15 &s) { cout << s.mysn << endl; };
void p13_16 () {
  // f_16 中没有发生复制操作，输出 16，17，18
  numbered_15 a, b = a, c = b;
  f_16(a); f_16(b); f_16(c);
}

/**
 * 练习13.17：分别编写前三题中所描述的numbered和f，验证你是否正确预测了输出结果。
 */
void p13_17 () {
}

/**
 * 练习13.18：定义一个Employee类，它包含雇员的姓名和唯一的雇员证号。
 * 为这个类定义默认构造函数，以及接受一个表示雇员姓名的string的构造函数。
 * 每个构造函数应该通过递增一个static数据成员来生成一个唯一的证号。
 */
class Employee {
  Employee () : code(++inCode) {};
  Employee (const string &n) : name(n), code(++inCode) {};
  Employee (const Employee& emp) : name(emp.name), code(++inCode) {};

  static int inCode;
private:
  string name;
  int code;
};

int Employee::inCode = 0;

void p13_18 () {
}

/**
 * 练习13.19：你的Employee类需要定义它自己的拷贝控制成员吗？
 * 如果需要，为什么？如果不需要，为什么？实现你认为Employee需要的拷贝控制成员。
 */
void p13_19 () {
  // 需要的，因为 inCode 是递增的
}

/**
 * 练习13.20：解释当我们拷贝、赋值或销毁TextQuery和QueryResult类（参见12.3节，第430页）对象时会发生什么。
 */
void p13_20 () {
  // 他们的成员都会正常拷贝
}

/**
 * 练习13.21：你认为TextQuery和QueryResult类需要定义它们自己版本的拷贝控制成员吗？
 * 如果需要，为什么？如果不需要，为什么？实现你认为这两个类需要的拷贝控制操作。
 */
void p13_21 () {
  // 不需要，合成的可以满足需求
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
  p13_14();
  p13_15();
  p13_16();
  // p13_17();
  // p13_18();
  // p13_19();
  // p13_20();
  // p13_21();

  return 0;
}
