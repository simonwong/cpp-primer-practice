#ifndef Screen_23_h
#define Screen_23_h

#include <iostream>
#include <string>

class Screen_23_24 {
public:
  using pos = std::string::size_type;

  Screen_23_24() = default;
  Screen_23_24(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen_23_24(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

  char get() const { return contents[cursor]; }
  char get(pos r, pos c) const { return contents[r * width + c]; }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

#endif
