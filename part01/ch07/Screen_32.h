#ifndef Screen_32_h
#define Screen_32_h

#include <iostream>
#include <string>
#include <vector>


class Window_mgr_32 {
public:
  using ScreenIndex = std::vector<Screen_32>::size_type;
  inline void clear(ScreenIndex);
private:
  std::vector<Screen_32> screens;
};

class Screen_32 {
  friend void Window_mgr_32::clear(ScreenIndex);

public:
  using pos = std::string::size_type;

  Screen_32() = default;
  Screen_32(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen_32(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

  char get() const { return contents[cursor]; }

  Screen_32 &display(std::ostream &os) {
    do_display(os);
    return *this;
  }

  inline char get(pos r, pos c) const;
  inline Screen_32 &move(pos r, pos c);
  inline Screen_32 &set(char txt);

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;

  void do_display(std::ostream &os) const {
    os << contents;
  }
};


inline void Window_mgr_32::clear(ScreenIndex idx) {
  if (idx >= screens.size()) {
    return;
  }
  Screen_32 &s = screens[idx];
  s.contents = std::string(s.height * s.width, ' ');
}

inline
char Screen_32::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

Screen_32 &Screen_32::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

Screen_32 &Screen_32::set(char txt) {
  contents[cursor] = txt;
  return *this;
}

#endif
