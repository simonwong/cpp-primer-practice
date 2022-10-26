#ifndef Person_15_h
#define Person_15_h

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

struct Person_15 {
  Person_15() = default;
  Person_15(const string &name, const string &address) : name(name), address(address) {};

  string name;
  string address;

public:
  auto getName() const -> string const & { return name; };
  auto getAddress() const -> string const & { return address; };
};

#endif
