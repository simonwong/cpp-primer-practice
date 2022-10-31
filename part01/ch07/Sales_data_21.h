#ifndef Sales_data_21_h
#define Sales_data_21_h

#include <iostream>
#include <string>

class Sales_data_21 {
  friend std::istream &read(std::istream &is, Sales_data_21 &item);
  friend std::ostream &print(std::ostream &os, Sales_data_21 &item);
  friend Sales_data_21 add(const Sales_data_21 &lhs, const Sales_data_21 &rhs);

public:
  Sales_data_21() = default;
  Sales_data_21(const std::string &s): bookNo(s) {};
  Sales_data_21(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {};
  Sales_data_21(std::istream &is) { read(is, *this); };

  std::string isbn() const { return bookNo; };
  Sales_data_21& combine(const Sales_data_21&);

private:
  inline double avg_price() const;

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

// 成员
Sales_data_21& Sales_data_21::combine(const Sales_data_21& rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

// 友员
std::istream &read(std::istream &is, Sales_data_21 &item)
{
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, Sales_data_21 &item)
{
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}

Sales_data_21 add(const Sales_data_21 &lhs, const Sales_data_21 &rhs)
{
  Sales_data_21 sum = lhs;
  sum.combine(rhs);

  return sum;
}

inline
double Sales_data_21::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

#endif
