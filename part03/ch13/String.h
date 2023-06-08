#ifndef String_h
#define String_h

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class String {
public:
  String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}

  String(std::initializer_list<char> listStr): elements(nullptr), first_free(nullptr), cap(nullptr) {
    auto newData = alloc_n_copy(listStr.begin(), listStr.end());
    elements = newData.first;
    first_free = newData.second;
  }

  String(const char *str): elements(nullptr), first_free(nullptr), cap(nullptr) {
    char *sl = const_cast<char*>(str);
    while (*sl) {
      ++sl;
    }

    auto newData = alloc_n_copy(str, sl);
    elements = newData.first;
    first_free = newData.second;
  }

  String(const String &s) {
    cout << "String(const String &s)" << endl;
    auto newData = alloc_n_copy(s.begin(), s.end());
    elements = newData.first;
    first_free = newData.second;
  }

  String &operator=(const String &rhs) {
    cout << "String &operator=" << endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
  }

  ~String() {
    free();
  }

  void push_back(const char &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
  };

  size_t size() const {
    return first_free - elements;
  }

  size_t capacity () const {
    return cap - elements;
  }

  char *begin() const {
    return elements;
  }

  char *end() const {
    return first_free;
  }

private:
  static std::allocator<char> alloc;

  void chk_n_alloc () {
    if (size() == capacity()) {
      reallocate();
    }
  }

  std::pair<char*, char*> alloc_n_copy(const char*b, const char*e) {
    auto data = alloc.allocate(e - b);
    return {
      data,
      std::uninitialized_copy(b, e, data),
    };
  }
  void free() {
    if (elements) {
      for (auto p = first_free; p != elements; ) {
        alloc.destroy(--p);
      }
      alloc.deallocate(elements, cap - elements);
    }
  }
  void reallocate() {
    auto newCapacity = size() ? 2 * size() : 1;
    auto newData = alloc.allocate(newCapacity);

    auto dest = newData;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
      alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
  };
  char *elements;
  char *first_free;
  char *cap;
};

#endif
