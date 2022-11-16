#include <iostream>
#include <string>
#include <vector>
#include "Sales_data_41.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;
using std::initializer_list;

/**
 * 练习7.36：下面的初始值是错误的，请找出问题所在并尝试修改它。
 */
struct X {
  X (int i, int j): base(i), rem(base % j) {};
  // int rem, base;
  int base, rem;
};

void p7_36 () {
  // 列表初始化没问题，下面定义的顺序不对
}

/**
 * 练习7.37：使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有数据成员的值。
 */
void p7_37 () {
  // first_item: 未初始化，需要输入
  // next: bookNo 初始化为 ""，cnt 为 0，revenue 为 0.0
  // last: bookNo 初始化为 "9-999-99999-9"，cnt 为 0，revenue 为 0.0
}

/**
 * 练习7.38：有些情况下我们希望提供cin作为接受istream&参数的构造函数的默认实参，请声明这样的构造函数。
 */
class DefaultCin {
  DefaultCin(std::istream &is = cin) {};
};
void p7_38 () {
}

/**
 * 练习7.39：如果接受string的构造函数和接受istream&的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？
 */
void p7_39 () {
  // 不合法，调用会不明确
}

/**
 * 练习7.40：从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
 */
class MyDate {
public:
  MyDate(string y, string m, string d): year(y), month(m), date(d) {};

  string getDate () {
    return year + "-" + month + "-" + date;
  }

private:
  string year;
  string month;
  string date;
};
void p7_40 () {
  MyDate curDate("2022", "10", "01");

  cout << curDate.getDate() << endl;
}

/**
 * 练习7.41：使用委托构造函数重新编写你的Sales_data类，给每个构造函数体添加一条语句，
 * 令其一旦执行就打印一条信息。
 * 用各种可能的方式分别创建Sales_data对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。
 */
void p7_41 () {
  // 会先执行委托构造函数，再执行当前的构造函数
  cout << "1: " << endl;
  Sales_data_41 salesData1;
  cout << "2: " << endl;
  Sales_data_41 salesData2("book-001");
}

/**
 * 练习7.42：对于你在练习7.40（参见7.5.1节，第261页）中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。
 * 如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。
 */
class MyDate2 {
public:
  MyDate2(string y, string m, string d): year(y), month(m), date(d) {};
  MyDate2(): MyDate2("1900", "01", "01") {};

  string getDate () {
    return year + "-" + month + "-" + date;
  }

private:
  string year;
  string month;
  string date;
};
void p7_42 () {
}

/**
 * 练习7.43：假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。
 * 定义类C，C有一个NoDefault类型的成员，定义C的默认构造函数。
 */
class NoDefault {
public:
  NoDefault (int i): num(i) {};
private:
  int num;
};
class C {
public:
  C (): nd(1) {};
private:
  NoDefault nd;
};

void p7_43 () {
}

/**
 * 练习7.44：下面这条声明合法吗？如果不，为什么？
 */
void p7_44 () {
  // ❌ 不合法，NoDefault 需要默认初始化值
  vector<NoDefault> vec(10);
}

/**
 * 练习7.45：如果在上一个练习中定义的vector的元素类型是C，则声明合法吗？为什么？
 */
void p7_45 () {
  // 没有问题，合法的
}

/**
 * 练习7.46：下面哪些论断是不正确的？为什么？
 */
void p7_46 () {
  // （a）一个类必须至少提供一个构造函数。
  // ❌
  // （b）默认构造函数是参数列表为空的构造函数。
  // ❌
  // （c）如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
  // ❌ 应该提供
  // （d）如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。
  // ❌ 不会初始化，只有当类没有显式的提供构造函数，编译器才会初始化默认值。
}

/**
 * 练习7.47：说明接受一个string参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。
 */
void p7_47 () {
  // 取决于用户如何使用 Sales_data 的转换。

  // 优点
  // ==
  // 缺点
  // ==
}

/**
 * 练习7.48：假定Sales_data的构造函数不是explicit的，则下述定义将执行什么样的操作？
 */
void p7_48 () {
  // 都不会有问题

  // 是explicit 也不会有问题，因为都是显式的
}

/**
 * 练习7.49：对于combine函数的三种不同声明，当我们调用i.combine（s）时分别发生什么情况？其中i是一个Sales_data，而s是一个string对象。
 */
void p7_49 () {
  // a
  // 发生隐式转换

  // b
  // 发生错误，string& 不能转化为 Sales_data 类型

  // c
  // 不能使用 尾部的 const ，因为它禁止数据成员发生改变。
}

/**
 * 练习7.50：确定在你的Person类中是否有一些构造函数应该是explicit的。
 */
void p7_50 () {
  // 没有一个实参的构造函数，不需要加
}

/**
 * 练习7.51：vector将其单参数的构造函数定义成explicit的，而string则不是，你觉得原因何在？
 */
void p7_51 () {
  // vector 单参数意义不大，大部分 vector 都是 size 大于 1 的，而且用起来会比较迷惑
  // string 单参数是非常自然的
}

/**
 * 练习7.52：使用2.6.1节（第64页）的Sales_data类，解释下面的初始化过程。如果存在问题，尝试修改它。
 */
// 2.6.1 的 Sales_data 有类内初始化、构造函数
struct Sales_data_52 {
  string bookNo;
  unsigned units_sold;
  double revenue;
};

void p7_52 () {
  Sales_data_52 item = {"999-99-99", 25, 12.55};
}

/**
 * 练习7.53：定义你自己的Debug。
 */
class Debug {
public:
  constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
  constexpr bool any () {
    return hw || io || other;
  }

  void set_io (bool b) { io = b; }
  void set_hw (bool b) { hw = b; }
  void set_other (bool b) { other = b; }

private:
  bool hw;
  bool io;
  bool other;
};

void p7_53 () {
}

/**
 * 练习7.54：Debug中以set_开头的成员应该被声明成constexpr吗？如果不，为什么？
 */
void p7_54 () {
}

/**
 * 练习7.55：7.5.5节（第266页）的Data类是字面值常量类吗？请解释原因。
 */
void p7_55 () {
  // 不是，string 不是字面值
}


int main () {
  // p7_36();
  // p7_37();
  // p7_38();
  // p7_39();
  p7_40();
  p7_41();
  // p7_42();
  // p7_43();
  // p7_44();
  // p7_45();
  // p7_46();
  // p7_47();
  // p7_48();
  // p7_49();
  // p7_50();
  // p7_51();
  // p7_52();
  // p7_53();
  // p7_54();
  // p7_55();

  return 0;
}
