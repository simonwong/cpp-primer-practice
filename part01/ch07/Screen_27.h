#ifndef Screen_27_h
#define Screen_27_h

#include <iostream>
#include <string>

class Screen_27 {
public:
  using pos = std::string::size_type;

  Screen_27() = default;
  Screen_27(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen_27(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

  char get() const { return contents[cursor]; }

  Screen_27 &display(std::ostream &os) {
    do_display(os);
    return *this;
  }

  inline char get(pos r, pos c) const;
  inline Screen_27 &move(pos r, pos c);
  inline Screen_27 &set(char txt);

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;

  void do_display(std::ostream &os) const {
    os << contents;
  }
};

inline
char Screen_27::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

Screen_27 &Screen_27::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

Screen_27 &Screen_27::set(char txt) {
  contents[cursor] = txt;
  return *this;
}

#endif
