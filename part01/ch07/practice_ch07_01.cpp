#include <iostream>
#include <string>
#include <vector>
#include "Sales_data_02.h"
#include "Sales_data_11.h"
#include "Person_15.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;
using std::initializer_list;

/**
 * 练习7.1：使用2.6.1节练习定义的Sales_data类为1.6节（第21页）的交易处理程序编写一个新版本。
 */
struct Sales_data_01 {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0;
};
int p7_01 () {
  Sales_data_01 total;

  if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data_01 trans;

    while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
        total = trans;
      }
    }
    cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
  } else {
    std::cerr << "No data?" << endl;
    return -1;
  }
  return 0;
}

/**
 * 练习7.2：曾在2.6.2节的练习（第67页）中编写了一个Sales_data类，请向这个类添加combine和isbn成员。
 *
 * 练习7.3：修改7.1.1节（第229页）的交易处理程序，令其使用这些成员。
 */
int p7_02_03 () {
  Sales_data_02 total;

  if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data_02 trans;

    while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
        total = trans;
      }
    }
    cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
  } else {
    std::cerr << "No data?" << endl;
    return -1;
  }
  return 0;
}

/**
 * 练习7.4：编写一个名为Person的类，使其表示人员的姓名和住址。
 * 使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。
 *
 * 练习7.5：在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是const的呢？解释原因。
 */
struct Person {
  string name;
  string address;

public:
  auto getName() const -> string const & { return name; };
  auto getAddress() const -> string const & { return address; };
};

void p7_04_05 () {
}

/**
 * 练习7.6：对于函数add、read和print，定义你自己的版本。
 *
 * 练习7.7：使用这些新函数重写7.1.2节（第233页）练习中的交易处理程序。
 */
std::istream &read(std::istream &is, Sales_data_02 &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}
std::ostream &print(std::ostream &os, const Sales_data_02 &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}
Sales_data_02 add(const Sales_data_02 &lhs, const Sales_data_02 &rhs) {
  Sales_data_02 sum = lhs;
  sum.combine(rhs);
  return sum;
}

int p7_06_07 () {
  Sales_data_02 total;

  if (read(cin, total)) {
    Sales_data_02 trans;

    while (read(cin, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(cout, total) << std::endl;
        total = trans;
      }
    }
    print(cout, total) << std::endl;
  } else {
    std::cerr << "No data?" << endl;
    return -1;
  }
  return 0;
}

/**
 * 练习7.8：为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用？
 */
void p7_08 () {
  // read 要修改
  // print 只读
}

/**
 * 练习7.9：对于7.1.2节（第233页）练习中的代码，添加读取和打印Person对象的操作。
 */
std::istream &read(std::istream &is, Person &item) {
  is >> item.name >> item.address;
  return is;
}
std::ostream &print(std::ostream &os, const Person &item) {
  os << item.getName() << " " << item.getAddress();
  return os;
}
void p7_09 () {
  // read 要修改
  // print 只读
  Person someone;
  if (read(cin, someone)) {
    print(cout, someone);
  }
}


/**
 * 练习7.10：在下面这条if语句中，条件部分的作用是什么？
 */
// if (read(read(cin, data1), data2))
void p7_10 () {
  // 相当于 cin >> data1 >> data2
}

/**
 * 练习7.11：在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。
 *
 * 练习7.12：把只接受一个istream作为参数的构造函数定义移到类的内部。
 */
void p7_11_12 () {
  Sales_data_11 data1;
  print(cout, data1) << endl;

  Sales_data_11 data2("123");
  print(cout, data2) << endl;

  Sales_data_11 data3("123", 3, 20.0);
  print(cout, data3) << endl;

  Sales_data_11 data4(cin);
  print(cout, data4) << endl;
}

/**
 * 练习7.13：使用istream构造函数重写第229页的程序。
 */
int p7_13 () {
  Sales_data_11 total(cin);

  if (!total.isbn().empty()) {
    std::istream &is = cin;

    while (is) {
      Sales_data_11 trans(is);

      if (!is) {
        break;
      }

      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(cout, total) << std::endl;
        total = trans;
      }
    }
    print(cout, total) << std::endl;
  } else {
    std::cerr << "No data?" << endl;
    return -1;
  }
  return 0;
}

/**
 * 练习7.14：编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。
 */
void p7_14 () {
  // Sales_data_11(): bookNo(""), units_sold(0), revenue(0) {};
}

/**
 * 练习7.15：为你的Person类添加正确的构造函数。
 */
void p7_15 () {
  Person_15 person("Aston", "Singapore");

  cout << person.getName() << " " << person.getAddress() << endl;
}

int main () {
  p7_01();
  p7_02_03();
  p7_04_05();
  p7_06_07();
  p7_08();
  p7_09();
  p7_10();
  p7_11_12();
  p7_13();
  p7_14();
  p7_15();

  return 0;
}
