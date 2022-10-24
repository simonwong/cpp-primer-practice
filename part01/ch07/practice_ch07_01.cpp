#include <iostream>
#include <string>
#include <vector>
#include "Chapter6.h"

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
struct Sales_data {
  string isbn() const { return bookNo; };
  Sales_data& combine(const Sales_data&);

  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0;
};
Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

int p7_02_03 () {
  Sales_data total;

  if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data trans;

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
std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

int p7_06_07 () {
  Sales_data total;

  if (read(cin, total)) {
    Sales_data trans;

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



int main () {
  p7_01();
  p7_02_03();
  p7_04_05();
  p7_06_07();
  p7_08();
  p7_09();
  p7_10();

  return 0;
}
