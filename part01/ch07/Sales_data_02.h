#ifndef Sales_data_02_h
#define Sales_data_02_h

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

struct Sales_data_02 {
  string isbn() const { return bookNo; };
  Sales_data_02& combine(const Sales_data_02&);

  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0;
};

Sales_data_02& Sales_data_02::combine(const Sales_data_02& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

#endif
