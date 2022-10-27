#ifndef Sales_data_11_h
#define Sales_data_11_h

#include <iostream>
#include <string>

struct Sales_data_11 {
  Sales_data_11() = default;
  Sales_data_11(const std::string &s): bookNo(s) {};
  Sales_data_11(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {};
  Sales_data_11(std::istream &is) { read(is, *this); };

  std::string isbn() const { return bookNo; };
  Sales_data_11& combine(const Sales_data_11&);

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data_11& Sales_data_11::combine(const Sales_data_11& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::istream &read(std::istream &is, Sales_data_11 &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, Sales_data_11 &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}

Sales_data_11 add(const Sales_data_11 &lhs, const Sales_data_11 &rhs) {
  Sales_data_11 sum = lhs;
  sum.combine(rhs);

  return sum;
}

// Sales_data_11::Sales_data_11(std::istream &is) {
//   read(is, *this);
// }


#endif
