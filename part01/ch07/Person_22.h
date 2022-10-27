#ifndef Person_22_h
#define Person_22_h

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Person_22 {
  friend std::istream &read(std::istream &is, Person_22 &person);
  friend std::ostream &print(std::ostream &os, Person_22 &person);

public:
  Person_22() = default;
  Person_22(const string &name, const string &address) : name(name), address(address) {};
  auto getName() const -> string const & { return name; };
  auto getAddress() const -> string const & { return address; };

private:
  string name;
  string address;
};

std::istream &read(std::istream &is, Person_22 &person)
{
  is >> person.name >> person.address;
  return is;
};

std::ostream &print(std::ostream &os, Person_22 &person)
{
  os << person.name << " " << person.address;
  return os;
};

#endif
