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

int main () {
  p7_01();
  p7_02_03();

  return 0;
}
