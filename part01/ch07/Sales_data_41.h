#ifndef Sales_data_41_h
#define Sales_data_41_h

#include <iostream>
#include <string>

class Sales_data_41 {
  friend std::ostream &print(std::ostream &os, Sales_data_41 &item);
public:
  Sales_data_41(): Sales_data_41("", 0, 0) {
    std::cout << "无参数 ";
    print(std::cout, *this);
    std::cout << std::endl;
  };
  Sales_data_41(const std::string &s): Sales_data_41(s, 0, 0) {
    std::cout << "1个字符串 ";
    print(std::cout, *this);
    std::cout << std::endl;
  };
  Sales_data_41(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {
    std::cout << "全参数 ";
    print(std::cout, *this);
    std::cout << std::endl;
  };
  Sales_data_41(std::istream &is) {
    print(std::cout, *this);
    std::cout << std::endl;
  };

  std::string isbn() const { return bookNo; };

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};


std::ostream &print(std::ostream &os, Sales_data_41 &item)
{
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}

#endif
